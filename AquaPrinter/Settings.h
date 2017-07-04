// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <QSettings>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDate>
#include "AllData.h"

#define DEF_FILE_NAME "Settings.ini"

class Settings : public QObject
{
	Q_OBJECT
public:
	QString fsqlHost;
	QString fsqlName;
	QString fsqlPassword;
	QString fsqlBaseName;
	qint64 fsqlPort;
	QString fsqlConname;
	QString fsqlDriver;
	qint64 sqlUpdateTimer;
	QString fsqlDTConvFirstDayMean;
	qint64 fsqlDTConvFirstDayVal;
	QString dateFormat;
	QChar fsqlTimeSplitter;
	qint64 fsqlRkTimeMaxVal;
	qint64 fsqlRkTimeDc;
	QString uiOrigionalText;
	qint64	progressBarMax;
	qint64 pass;

	QString rkHost;
	QString rkName;
	QString rkPassword;
	QString rkBaseName;
	qint64 rkPort;
	QString rkConname;
	QString rkDriver;

	qint64 printVerticalLineWrap;
	qint64 printVerticalLineShift;
	qint64 printHorizontalLineShift;
	QString printFont;
	qint64 printFontSize;
	qint64 printDTx;
	qint64 printDTy;

	qreal addTime;
	QString cardAdditionalServices;
	QString cardHotel;
	QString cardFood;
	QString cardSit;
	QString cardIn;
	//QString cashNoPayments;
	QString cashHotel;
	QString cashFood;
	QString cashSit;
	QString cashIn;
	QString allVisitorsCount;
	QString incomeCards;
	QString whiteCard;
	QString whiteCash;
	QString blueCard;
	QString blueCash;
	QString cashAdditionalServices;
	QString rkAdditionalServices; // additional services
	QString rkSittings; // sittings
	QString rkKitchen; // kitchen services
	QString rkHotel; // hotel
	QString rkInvaders; // vip
	
	static Settings* i();

	void init();
private:
	Settings();
	~Settings();
};