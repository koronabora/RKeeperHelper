// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "AllData.h"

AllData::AllData()
{
	date = QDate::currentDate();
	blueAll = 0;
	blueAllOrig = 0;
	blueCash = 0;
	blueCashOrig = 0;
	blueCard = 0;
	blueCardOrig = 0;
	blueDisc = 0;
	whiteAll = 0;
	whiteAllOrig = 0;
	whiteCash = 0;
	whiteCashOrig = 0;
	whiteCard = 0;
	whiteCardOrig = 0;
	whiteDisc = 0;
	allKeysCount = 0;
	allVisitorsCount = 0;
	allIn = 0;
	allSit = 0;
	allFood = 0;
	allBar = 0;
	allHotel = 0;
	allAdditionalServices = 0;
	allInvaders = 0;
	allDiscounts = 0;
	diffFromPrevDay = 0;
	vipVisitors = 0;
	finalCash = 0;
	cashToBank = 0;
	allHookah = 0;
	allBath = 0;
	cashToBankPrev = 0;
	finalBank = 0;
	writeOffs = 0;
	lostFolios.clear();
}

AllData::~AllData()
{}

void AllData::operator=(const AllData &d)
{
	this->date = d.date;
	this->blueAll = d.blueAll;
	this->blueAllOrig = d.blueAllOrig;
	this->blueCash = d.blueCash;
	this->blueCashOrig = d.blueCashOrig;
	this->blueCard = d.blueCard;
	this->blueCardOrig = d.blueCardOrig;
	this->blueDisc = d.blueDisc;
	this->whiteAll = d.whiteAll;
	this->whiteAllOrig = d.whiteAllOrig;
	this->whiteCash = d.whiteCash;
	this->whiteCashOrig = d.whiteCashOrig;
	this->whiteCard = d.whiteCard;
	this->whiteCardOrig = d.whiteCardOrig;
	this->whiteDisc = d.whiteDisc;
	this->allKeysCount = d.allKeysCount;
	this->allVisitorsCount = d.allVisitorsCount;
	this->allIn = d.allIn;
	this->allSit = d.allSit;
	this->allFood = d.allFood;
	this->allBar = d.allBar;
	this->allHotel = d.allHotel;
	this->allAdditionalServices = d.allAdditionalServices;
	this->allInvaders = d.allInvaders;
	this->allDiscounts = d.allDiscounts;
	this->diffFromPrevDay = d.diffFromPrevDay;
	this->vipVisitors = d.vipVisitors;
	this->finalCash = d.finalCash;
	this->cashToBank = d.cashToBank;
	this->allHookah = d.allHookah;
	this->allBath = d.allBath;
	this->cashToBankPrev = d.cashToBankPrev;
	this->finalBank = d.finalBank;
	this->lostFolios = d.lostFolios;
	this->writeOffs = d.writeOffs;
}

AllData::AllData(const AllData& d)
{
	date = d.date;
	blueAll = d.blueAll;
	blueAllOrig = d.blueAllOrig;
	blueCash = d.blueCash;
	blueCashOrig = d.blueCashOrig;
	blueCard = d.blueCard;
	blueCardOrig = d.blueCardOrig;
	blueDisc = d.blueDisc;
	whiteAll = d.whiteAll;
	whiteAllOrig = d.whiteAllOrig;
	whiteCash = d.whiteCash;
	whiteCashOrig = d.whiteCashOrig;
	whiteCard = d.whiteCard;
	whiteCardOrig = d.whiteCardOrig;
	whiteDisc = d.whiteDisc;
	allKeysCount = d.allKeysCount;
	allVisitorsCount = d.allVisitorsCount;
	allIn = d.allIn;
	allSit = d.allSit;
	allFood = d.allFood;
	allBar = d.allBar;
	allHotel = d.allHotel;
	allHookah = d.allHookah;
	allBath = d.allBath;
	allAdditionalServices = d.allAdditionalServices;
	allInvaders = d.allInvaders;
	allDiscounts = d.allDiscounts;
	diffFromPrevDay = d.diffFromPrevDay;
	vipVisitors = d.vipVisitors;
	finalCash = d.finalCash;
	cashToBank = d.cashToBank;
	cashToBankPrev = d.cashToBankPrev;
	finalBank = d.finalBank;
	lostFolios = d.lostFolios;
	writeOffs = d.writeOffs;
}