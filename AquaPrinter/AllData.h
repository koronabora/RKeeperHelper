// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <QObject>
#include <QDate>

#include "Settings.h"

class AllData : public QObject
{
	Q_OBJECT
public:
	AllData(const AllData& d);
	AllData();
	~AllData();
	AllData &operator =(const AllData &);
	QDate date;
	qint64 blueAll;
	qint64 blueAllOrig;
	qint64 blueCash;
	qint64 blueCashOrig;
	qint64 blueCard;
	qint64 blueCardOrig;
	qint64 whiteAll;
	qint64 whiteAllOrig;
	qint64 whiteCash;
	qint64 whiteCashOrig;
	qint64 whiteCard;
	qint64 whiteCardOrig;
	qint64 allKeysCount;
	qint64 allVisitorsCount;
	qint64 cashIn;
	qint64 cashSit;
	qint64 cashFood;
	qint64 cashHotel;
	qint64 cashHookah;
	qint64 cashBath;
	qint64 cashAdditionalServices;
	qint64 cashInvaders;
	qint64 cardIn;
	qint64 cardSit;
	qint64 cardFood;
	qint64 cardHotel;
	qint64 cardHookah;
	qint64 cardBath;
	qint64 cardAdditionalServices;
	qint64 finalCash;
	qint64 cashToBank;
};