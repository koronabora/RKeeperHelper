// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Worker.h"

Worker::Worker()
{
	_host = Settings::i()->fsqlHost;
	_name = Settings::i()->fsqlName;
	_pass = Settings::i()->fsqlPassword;
	_baseName = Settings::i()->fsqlBaseName;
	_port = Settings::i()->fsqlPort;

	_rkHost = Settings::i()->rkHost;
	_rkName = Settings::i()->rkName;
	_rkPass = Settings::i()->rkPassword;
	_rkBaseName = Settings::i()->rkBaseName;
	_rkPort = Settings::i()->rkPort;
}

Worker::~Worker()
{
	//_sqlBase.commit();
	_sqlBase.close();
	//_sqlBase.removeDatabase(Settings::i()->fsqlConname);
	_rkBase.close();
	//_rkBase.removeDatabase(Settings::i()->rkConname);
	emit workFinished();
}

void Worker::checkConnection()
{
	qint64 count = 0;
	if (!_sqlBase.isOpen() && count<Settings::i()->sqlRetries)
	{
		count++;
		emit fbsqllStateChanged(SQL_STATES::CONNECTING);
		if (_sqlBase.open())
		{
			emit fbsqllStateChanged(SQL_STATES::CONNECTED);
			qInfo() << ("Sucsesfully connected to database: " + Settings::i()->fsqlBaseName);
			//break;
		}
		else
			emit fbsqllStateChanged(SQL_STATES::NOT_CONNECTED);
		//QThread::msleep(Settings::i()->sqlUpdateTimer);
		//QApplication::processEvents();
	}
}

void Worker::checkConnectionRk()
{
	qint64 count = 0;
	if (!_rkBase.isOpen() && count<Settings::i()->sqlRetries)
	{
		count++;
		emit mssqlStateChanged(SQL_STATES::CONNECTING);
		if (_rkBase.open())
		{
			emit mssqlStateChanged(SQL_STATES::CONNECTED);
			qInfo() << ("Sucsesfully connected to database: " + Settings::i()->rkBaseName);
		}
		else
			emit mssqlStateChanged(SQL_STATES::NOT_CONNECTED);
		//QThread::msleep(Settings::i()->sqlUpdateTimer);
		//QApplication::processEvents();
	}
}

bool Worker::init()
{
	_sqlBase = QSqlDatabase::addDatabase(Settings::i()->fsqlDriver, Settings::i()->fsqlConname);
	_sqlBase.setHostName(_host);
	_sqlBase.setPort(_port);
	_sqlBase.setDatabaseName(_baseName);
	_sqlBase.setUserName(_name);
	_sqlBase.setPassword(_pass);
	emit fbsqllStateChanged(SQL_STATES::CONNECTING);
	return _sqlBase.open();
}

bool Worker::initRk()
{
	_rkBase = QSqlDatabase::addDatabase(Settings::i()->rkDriver, Settings::i()->rkConname);
	_rkBase.setHostName(_rkHost);
	_rkBase.setPort(_rkPort);
	_rkBase.setDatabaseName(_rkBaseName);
	_rkBase.setUserName(_rkName);
	_rkBase.setPassword(_rkPass);
	emit mssqlStateChanged(SQL_STATES::CONNECTING);
	return _rkBase.open();
}

void Worker::run()
{
	if (!init())
	{
		qInfo() << (QCoreApplication::libraryPaths().join('_'));
		qInfo() << ("Error while connecting to database:");
		qInfo() << (_sqlBase.lastError().text());
		emit fbsqllStateChanged(SQL_STATES::NOT_CONNECTED);
	}
	else
	{
		emit fbsqllStateChanged(CONNECTED);
		qInfo() << ("Sucsesfully connected to database: " + Settings::i()->fsqlBaseName);
	}

	if (!initRk())
	{
		qInfo() << (QCoreApplication::libraryPaths().join('_'));
		qInfo() << ("Error while connecting to database:");
		QString t = _rkBase.lastError().text();
		qInfo() << (t);
		emit mssqlStateChanged(NOT_CONNECTED);
	}
	else
	{
		emit mssqlStateChanged(CONNECTED);
		qInfo() << ("Sucsesfully connected to database: " + Settings::i()->rkBaseName);
	}
}

qint64 Worker::dateToInt(QDate day)
{
	qint64 res = day.toJulianDay();
	res = res - QDate::fromString(Settings::i()->fsqlDTConvFirstDayMean, Settings::i()->dateFormat).toJulianDay() + Settings::i()->fsqlDTConvFirstDayVal;
	return res;
}

QDateTime Worker::intToTime(QString in)
{
	QDateTime res = QDateTime::currentDateTime();
	QStringList ss = in.split(Settings::i()->fsqlTimeSplitter);
	if (ss.size() == 2)
	{
		bool ok;
		qint64 day = ss.at(0).toULongLong(&ok);
		if (!ok)
		{
			qInfo() << ("Could not convert day value: " + ss.at(0));
		}
		else
			res.setDate(QDate::fromString(Settings::i()->fsqlDTConvFirstDayMean, Settings::i()->dateFormat).addDays(day - Settings::i()->fsqlDTConvFirstDayVal));

		QString ts = ss.at(1);
		while (ts.size() < Settings::i()->fsqlRkTimeDc)
			ts.append("0");
		qint64 time = ts.toULongLong(&ok);
		if (!ok)
		{
			qInfo() << ("Could not convert day value: " + ts);
		}
		else
		{
			double div = 6.0 * 6.0 * 24.0 / (Settings::i()->fsqlRkTimeMaxVal);
			res.setTime(QTime::fromMSecsSinceStartOfDay(round((time*1.0)*div))); // time * msecsInDay / partsInDay
			qDebug() << "TIME CONVERSION: " << time << " -> " << res.time().toString();
		}
	}
	return res;
}

void Worker::getInfo(QDate date)
{
	bool found = false;
	if (storage.size() > 0)
	{
		for (qint64 i=0; i<storage.size(); i++)
			if (storage.at(i).date == date)
			{
				found = true;
				emit haveInfo(storage.at(i));
			}
	}

	if (!found)
	{
		emit updateProgressBar();
		checkConnectionRk();
		emit updateProgressBar();
		checkConnection();
		emit updateProgressBar();
		AllData d;
		//QVector<QVector<qint64>> orders = getPayments(date);
		d.date = date;

		d.blueCash = universalSql(Settings::i()->blueCash, date);
		emit updateProgressBar();

		d.blueCashOrig = d.blueCash;
		emit updateProgressBar();

		d.blueCard = universalSql(Settings::i()->blueCard, date);
		emit updateProgressBar();

		d.blueCardOrig = d.blueCard;
		emit updateProgressBar();

		d.blueAll = d.blueCash+d.blueCard;
		emit updateProgressBar();

		d.blueAllOrig = d.blueAll;
		emit updateProgressBar();

		d.blueDisc = universalSql(Settings::i()->blueDisc, date);
		emit updateProgressBar();

		d.whiteCash = universalSql(Settings::i()->whiteCash, date);
		emit updateProgressBar();

		d.whiteCashOrig = d.whiteCash;
		emit updateProgressBar();

		d.whiteCard = universalSql(Settings::i()->whiteCard, date);
		emit updateProgressBar();

		d.whiteCardOrig = d.whiteCard;
		emit updateProgressBar();

		d.whiteAll = d.whiteCard+d.whiteCash;
		emit updateProgressBar();

		d.whiteAllOrig = d.whiteAll;
		emit updateProgressBar();

		d.whiteDisc = universalSql(Settings::i()->whiteDisc, date);
		emit updateProgressBar();

		d.allKeysCount = universalSql(Settings::i()->incomeCards, date);
		emit updateProgressBar();

		d.allVisitorsCount = universalSql(Settings::i()->allVisitorsCount, date);
		emit updateProgressBar();

		d.allIn = universalSql(Settings::i()->allIn, date);
		emit updateProgressBar();

		d.allSit = universalSqlRk(Settings::i()->rkSittings, date);
		emit updateProgressBar();

		d.allFood = universalSqlRk(Settings::i()->rkKitchen, date);
		emit updateProgressBar();

		d.allBar = universalSqlRk(Settings::i()->rkBar, date);
		emit updateProgressBar();

		d.allHotel = universalSqlRk(Settings::i()->rkHotel, date);
		emit updateProgressBar();

		d.allInvaders = universalSqlRk(Settings::i()->rkInvaders, date);
		emit updateProgressBar();

		d.allDiscounts = universalSqlRk(Settings::i()->rkDiscounts, date);
		emit updateProgressBar();
		
		d.allHookah = universalSqlRk(Settings::i()->rkHookahs, date);
		emit updateProgressBar();

		d.allBath = universalSqlRk(Settings::i()->rkBaths, date);
		emit updateProgressBar();
		
		//d.allAdditionalServices = sumAll - other;
		d.allAdditionalServices = universalSqlRk(Settings::i()->rkAdditionalServices, date);
		emit updateProgressBar();

		qint64 sumAll = d.blueAll + d.whiteAll;
		qint64 other = d.allIn + d.allSit + d.allFood + d.allBar + d.allHotel + d.allHookah + d.allBath+d.allAdditionalServices;
		d.diffFromPrevDay = other - sumAll;

		d.cashToBank = 0;
		emit updateProgressBar();

		d.cashToBankPrev = 0;
		emit updateProgressBar();

		d.finalBank = d.cashToBankPrev+d.cashToBank+d.blueCard+d.whiteCard;
		emit updateProgressBar();
		
		d.finalCash = d.whiteAll + d.blueAll-d.cashToBank;
		d.writeOffs = 0;
		d.lostFolios = getLostFolios(date);

		emit updateProgressBar();
		fq.clear();
		emit haveInfo(d);
	}
}

qint64 Worker::universalSql(QString src, QDate date)
{
	//checkConnection();
	qint64 res = 0;
	QString qq = fillReq(src, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		//QString sss = fq.record().value(0).toString();
		res = fq.record().value(0).toLongLong();
	}
	else
		qDebug() << "No results from firebird database for request: "+src;
	return res;
}

qint64 Worker::universalSqlRk(QString src, QDate date)
{
	//checkConnectionRk();
	qint64 res = 0;
	QString qq = fillReqRk(src, date);
	rq = _rkBase.exec(qq);
	rerr = rq.lastError();
	if (rerr.text().size() > 1)
		qWarning() << ("SQL Error: " + rerr.text());
	if (rq.next())
	{
		//QString sss = rq.record().value(0).toString();
		res = rq.record().value(0).toLongLong();
	}
	else
		qDebug() << "No results from mssql database for request: " + src;
	return res;
}

QString Worker::fillReq(QString src, QDate date)
{
	// '?' - curday
	// '~' - curday+1
	QString res = "";
	qint64 day = dateToInt(date);
	if (src.size()>0)
		for (qint64 i = 0; i < src.size(); i++)
		{
			if (src.at(i) == '?')
				res.append(QString::number(day*1.0 + Settings::i()->addTime));
			else if (src.at(i) == '~')
				res.append(QString::number((day+1)*1.0+Settings::i()->addTime));
			else
				res.append(src.at(i));
		}
	return res;
}

QString Worker::fillReqRk(QString src, QDate date)
{
	// '?' - curday
	// '~' - curday+1
	QString res = "";
	QDateTime d1;
	d1.setDate(date);
	d1.setTime(QTime::fromString(Settings::i()->addTimeRk, Settings::i()->timeFormatRk));
	QDateTime d2;
	d2.setDate(date.addDays(1));
	d2.setTime(QTime::fromString(Settings::i()->addTimeRk, Settings::i()->timeFormatRk));
	QString day = d1.toString(Settings::i()->dateFormatRk);
	QString dayNext = d2.toString(Settings::i()->dateFormatRk);
	if (src.size()>0)
		for (qint64 i = 0; i < src.size(); i++)
		{
			if (src.at(i) == '?')
				res.append(day);
			else if (src.at(i) == '~')
				res.append(dayNext);
			else
				res.append(src.at(i));
		}
	return res;
}

qint64 Worker::cashByFolio(qint64 folio)
{
	qint64 res = 0;
	QString qq = Settings::i()->cashByFolio;
	qq.append(QString::number(folio));
	qq.append(";");
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
		res = sss.toLongLong();
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

qint64 Worker::cardByFolio(qint64 folio)
{
	qint64 res = 0;
	QString qq = Settings::i()->cardByFolio;
	qq.append(QString::number(folio));
	qq.append(";");
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
		res = sss.toLongLong();
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

QVector<QVector<qint64>> Worker::getLostFolios(QDate date)
{
	QVector<QVector<qint64>> res; // folio, cost, rk_id
	
	QString qq = fillReq(Settings::i()->lostFolios, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	while (fq.next())
	{
		qint64 folio = fq.record().value(0).toLongLong();
		qint64 cost = fq.record().value(1).toLongLong();
		QString info = fq.record().value(2).toString();
		QStringList ss = info.split(':');
		if (ss.size() > 1)
		{
			qint64 order = ss.at(1).toLongLong();
			res.append(QVector<qint64>({folio, cost, order}));
		}
		else
			res.append(QVector<qint64>({ folio, cost, 0 }));
	}
	return res;
}