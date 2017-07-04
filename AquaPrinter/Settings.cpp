// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Settings.h"

Settings::Settings()
{
	fsqlHost = "192.168.1.299";
	fsqlName = "UCS";
	fsqlPassword = "ucs";
	fsqlBaseName = "D:\\FITNESS.FDB";
	fsqlPort = 3080;
	fsqlConname = "FireBirdBase";
	fsqlDriver = "QIBASE";
	sqlUpdateTimer = 5000;
	fsqlDTConvFirstDayMean = "2017-05-27";
	fsqlDTConvFirstDayVal = 42882;
	dateFormat = "yyyy-MM-dd";
	fsqlTimeSplitter = '.';
	fsqlRkTimeDc = 12;
	fsqlRkTimeMaxVal = 10000000;
	uiOrigionalText = tr("изначально ");
	progressBarMax = 24;
	pass = 0; // keep 0 to disable password

	printVerticalLineWrap = 1;
	printVerticalLineShift = 3;
	printHorizontalLineShift = 8;
	printFont = "Consolas";
	printFontSize = 12;
	printDTx = 83;
	printDTy = 62;

	addTime = 0.16;
	cardAdditionalServices = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 15 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cardHotel = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 15 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cardFood = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 15 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cardSit = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 15 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cardIn = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 15 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 70)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cashNoPayments = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cashHotel = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cashFood = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cashSit = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cashIn = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 70)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	allVisitorsCount = "SELECT COUNT(DISTINCT(GUEST)) FROM FOLIO_CONTENTS WHERE OPERATION = 70 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	incomeCards = "SELECT COUNT(DISTINCT(GUEST)) FROM FOLIO_CONTENTS WHERE OPERATION = 70 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	whiteCard = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID = 2 AND OPERATION = 15 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	whiteCash = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID = 2 AND OPERATION = 14 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	blueCard = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID <> 2 AND OPERATION = 15 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	blueCash = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID <> 2 AND OPERATION = 14 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	cashAdditionalServices = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND(FOLIO IN(SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	rkAdditionalServices = "";
	rkSittings = "";
	rkKitchen = "";
	rkHotel = "";
	rkInvaders = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CURRENCYTYPE = 'Неплательщики' AND SHIFTDATE = '?';";

	rkHost = "192.168.1.1";
	rkName = "sa";
	rkPassword = "123456789";
	rkBaseName = "DRIVER={SQL Server Native Client 11.0};SERVER=192.168.1.10,1433;DATABASE=RK7;Uid=sa;Pwd=123456789;WSID=.;";
	rkPort = 1433;
	rkConname = "MSSQL";
	rkDriver = "QODBC";
}

Settings* Settings::i() {
	static Settings instance;
	return &instance;
}

Settings::~Settings()
{}

void Settings::init()
{
	QSettings settings(DEF_FILE_NAME, QSettings::IniFormat);
	QFile file(DEF_FILE_NAME);
	if (file.exists())
	{
		// Loading settings from file
		settings.beginGroup("Firebird_Base_Connection");
		fsqlHost = settings.value("fsqlHost", fsqlHost).toString();
		fsqlName = settings.value("fsqlName", fsqlName).toString();
		fsqlPassword = settings.value("fsqlPassword", fsqlPassword).toString();
		fsqlBaseName = settings.value("fsqlBaseName", fsqlBaseName).toString();
		fsqlPort = settings.value("fsqlPort", fsqlPort).toLongLong();
		fsqlConname = settings.value("fsqlConname", fsqlConname).toString();
		fsqlDriver = settings.value("fsqlDriver", fsqlDriver).toString();
		settings.endGroup();

		settings.beginGroup("MsSql_Base_Connection");
		rkHost = settings.value("rkHost", rkHost).toString();
		rkName = settings.value("rkName", rkName).toString();
		rkPassword = settings.value("rkPassword", rkPassword).toString();
		rkBaseName = settings.value("rkBaseName", rkBaseName).toString();
		rkPort = settings.value("rkPort", rkPort).toLongLong();
		rkConname = settings.value("rkConname", rkConname).toString();
		rkDriver = settings.value("rkDriver", rkDriver).toString();
		settings.endGroup();

		settings.beginGroup("Misc");
		sqlUpdateTimer = settings.value("sqlUpdateTimer", sqlUpdateTimer).toLongLong();
		fsqlDTConvFirstDayMean = settings.value("fsqlDTConvFirstDayMean", fsqlDTConvFirstDayMean).toString();
		fsqlDTConvFirstDayVal = settings.value("fsqlDTConvFirstDayVal", fsqlDTConvFirstDayVal).toLongLong();
		dateFormat = settings.value("dateFormat", dateFormat).toString();
		fsqlTimeSplitter = settings.value("fsqlTimeSplitter", fsqlTimeSplitter).toChar();
		fsqlRkTimeDc = settings.value("fsqlRkTimeDc", fsqlRkTimeDc).toLongLong();
		fsqlRkTimeMaxVal = settings.value("fsqlRkTimeMaxVal", fsqlRkTimeMaxVal).toLongLong();
		uiOrigionalText = settings.value("uiOrigionalText", uiOrigionalText).toString();
		progressBarMax = settings.value("progressBarMax", progressBarMax).toLongLong();
		pass = settings.value("pass", pass).toLongLong();
		settings.endGroup();

		settings.beginGroup("Printing");
		//printCaptionShift = settings.value("printCaptionShift", printCaptionShift).toLongLong();
		printVerticalLineWrap = settings.value("printVerticalLineWrap", printVerticalLineWrap).toLongLong();
		printVerticalLineShift = settings.value("printVerticalLineShift", printVerticalLineShift).toLongLong();
		printHorizontalLineShift = settings.value("printHorizontalLineShift", printHorizontalLineShift).toLongLong();
		printFont = settings.value("printFont", printFont).toString();
		printFontSize = settings.value("printFontSize", printFontSize).toLongLong();
		printDTx = settings.value("printDTx", printDTx).toLongLong();
		printDTy = settings.value("printDTy", printDTy).toLongLong();
		settings.endGroup();

		settings.beginGroup("SQL");
		addTime = settings.value("addTime", addTime).toReal();
		cardAdditionalServices = settings.value("cardAdditionalServices", cardAdditionalServices).toString();
		cardHotel = settings.value("cardHotel", cardHotel).toString();
		cardFood = settings.value("cardFood", cardFood).toString();
		cardSit = settings.value("cardSit", cardSit).toString();
		cardIn = settings.value("cardIn", cardIn).toString();
		cashNoPayments = settings.value("cashNoPayments", cashNoPayments).toString();
		cashHotel = settings.value("cashHotel", cashHotel).toString();
		cashFood = settings.value("cashFood", cashFood).toString();
		cashSit = settings.value("cashSit", cashSit).toString();
		cashIn = settings.value("cashIn", cashIn).toString();
		allVisitorsCount = settings.value("allVisitorsCount", allVisitorsCount).toString();
		incomeCards = settings.value("incomeCards", incomeCards).toString();
		whiteCard = settings.value("whiteCard", whiteCard).toString();
		whiteCash = settings.value("whiteCash", whiteCash).toString();
		blueCard = settings.value("blueCard", blueCard).toString();
		blueCash = settings.value("blueCash", blueCash).toString();
		cashAdditionalServices = settings.value("cashAdditionalServices", cashAdditionalServices).toString();
		rkAdditionalServices = settings.value("rkAdditionalServices", rkAdditionalServices).toString();
		rkSittings = settings.value("rkSittings", rkSittings).toString();
		rkKitchen = settings.value("rkKitchen", rkKitchen).toString();
		rkHotel = settings.value("rkHotel", rkHotel).toString();
		rkInvaders = settings.value("rkInvaders", rkInvaders).toString();
	}
	else
	{
		// Saving default settings into file
		settings.beginGroup("Firebird_Base_Connection");
		settings.setValue("fsqlHost", fsqlHost);
		settings.setValue("fsqlName", fsqlName);
		settings.setValue("fsqlPassword", fsqlPassword);
		settings.setValue("fsqlBaseName", fsqlBaseName);
		settings.setValue("fsqlPort", fsqlPort);
		settings.setValue("fsqlConname", fsqlConname);
		settings.setValue("fsqlDriver", fsqlDriver);
		settings.endGroup();

		settings.beginGroup("MsSql_Base_Connection");
		settings.setValue("rkHost", rkHost);
		settings.setValue("rkName", rkName);
		settings.setValue("rkPassword", rkPassword);
		settings.setValue("rkBaseName", rkBaseName);
		settings.setValue("rkPort", rkPort);
		settings.setValue("rkConname", rkConname);
		settings.setValue("rkDriver", rkDriver);
		settings.endGroup();

		settings.beginGroup("Misc");
		settings.setValue("sqlUpdateTimer", sqlUpdateTimer);
		settings.setValue("fsqlDTConvFirstDayMean", fsqlDTConvFirstDayMean);
		settings.setValue("fsqlDTConvFirstDayVal", fsqlDTConvFirstDayVal);
		settings.setValue("dateFormat", dateFormat);
		settings.setValue("fsqlTimeSplitter", fsqlTimeSplitter);
		settings.setValue("fsqlRkTimeDc", fsqlRkTimeDc);
		settings.setValue("fsqlRkTimeMaxVal", fsqlRkTimeMaxVal);
		settings.setValue("uiOrigionalText", uiOrigionalText);
		settings.setValue("progressBarMax", progressBarMax);
		settings.setValue("pass", pass);
		settings.endGroup();

		settings.beginGroup("Printing");
		//settings.setValue("printCaptionShift", printCaptionShift);
		settings.setValue("printVerticalLineWrap", printVerticalLineWrap);
		settings.setValue("printVerticalLineShift", printVerticalLineShift);
		settings.setValue("printHorizontalLineShift", printHorizontalLineShift);
		settings.setValue("printFont", printFont);
		settings.setValue("printFontSize", printFontSize);
		settings.setValue("printDTx", printDTx);
		settings.setValue("printDTy", printDTy);
		settings.endGroup();

		settings.beginGroup("SQL");
		settings.setValue("addTime", addTime);
		settings.setValue("cardAdditionalServices", cardAdditionalServices);
		settings.setValue("cardHotel", cardHotel);
		settings.setValue("cardFood", cardFood);
		settings.setValue("cardSit", cardSit);
		settings.setValue("cardIn", cardIn);
		settings.setValue("cashNoPayments", cashNoPayments);
		settings.setValue("cashHotel", cashHotel);
		settings.setValue("cashFood", cashFood);
		settings.setValue("cashSit", cashSit);
		settings.setValue("cashIn", cashIn);
		settings.setValue("allVisitorsCount", allVisitorsCount);
		settings.setValue("incomeCards", incomeCards);
		settings.setValue("whiteCard", whiteCard);
		settings.setValue("whiteCash", whiteCash);
		settings.setValue("blueCard", blueCard);
		settings.setValue("blueCash", blueCash);
		settings.setValue("cashAdditionalServices", cashAdditionalServices);
		settings.setValue("rkAdditionalServices", rkAdditionalServices);
		settings.setValue("rkSittings", rkSittings);
		settings.setValue("rkKitchen", rkKitchen);
		settings.setValue("rkHotel", rkHotel);
		settings.setValue("rkInvaders", rkInvaders);
		settings.endGroup();

		settings.sync();
	}
}