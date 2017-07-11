// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Settings.h"

Settings::Settings()
{
	fsqlHost = "192.168.1.199";
	fsqlName = "UCS";
	fsqlPassword = "ucs";
	fsqlBaseName = "D:\\Fitness\\Empty\\FITNESS.FDB";
	fsqlPort = 3080;
	fsqlConname = "FireBirdBase";
	fsqlDriver = "QIBASE";
	sqlUpdateTimer = 1000;
	fsqlDTConvFirstDayMean = "2017-05-27";
	fsqlDTConvFirstDayVal = 42882;
	dateFormat = "yyyy-MM-dd";
	fsqlTimeSplitter = '.';
	fsqlRkTimeDc = 12;
	fsqlRkTimeMaxVal = 10000000;
	uiOrigionalText = tr("изначально ");
	progressBarMax = 33;
	pass = 3870440254;
	lostFolioUiName = "LostFoliosInfo.ui";
	lostFolioUiCloseButton = "closeButton";
	lostFolioUiMainTable = "mainTable";
	lostFolioUiMainTableC1Name = "Фолио";
	lostFolioUiMainTableC2Name = "Сумма";
	lostFolioUiMainTableC3Name = "Чек RKeeper";
	//
	printVerticalLineWrap = 1;
	printVerticalLineShift = 3;
	printHorizontalLineShift = 8;
	printFont = "Consolas";
	printFontSize = 12;
	printDTx = 83;
	printDTy = 62;

	addTime = 0.16;
	addTimeRk = "00:00:00";
	timeFormatRk = "hh:mm:ss";
	dateFormatRk = "yyyy-MM-ddTHH:mm:ss.zzz";

	// выборка 
	//rkAdditionalServices = "SELECT * FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE NOT ((CATEGPATH LIKE '%Бар%') OR (CATEGPATH LIKE '%Размещение%') OR (CATEGPATH LIKE '%Кухня%') OR (CATEGPATH LIKE '%СПА%') OR (CATEGPATH LIKE '%БАНЯ%') OR (CATEGPATH LIKE '%Отель%') OR (CATEGPATH LIKE '%Кальян%')) AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkAdditionalServices = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE NOT ((CATEGPATH LIKE '%Бар%') OR (CATEGPATH LIKE '%Размещение%') OR (CATEGPATH LIKE '%Кухня%') OR (CATEGPATH LIKE '%СПА%') OR (CATEGPATH LIKE '%БАНЯ%') OR (CATEGPATH LIKE '%Отель%') OR (CATEGPATH LIKE '%Кальян%')) AND SHIFTDATE='?';";
	//rkSittings = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Размещение%' AND  CURRENCYTYPE<>'Неплательщики' AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkSittings = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Размещение%' AND  CURRENCYTYPE<>'Неплательщики' AND SHIFTDATE='?';";
	//rkKitchen = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Кухня%' AND  CURRENCYTYPE<>'Неплательщики' AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkKitchen = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Кухня%' AND  CURRENCYTYPE<>'Неплательщики' AND SHIFTDATE='?';";
	//rkBar = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Бар%' AND  CURRENCYTYPE<>'Неплательщики' AND CLOSEDATETIME___37 >= '?' AND CLOSEDATETIME___37<'~';";
	rkBar = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Бар%' AND  CURRENCYTYPE<>'Неплательщики' AND SHIFTDATE='?';";
	//rkHotel = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE (CATEGPATH LIKE '%СПА%' OR CATEGPATH LIKE '%БАНЯ%') AND  CURRENCYTYPE<>'Неплательщики' AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkHotel = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE (CATEGPATH LIKE '%СПА%' OR CATEGPATH LIKE '%БАНЯ%') AND  CURRENCYTYPE<>'Неплательщики' AND SHIFTDATE='?';";
	//rkBaths = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Отель%' AND  CURRENCYTYPE <> 'Неплательщики' AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkBaths = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Отель%' AND  CURRENCYTYPE <> 'Неплательщики' AND SHIFTDATE='?';";
	//rkHookahs = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Кальян%' AND  CURRENCYTYPE <> 'Неплательщики' AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkHookahs = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CATEGPATH LIKE '%Кальян%' AND  CURRENCYTYPE <> 'Неплательщики' AND SHIFTDATE='?';";
	//rkDiscounts = "SELECT SUM(PRLISTSUM - PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkDiscounts = "SELECT SUM(PRLISTSUM - PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE SHIFTDATE='?';";
	// входные
	allIn = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 70 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	//allIn = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND (FOLIO IN (SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 70)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	// посетители
	allVisitorsCount = "SELECT COUNT(DISTINCT(GUEST)) FROM FOLIO_CONTENTS WHERE OPERATION = 70 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	incomeCards = "SELECT COUNT(DISTINCT(GUEST)) FROM FOLIO_CONTENTS WHERE OPERATION = 70 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	//
	whiteCard = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID = 2 AND OPERATION = 15 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	whiteCash = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID = 2 AND OPERATION = 14 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	whiteDisc = "SELECT SUM(-COST) FROM FOLIO_CONTENTS WHERE COST<0 AND USERID=2 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	//	
	blueCard = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID <> 2 AND OPERATION = 15 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	blueCash = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE USERID <> 2 AND OPERATION = 14 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	blueDisc = "SELECT SUM(-COST) FROM FOLIO_CONTENTS WHERE COST<0 AND USERID<>2 AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	//
	//rkAdditionalServices = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND(FOLIO IN(SELECT FOLIO FROM FOLIO_CONTENTS WHERE OPERATION = 71)) AND CREATIONDATE >= '?' AND CREATIONDATE < '~';";
	//rkInvaders = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CURRENCYTYPE = 'Неплательщики' AND CLOSEDATETIME___37>='?' AND CLOSEDATETIME___37<'~';";
	rkInvaders = "SELECT SUM(PAYSUM) FROM[RK7].[dbo].[VRK7CUBEVIEW3001] WHERE CURRENCYTYPE = 'Неплательщики' AND SHIFTDATE='?';";
	//
	allFolios = "SELECT FOLIO, COST, INFO FROM FOLIO_CONTENTS WHERE OPERATION=71 AND CREATIONDATE >='?' AND CREATIONDATE < '~';";
	cardByFolio = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 15 AND FOLIO =";
	cashByFolio = "SELECT SUM(COST) FROM FOLIO_CONTENTS WHERE OPERATION = 14 AND FOLIO =";
	lostFolios = "SELECT FOLIO, COST, INFO FROM FOLIO_CONTENTS WHERE (FOLIO IN (SELECT FOLIO FROM GUEST_IDENTIFIERS WHERE REGDATE>0 AND UNREGDATE=0)) AND (OPERATION=70 OR OPERATION=71) AND CREATIONDATE >='?' AND CREATIONDATE < '~';";
	//
	rkHost = "192.168.1.10";
	rkName = "sa";
	rkPassword = "123456789";
	rkBaseName = "DRIVER={SQL Server Native Client 11.0};SERVER=192.168.1.10,1433;DATABASE=RK7;Uid=sa;Pwd=123456789;WSID=.;";
	rkPort = 1433;
	rkConname = "MSSQL";
	rkDriver = "QODBC";

	sqlRetries = 3;
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
		sqlRetries = settings.value("sqlRetries", sqlRetries).toLongLong();
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

		settings.beginGroup("Lost_Folio_Window");
		lostFolioUiName = settings.value("lostFolioUiName", lostFolioUiName).toString();
		lostFolioUiCloseButton = settings.value("lostFolioUiCloseButton", lostFolioUiCloseButton).toString();
		lostFolioUiMainTable = settings.value("lostFolioUiMainTable", lostFolioUiMainTable).toString();
		lostFolioUiMainTableC1Name = settings.value("lostFolioUiMainTableC1Name", lostFolioUiMainTableC1Name).toString();
		lostFolioUiMainTableC2Name = settings.value("lostFolioUiMainTableC2Name", lostFolioUiMainTableC2Name).toString();
		lostFolioUiMainTableC3Name = settings.value("lostFolioUiMainTableC3Name", lostFolioUiMainTableC3Name).toString();
		settings.endGroup();

		settings.beginGroup("Printing");
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
		addTimeRk = settings.value("addTimeRk", addTimeRk).toString();
		timeFormatRk = settings.value("timeFormatRk", timeFormatRk).toString();
		dateFormatRk = settings.value("dateFormatRk", dateFormatRk).toString();
		allIn = settings.value("allIn", allIn).toString();
		rkAdditionalServices = settings.value("rkAdditionalServices", rkAdditionalServices).toString();
		rkSittings = settings.value("rkSittings", rkSittings).toString();
		rkKitchen = settings.value("rkKitchen", rkKitchen).toString();
		rkBar = settings.value("rkBar", rkBar).toString();
		rkHotel = settings.value("rkHotel", rkHotel).toString();
		rkBaths = settings.value("rkBaths", rkBaths).toString();
		rkHookahs = settings.value("rkHookahs", rkHookahs).toString();
		rkInvaders = settings.value("rkInvaders", rkInvaders).toString();
		rkDiscounts = settings.value("rkDiscounts", rkDiscounts).toString();

		allVisitorsCount = settings.value("allVisitorsCount", allVisitorsCount).toString();
		incomeCards = settings.value("incomeCards", incomeCards).toString();

		whiteCard = settings.value("whiteCard", whiteCard).toString();
		whiteCash = settings.value("whiteCash", whiteCash).toString();
		whiteDisc = settings.value("whiteDisc", whiteDisc).toString();
		blueCard = settings.value("blueCard", blueCard).toString();
		blueCash = settings.value("blueCash", blueCash).toString();
		blueDisc = settings.value("blueDisc", blueDisc).toString();

		allFolios = settings.value("allFolios", allFolios).toString();
		cardByFolio = settings.value("cardByFolio", cardByFolio).toString();
		cashByFolio = settings.value("cashByFolio", cashByFolio).toString();
		lostFolios = settings.value("lostFolios", lostFolios).toString();
		settings.endGroup();
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
		settings.setValue("sqlRetries", sqlRetries);
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

		settings.beginGroup("Lost_Folio_Window");
		settings.setValue("lostFolioUiName", lostFolioUiName);
		settings.setValue("lostFolioUiCloseButton", lostFolioUiCloseButton);
		settings.setValue("lostFolioUiMainTable", lostFolioUiMainTable);
		settings.setValue("lostFolioUiMainTableC1Name", lostFolioUiMainTableC1Name);
		settings.setValue("lostFolioUiMainTableC2Name", lostFolioUiMainTableC2Name);
		settings.setValue("lostFolioUiMainTableC3Name", lostFolioUiMainTableC3Name);
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
		settings.setValue("addTimeRk", addTimeRk);
		settings.setValue("timeFormatRk", timeFormatRk);
		settings.setValue("dateFormatRk", dateFormatRk);
		settings.setValue("allIn", allIn);
		settings.setValue("rkAdditionalServices", rkAdditionalServices);
		settings.setValue("rkSittings", rkSittings);
		settings.setValue("rkKitchen", rkKitchen);
		settings.setValue("rkBar", rkBar);
		settings.setValue("rkHotel", rkHotel);
		settings.setValue("rkBaths", rkBaths);
		settings.setValue("rkHookahs", rkHookahs);
		settings.setValue("rkInvaders", rkInvaders);
		settings.setValue("rkDiscounts", rkDiscounts);
		settings.setValue("allVisitorsCount", allVisitorsCount);
		settings.setValue("incomeCards", incomeCards);
		settings.setValue("whiteCard", whiteCard);
		settings.setValue("whiteCash", whiteCash);
		settings.setValue("whiteDisc", whiteDisc);
		settings.setValue("blueCard", blueCard);
		settings.setValue("blueCash", blueCash);
		settings.setValue("blueDisc", blueDisc);
		settings.setValue("allFolios", allFolios);
		settings.setValue("cardByFolio", cardByFolio);
		settings.setValue("cashByFolio", cashByFolio);
		settings.setValue("lostFolios", lostFolios);
		settings.endGroup();

		settings.sync();
	}
}


QString Settings::fNum(qint64 num)
{
	QString src = QString::number(num);
	QString res;
	if (src.size() > 0)
		for (qint64 i = 0; i < src.size(); i++)
		{
			if ((src.size() - i) % 3 == 0)
				res.append(' ');
			res.append(src.at(i));
		}

	return res;
}