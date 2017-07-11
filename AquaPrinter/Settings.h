// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <QSettings>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDate>
#include <QStringList>
#include "AllData.h"

#define DEF_FILE_NAME "Settings.ini"

enum SQL_STATES
{
	NOT_CONNECTED,
	CONNECTING,
	CONNECTED
};

static const QStringList SQL_STATE_NAMES = 
{QObject::tr("Отключен"), QObject::tr("Подключение"), QObject::tr("Подключен")};

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
	qint64 sqlRetries;

	QString lostFolioUiName;
	QString lostFolioUiCloseButton;
	QString lostFolioUiMainTable;
	QString lostFolioUiMainTableC1Name;
	QString lostFolioUiMainTableC2Name;
	QString lostFolioUiMainTableC3Name;

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
	QString addTimeRk;
	QString timeFormatRk;
	QString dateFormatRk;
	QString allIn;
	QString rkAdditionalServices;
	QString rkSittings;
	QString rkKitchen;
	QString rkBar;
	QString rkHotel;
	QString rkBaths;
	QString rkHookahs;
	QString rkInvaders;
	QString rkDiscounts;
	
	QString allVisitorsCount;
	QString incomeCards;
	
	QString whiteCard;
	QString whiteCash;
	QString whiteDisc;
	QString blueCard;
	QString blueCash;
	QString blueDisc;
	
	QString allFolios;
	QString cardByFolio;
	QString cashByFolio;
	QString lostFolios;

	static Settings* i();
	static QString fNum(qint64 num);

	void init();
private:
	Settings();
	~Settings();
};