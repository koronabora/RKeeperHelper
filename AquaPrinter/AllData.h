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
	void operator =(const AllData &);
	QDate date;
	qint64 blueAll;
	qint64 blueAllOrig;
	qint64 blueCash;
	qint64 blueCashOrig;
	qint64 blueCard;
	qint64 blueCardOrig;
	qint64 blueDisc;
	qint64 whiteAll;
	qint64 whiteAllOrig;
	qint64 whiteCash;
	qint64 whiteCashOrig;
	qint64 whiteCard;
	qint64 whiteCardOrig;
	qint64 whiteDisc;
	qint64 allKeysCount;
	qint64 allVisitorsCount;
	qint64 allIn;
	qint64 allSit;
	qint64 allFood;
	qint64 allBar;
	qint64 allHotel;
	qint64 allAdditionalServices;
	qint64 allInvaders;
	qint64 allDiscounts;
	qint64 diffFromPrevDay;
	qint64 vipVisitors;
	qint64 finalCash;
	qint64 cashToBank;
	qint64 allHookah;
	qint64 allBath;
	qint64 cashToBankPrev;
	qint64 finalBank;
	qint64 writeOffs;
	QVector<QVector<qint64>> lostFolios;
};