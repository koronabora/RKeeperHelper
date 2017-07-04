// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "AquaPrinter.h"

AquaPrinter::AquaPrinter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowIcon(QIcon(":/icon.ico"));
	calendar = ui.calendar;
	blueAllEdit = ui.blueAllEdit;
	blueOriginalLabel = ui.blueOriginalLabel;
	blueCashEdit = ui.blueCashEdit;
	blueCashOriginalLabel = ui.blueCashOriginalLabel;
	blueCardEdit = ui.blueCardEdit;
	blueCardOriginalEdit = ui.blueCardOriginalEdit;
	whiteAllEdit = ui.whiteAllEdit;
	whiteAllOriginalLabel = ui.whiteAllOriginalLabel;
	whiteCashEdit = ui.whiteCashEdit;
	whiteOriginalCashEdit = ui.whiteOriginalCashEdit;
	whiteCardEdit = ui.whiteCardEdit;
	whiteCardOriginalLabel = ui.whiteCardOriginalLabel;
	allKeysCount = ui.allKeysCount;
	allVisitorsCount = ui.allVisitorsCount;
	cashInEdit = ui.cashInEdit;
	cashSitEdit = ui.cashSitEdit;
	cashFoodEdit = ui.cashFoodEdit;
	cashHotelEdit = ui.cashHotelEdit;
	cashAdditionalServicesEdit = ui.cashAdditionalServicesEdit;
	cashInvadersEdit = ui.cashInvadersEdit;
	cardInEdit = ui.cardInEdit;
	cardSitEdit = ui.cardSitEdit;
	cardFoodEdit = ui.cardFoodEdit;
	cardHotelEdit = ui.cardHotelEdit;
	cardAdditionalServicesEdit = ui.cardAdditionalServicesEdit;
	cashToBank = ui.cashToBank;
	finalCashe = ui.finalCashe;
	printButton = ui.printButton;
	statusBar = ui.statusBar;
	statusBarLabel = new QLabel();
	statusProgressBar = new QProgressBar();
	if (statusProgressBar != nullptr)
		statusProgressBar->setMaximum(Settings::i()->progressBarMax);
	if (statusBar != nullptr)
	{
		statusBar->addPermanentWidget(statusBarLabel, 0);
		statusBar->addPermanentWidget(statusProgressBar, 1);
	}

	if (calendar != nullptr)
		connect(calendar, &QCalendarWidget::selectionChanged, this, &AquaPrinter::calendarSelected);

	if (printButton != nullptr)
		connect(printButton, &QPushButton::pressed, this, &AquaPrinter::buttonPressed);

	if (blueCashEdit != nullptr)
		connect(blueCashEdit, &QSpinBox::editingFinished, this, &AquaPrinter::blueCashEdited);

	if (blueCardEdit != nullptr)
		connect(blueCardEdit, &QSpinBox::editingFinished, this, &AquaPrinter::blueCardEdited);

	if (whiteCashEdit != nullptr)
		connect(whiteCashEdit, &QSpinBox::editingFinished, this, &AquaPrinter::whiteCashEdited);

	if (whiteCardEdit != nullptr)
		connect(whiteCardEdit, &QSpinBox::editingFinished, this, &AquaPrinter::whiteCardEdited);

	if (cashToBank != nullptr)
		connect(cashToBank, SIGNAL(valueChanged(int)), this, SLOT(cashToBankTextChanged(int)));

	fbState = false;
	msState = false;
	updateStatusBar();
	if (calendar != nullptr)
		calendar->setSelectedDate(QDate::currentDate().addDays(1));
}

void AquaPrinter::fillData()
{
	if (blueAllEdit != nullptr)
		blueAllEdit->setValue(curData.blueAll);
	if (blueOriginalLabel != nullptr)
	{
		blueOriginalLabel->setText(QString::number(curData.blueAllOrig));
		blueOriginalLabel->setVisible(false);
	}
	if (blueCashEdit != nullptr)
		blueCashEdit->setValue((curData.blueCash));
	if (blueCashOriginalLabel != nullptr)
	{
		blueCashOriginalLabel->setText(QString::number(curData.blueCashOrig));
		blueCashOriginalLabel->setVisible(false);
	}
	if (blueCardEdit != nullptr)
		blueCardEdit->setValue((curData.blueCard));
	if (blueCardOriginalEdit != nullptr)
	{
		blueCardOriginalEdit->setText(QString::number(curData.blueCardOrig));
		blueCardOriginalEdit->setVisible(false);
	}
	if (whiteAllEdit != nullptr)
		whiteAllEdit->setValue((curData.whiteAll));
	if (whiteAllOriginalLabel != nullptr)
	{
		whiteAllOriginalLabel->setText(QString::number(curData.whiteAllOrig));
		whiteAllOriginalLabel->setVisible(false);
	}
	if (whiteCashEdit != nullptr)
		whiteCashEdit->setValue((curData.whiteCash));
	if (whiteOriginalCashEdit != nullptr)
	{
		whiteOriginalCashEdit->setText(QString::number(curData.whiteCashOrig));
		whiteOriginalCashEdit->setVisible(false);
	}
	if (whiteCardEdit != nullptr)
		whiteCardEdit->setValue((curData.whiteCard));
	if (whiteCardOriginalLabel != nullptr)
	{
		whiteCardOriginalLabel->setText(QString::number(curData.whiteCardOrig));
		whiteCardOriginalLabel->setVisible(false);
	}
	if (allKeysCount != nullptr)
		allKeysCount->setValue((curData.allKeysCount));
	if (allVisitorsCount != nullptr)
		allVisitorsCount->setValue((curData.allVisitorsCount));
	if (cashInEdit != nullptr)
		cashInEdit->setValue((curData.cashIn));
	if (cashSitEdit != nullptr)
		cashSitEdit->setValue((curData.cashSit));
	if (cashFoodEdit != nullptr)
		cashFoodEdit->setValue((curData.cashFood));
	if (cashHotelEdit != nullptr)
		cashHotelEdit->setValue((curData.cashHotel));
	if (cashAdditionalServicesEdit != nullptr)
		cashAdditionalServicesEdit->setValue((curData.cashAdditionalServices));
	if (cashInvadersEdit != nullptr)
		cashInvadersEdit->setValue((curData.cashInvaders));
	if (cardInEdit != nullptr)
		cardInEdit->setValue((curData.cardIn));
	if (cardSitEdit != nullptr)
		cardSitEdit->setValue((curData.cardSit));
	if (cardFoodEdit != nullptr)
		cardFoodEdit->setValue((curData.cardFood));
	if (cardHotelEdit != nullptr)
		cardHotelEdit->setValue((curData.cardHotel));
	if (cardAdditionalServicesEdit != nullptr)
		cardAdditionalServicesEdit->setValue((curData.cardAdditionalServices));
	if (cashToBank != nullptr)
		cashToBank->setValue(0);
	updateFinalCash();
}

void AquaPrinter::updateStatusBar()
{
	QString s;
	s.append("Абонемент: ");
	if (fbState)
		s.append("Подключен");
	else
		s.append("Отключен");
	s.append(" | RKeeper: ");
	if (msState)
		s.append("Подключен");
	else
		s.append("Отключен");
	if (statusBarLabel!=nullptr)
		statusBarLabel->setText(s);
}

void AquaPrinter::buttonPressed()
{
	emit printInfo(curData);
}

void AquaPrinter::calendarSelected()
{
	if (calendar != nullptr)
		emit getInfo(calendar->selectedDate());
}

void AquaPrinter::haveInfo(AllData s)
{
	curData = s;
	fillData();
	statusProgressBar->reset();
}

void AquaPrinter::blueAllEdited()
{
	if (blueAllEdit != nullptr && blueOriginalLabel != nullptr)
	{ 
		if (blueAllEdit->value()>0 && blueAllEdit->value() != curData.blueAllOrig)
		{
			blueOriginalLabel->setText(Settings::i()->uiOrigionalText + QString::number(curData.blueAllOrig));
			blueOriginalLabel->setVisible(true);
		}
		else
			blueOriginalLabel->setVisible(false);
	}
	updateFinalCash();
}

void AquaPrinter::blueCashEdited()
{
	if (blueCashEdit != nullptr && blueCashOriginalLabel != nullptr)
	{
		if (blueCashEdit->value()>0 && blueCashEdit->value()!=curData.blueCashOrig)
		{
			blueCashOriginalLabel->setText(Settings::i()->uiOrigionalText + QString::number(curData.blueCashOrig));
			blueCashOriginalLabel->setVisible(true);
		}
		else
			blueCashOriginalLabel->setVisible(false);

		curData.blueCash = blueCashEdit->value();
		curData.blueAll = curData.blueCard + curData.blueCash;
		blueAllEdit->setValue(curData.blueAll);
		blueAllEdited();
	}
	updateFinalCash();
}

void AquaPrinter::blueCardEdited()
{
	if (blueCardEdit != nullptr && blueCardOriginalEdit != nullptr)
	{
		if (blueCardEdit->value()>0 && blueCardEdit->value()!=curData.blueCardOrig)
		{
			blueCardOriginalEdit->setText(Settings::i()->uiOrigionalText + QString::number(curData.blueCardOrig));
			blueCardOriginalEdit->setVisible(true);
		}
		else
			blueCardOriginalEdit->setVisible(false);
		curData.blueCard = blueCardEdit->value();
		curData.blueAll = curData.blueCard + curData.blueCash;
		blueAllEdit->setValue(curData.blueAll);
		blueAllEdited();
	}
}

void AquaPrinter::whiteAllEdited()
{
	if (whiteAllEdit != nullptr && whiteAllOriginalLabel != nullptr)
	{
		if (whiteAllEdit->value()>0 && whiteAllEdit->value()!=curData.whiteAllOrig)
		{
			whiteAllOriginalLabel->setText(Settings::i()->uiOrigionalText + QString::number(curData.whiteAllOrig));
			whiteAllOriginalLabel->setVisible(true);
		}
		else
			whiteAllOriginalLabel->setVisible(false);
	}
}

void AquaPrinter::whiteCashEdited()
{	
	if (whiteCashEdit != nullptr && whiteOriginalCashEdit != nullptr)
	{
		if (whiteCashEdit->value()>0 && whiteCashEdit->value()!=curData.whiteCashOrig)
		{
			whiteOriginalCashEdit->setText(Settings::i()->uiOrigionalText + QString::number(curData.whiteCashOrig));
			whiteOriginalCashEdit->setVisible(true);
		}
		else
			whiteOriginalCashEdit->setVisible(false);
		curData.whiteCash = whiteCashEdit->value();
		curData.whiteAll = curData.whiteCard + curData.whiteCash;
		whiteAllEdit->setValue(curData.whiteAll);
		whiteAllEdited();
	}
	updateFinalCash();
}

void AquaPrinter::whiteCardEdited()
{
	if (whiteCardEdit != nullptr && whiteCardOriginalLabel != nullptr)
	{
		if (whiteCardEdit->value()>0 && whiteCardEdit->value()!=curData.whiteCardOrig)
		{
			whiteCardOriginalLabel->setText(Settings::i()->uiOrigionalText + QString::number(curData.whiteCardOrig));
			whiteCardOriginalLabel->setVisible(true);
		}
		else
			whiteCardOriginalLabel->setVisible(false);
		curData.whiteCard = whiteCardEdit->value();
		curData.whiteAll = curData.whiteCard + curData.whiteCash;
		whiteAllEdit->setValue(curData.whiteAll);
		whiteAllEdited();
	}
	updateFinalCash();
}

void AquaPrinter::cashToBankTextChanged(int i)
{
	curData.cashToBank = i;
	updateFinalCash();
}

void AquaPrinter::updateFinalCash()
{
	curData.finalCash = curData.whiteCash + curData.blueCash - curData.cashToBank;
	if (finalCashe != nullptr)
		finalCashe->setValue(curData.finalCash);
}

void AquaPrinter::mssqlStateChanged(bool state)
{
	msState = state;
	updateStatusBar();
}

void AquaPrinter::fbsqllStateChanged(bool state)
{
	fbState = state;
	updateStatusBar();
}

void AquaPrinter::updateProgressBar()
{
	if (statusProgressBar != nullptr)
	{
		int val = statusProgressBar->value();
		if (val < statusProgressBar->maximum())
			statusProgressBar->setValue(val + 1);
		else
			statusProgressBar->reset();
	}
}
