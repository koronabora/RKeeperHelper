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

	qint64 getBlueCash(QDate date);
	qint64 getBlueCard(QDate date);
	qint64 getWhiteCash(QDate date);
	qint64 getWhiteCard(QDate date);
	qint64 getAllKeysCount(QDate date);
	qint64 getAllVisitorsCount(QDate date);
	qint64 getCashIn(QDate date);
	qint64 getCashSit(QDate date, QVector<quint64> orders);
	qint64 getCashFood(QDate date, QVector<quint64> orders);
	qint64 getCashHotel(QDate date, QVector<quint64> orders);
	qint64 getCashBaths(QDate date, QVector<quint64> orders);
	qint64 getCashHookah(QDate date, QVector<quint64> orders);
	qint64 getCashAdditionalService(QDate date, QVector<quint64> orders);
	qint64 cashGetVIP(QDate date);
	qint64 getCardIn(QDate date);
	qint64 getCardSit(QDate date, QVector<quint64> orders);
	qint64 getCardFood(QDate date, QVector<quint64> orders);
	qint64 getCardHotel(QDate date, QVector<quint64> orders);
	qint64 getCardBaths(QDate date, QVector<quint64> orders);
	qint64 getCardHookah(QDate date, QVector<quint64> orders);
	qint64 getCardAdditionalService(QDate date, QVector<quint64> orders);
	QString fillReq(QString src, QDate date);
	QString fillReqRk(QString src, QDate date);

	QVector<quint64> getAdditionalServices(QDate day);
	QVector<quint64> getSits(QDate day);
	QVector<quint64> getKitchen(QDate day);
	QVector<quint64> getBath(QDate day);
	QVector<quint64> getHookah(QDate day);
	QVector<quint64> getHotel(QDate day);

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
	void mssqlStateChanged(bool state);
	void fbsqllStateChanged(bool state);
	void updateProgressBar();
};