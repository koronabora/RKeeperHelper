// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QDateTime>
#include <QVariant>
#include <QSemaphore>
#include <QObject>
#include <QTimer>
#include <QCoreApplication>
#include <QtSql/QSqlError>
#include "Settings.h"
#include <QThread>
#include <QApplication>

class Worker : public QObject
{
	Q_OBJECT
public:
	Worker();
	~Worker();

private:
	QSqlDatabase _sqlBase;
	QSqlDatabase _rkBase;
	bool parseArray(QString src, QList<qint64>* res);
	QString combineArray(QList<qint64>* src);
	QString _host;
	QString _rkHost;
	QString _name;
	QString _rkName;
	QString _pass;
	QString _rkPass;
	QString _baseName;
	QString _rkBaseName;
	int _port;
	int _rkPort;
	QSqlQuery fq;
	QSqlQuery rq;
	QSqlError ferr;
	QSqlError rerr;

	qint64 dateToInt(QDate day);
	QDateTime intToTime(QString in);

	QVector<AllData> storage;

	qint64 universalSql(QString src, QDate date);
	qint64 universalSqlRk(QString src, QDate date);
	QString fillReq(QString src, QDate date);
	QString fillReqRk(QString src, QDate date);

	QVector<QVector<qint64>> getLostFolios(QDate day); // payed by card
	qint64 cashByFolio(qint64 folio);
	qint64 cardByFolio(qint64 folio);

	bool init();
	bool initRk();

public slots :
	void run();
	void checkConnection(); // переподключаемся к базе
	void checkConnectionRk(); // переподключаемся к базе
	void getInfo(QDate date);

signals:
	void workFinished();
	void haveInfo(AllData s);
	void mssqlStateChanged(quint64 state);
	void fbsqllStateChanged(quint64 state);
	void updateProgressBar();
};