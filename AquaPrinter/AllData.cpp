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
	whiteAll = 0;
	whiteAllOrig = 0;
	whiteCash = 0;
	whiteCashOrig = 0;
	whiteCard = 0;
	whiteCardOrig = 0;
	allKeysCount = 0;
	allVisitorsCount = 0;
	cashIn = 0;
	cashSit = 0;
	cashFood = 0;
	cashHotel = 0;
	cashHookah = 0;
	cashBath = 0;
	cashAdditionalServices = 0;
	cashInvaders = 0;
	cardIn = 0;
	cardSit = 0;
	cardFood = 0;
	cardHotel = 0;
	cardHookah = 0;
	cardBath = 0;
	cardAdditionalServices = 0;
	finalCash = 0;
	cashToBank = 0;
}

AllData::~AllData()
{}

AllData & AllData::operator=(const AllData &d)
{
	this->date = d.date;
	this->blueAll = d.blueAll;
	this->blueCash = d.blueCash;
	this->blueCard = d.blueCard;
	this->whiteAll = d.whiteAll;
	this->whiteCash = d.whiteCash;
	this->whiteCard = d.whiteCard;
	this->blueAllOrig = d.blueAllOrig;
	this->blueCashOrig = d.blueCashOrig;
	this->blueCardOrig = d.blueCardOrig;
	this->whiteAllOrig = d.whiteAllOrig;
	this->whiteCashOrig = d.whiteCashOrig;
	this->whiteCardOrig = d.whiteCardOrig;
	this->allKeysCount = d.allKeysCount;
	this->allVisitorsCount = d.allVisitorsCount;
	this->cashIn = d.cashIn;
	this->cashSit = d.cashSit;
	this->cashFood = d.cashFood;
	this->cashHotel = d.cashHotel;
	this->cashBath = d.cashBath;
	this->cashHookah = d.cashHookah;
	this->cashAdditionalServices = d.cashAdditionalServices;
	this->cashInvaders = d.cashInvaders;
	this->cardIn = d.cardIn;
	this->cardSit = d.cardSit;
	this->cardFood = d.cardFood;
	this->cardHotel = d.cardHotel;
	this->cardBath = d.cardBath;
	this->cardHookah = d.cardHookah;
	this->cardAdditionalServices = d.cardAdditionalServices;
	this->finalCash = d.finalCash;
	this->cashToBank = d.cashToBank;
	return AllData(d);
}

AllData::AllData(const AllData& d)
{
	date = d.date;
	blueAll = d.blueAll;
	blueCash = d.blueCash;
	blueCard = d.blueCard;
	whiteAll = d.whiteAll;
	whiteCash = d.whiteCash;
	whiteCard = d.whiteCard;
	blueAllOrig = d.blueAllOrig;
	blueCashOrig = d.blueCashOrig;
	blueCardOrig = d.blueCardOrig;
	whiteAllOrig = d.whiteAllOrig;
	whiteCashOrig = d.whiteCashOrig;
	whiteCardOrig = d.whiteCardOrig;
	allKeysCount = d.allKeysCount;
	allVisitorsCount = d.allVisitorsCount;
	cashIn = d.cashIn;
	cashSit = d.cashSit;
	cashFood = d.cashFood;
	cashHotel = d.cashHotel;
	cardBath = d.cardBath;
	cardHookah = d.cardHookah;
	cashAdditionalServices = d.cashAdditionalServices;
	cashInvaders = d.cashInvaders;
	cardIn = d.cardIn;
	cardSit = d.cardSit;
	cardFood = d.cardFood;
	cardHotel = d.cardHotel;
	cardBath = d.cardBath;
	cardHookah = d.cardHookah;
	cardAdditionalServices = d.cardAdditionalServices;
	finalCash = d.finalCash;
	cashToBank = d.cashToBank;
}