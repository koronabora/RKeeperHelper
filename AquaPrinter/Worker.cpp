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
	_sqlBase.removeDatabase(Settings::i()->fsqlConname);
	_rkBase.close();
	_rkBase.removeDatabase(Settings::i()->rkConname);
	emit workFinished();
}

void Worker::checkConnection()
{
	while (!_sqlBase.isOpen())
	{
		if (_sqlBase.open())
		{
			emit fbsqllStateChanged(true);
			qInfo() << ("Sucsesfully connected to database: " + Settings::i()->fsqlBaseName);
			break;
		}
		QThread::msleep(Settings::i()->sqlUpdateTimer);
		QApplication::processEvents();
	}
}

void Worker::checkConnectionRk()
{
	while (!_rkBase.isOpen())
	{
		if (_rkBase.open())
		{
			emit mssqlStateChanged(true);
			qInfo() << ("Sucsesfully connected to database: " + Settings::i()->rkBaseName);
			break;
		}
		QThread::msleep(Settings::i()->sqlUpdateTimer);
		QApplication::processEvents();
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
	return _rkBase.open();
}

void Worker::run()
{
	if (!init())
	{
		qInfo() << (QCoreApplication::libraryPaths().join('_'));
		qInfo() << ("Error while connecting to database:");
		qInfo() << (_sqlBase.lastError().text());
		emit fbsqllStateChanged(false);
	}
	else
	{
		emit fbsqllStateChanged(true);
		qInfo() << ("Sucsesfully connected to database: " + Settings::i()->fsqlBaseName);
	}

	if (!initRk())
	{
		qInfo() << (QCoreApplication::libraryPaths().join('_'));
		qInfo() << ("Error while connecting to database:");
		QString t = _rkBase.lastError().text();
		qInfo() << (t);
		emit mssqlStateChanged(false);
	}
	else
	{
		emit mssqlStateChanged(true);
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
		AllData d;
		QVector<quint64> sit = getSits(date);
		emit updateProgressBar();
		QVector<quint64> food = getKitchen(date);
		emit updateProgressBar();
		QVector<quint64> hotel = getHotel(date);
		emit updateProgressBar();
		QVector<quint64> baths = getBath(date);
		emit updateProgressBar();
		QVector<quint64> hookah = getHookah(date);
		emit updateProgressBar();
		QVector<quint64> additionalServices = getAdditionalServices(date);
		emit updateProgressBar();
		d.date = date;
		d.blueCash =  getBlueCash(date);
		d.blueCashOrig = d.blueCash;
		emit updateProgressBar();
		d.blueCard = getBlueCard(date);
		emit updateProgressBar();
		d.blueCardOrig = d.blueCard;
		d.blueAll = d.blueCard+d.blueCash;
		d.blueAllOrig = d.blueAll;
		emit updateProgressBar();
		d.whiteCash = getWhiteCash(date);
		emit updateProgressBar();
		d.whiteCashOrig = d.whiteCash;
		d.whiteCard = getWhiteCard(date);
		emit updateProgressBar();
		d.whiteCardOrig = d.whiteCard;
		d.whiteAll = d.whiteCard+d.whiteCash;
		d.whiteAllOrig = d.whiteAll;
		d.allKeysCount = getAllKeysCount(date);
		emit updateProgressBar();
		d.allVisitorsCount = getAllVisitorsCount(date);
		emit updateProgressBar();
		d.cashIn = getCashIn(date);
		emit updateProgressBar();
		d.cashSit = getCashSit(date, sit);
		emit updateProgressBar();
		d.cashFood = getCashFood(date, sit);
		emit updateProgressBar();
		d.cashHotel = getCashHotel(date, hotel);
		emit updateProgressBar();
		d.cashAdditionalServices = getCashAdditionalService(date, additionalServices);
		emit updateProgressBar();
		d.cashInvaders = cashGetVIP(date);
		emit updateProgressBar();
		d.cardIn = getCardIn(date);
		emit updateProgressBar();
		d.cardSit = getCardSit(date, sit);
		emit updateProgressBar();
		d.cardFood = getCardFood(date, food);
		emit updateProgressBar();
		d.cardHotel = getCardHotel(date, hotel);
		emit updateProgressBar();
		d.cardAdditionalServices = getCardAdditionalService(date, additionalServices);
		emit updateProgressBar();
		d.finalCash = d.whiteCash + d.blueCash;
		//storage.append(d);
		fq.clear();
		emit updateProgressBar();
		emit haveInfo(d);
	}
}

/*qint64 Worker::getBlueAll(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->blueAll);
	qq.append(QString::number(day));
	qq.append(".%';");
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
}*/

qint64 Worker::getBlueCash(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->blueCash, date);
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

qint64 Worker::getBlueCard(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->blueCard, date);
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

/*qint64 Worker::getWhiteAll(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->whiteAll, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}*/

qint64 Worker::getWhiteCash(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->whiteCash, date);
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

qint64 Worker::getWhiteCard(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->whiteCard, date);
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

qint64 Worker::getAllKeysCount(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->incomeCards, date);
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

qint64 Worker::getAllVisitorsCount(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->allVisitorsCount, date);
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

qint64 Worker::getCashIn(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cashIn, date);
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

qint64 Worker::getCashSit(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cashSit, date);
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

qint64 Worker::getCashFood(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cashFood, date);
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

qint64 Worker::getCashHotel(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cashHotel, date);
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

qint64 Worker::getCashAdditionalService(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cashAdditionalServices, date);
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

qint64 Worker::cashGetVIP(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReqRk(Settings::i()->rkInvaders, date);
	rq = _rkBase.exec(qq);
	rerr = rq.lastError();
	if (rerr.text().size() > 1)
		qWarning() << ("SQL Error: " + rerr.text());
	if (rq.next())
	{
		QString sss = rq.record().value(0).toString();
		res = sss.toLongLong();
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

qint64 Worker::getCardIn(QDate date)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cardIn, date);
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

qint64 Worker::getCardSit(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cardSit, date);
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

qint64 Worker::getCardFood(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cardFood, date);
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

qint64 Worker::getCardHotel(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	
	QString qq = fillReq(Settings::i()->cardHotel, date);
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

qint64 Worker::getCardAdditionalService(QDate date, QVector<quint64> orders)
{
	qint64 res = 0;
	QString qq = fillReq(Settings::i()->cardAdditionalServices, date);
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

QString Worker::fillReq(QString src, QDate date)
{
	// '?' - curday
	// '~' - curday+1
	QString res = "";
	qint64 day = dateToInt(date);
	if (src.size()>0)
		for (quint64 i = 0; i < src.size(); i++)
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
	QString day = date.toString("yyyyMMdd");
	QString dayNext = date.addDays(1).toString("yyyyMMdd");
	if (src.size()>0)
		for (quint64 i = 0; i < src.size(); i++)
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

QVector<quint64> Worker::getAdditionalServices(QDate date)
{
	QVector<quint64> res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
		res.append(sss.toLongLong());
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

QVector<quint64> Worker::getSits(QDate date)
{
	QVector<quint64> res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
		res.append(sss.toLongLong());
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

QVector<quint64> Worker::getKitchen(QDate date)
{
	QVector<quint64> res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
		res.append(sss.toLongLong());
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

QVector<quint64> Worker::getHotel(QDate date)
{
	QVector<quint64> res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
	fq = _sqlBase.exec(qq);
	ferr = fq.lastError();
	if (ferr.text().size() > 1)
		qWarning() << ("SQL Error: " + ferr.text());
	if (fq.next())
	{
		QString sss = fq.record().value(0).toString();
		res.append(sss.toLongLong());
	}
	else
		qDebug() << ("No results from firebird database while selecting !");
	return res;
}

qint64 Worker::getCardBaths(QDate date, QVector<quint64> orders)
{
	qint64 res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
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

qint64 Worker::getCardHookah(QDate date, QVector<quint64> orders)
{
	qint64 res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
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

qint64 Worker::getCashBaths(QDate date, QVector<quint64> orders)
{
	qint64 res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
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

qint64 Worker::getCashHookah(QDate date, QVector<quint64> orders)
{
	qint64 res;
	QString qq = fillReq(Settings::i()->cardHotel, date);
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