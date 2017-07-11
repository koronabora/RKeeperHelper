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
	vipVisitors = ui.vipVisitors;
	
	allInEdit = ui.allInEdit;
	allSitEdit = ui.allSitEdit;
	allFoodEdit = ui.allFoodEdit;
	allHotelEdit = ui.allHotelEdit;
	allAdditionalServicesEdit = ui.allAdditionalServicesEdit;
	allInvadersEdit = ui.allInvadersEdit;
	allDiscountsEdit = ui.allDiscountsEdit;
	cashToBank = ui.cashToBank;
	finalCashe = ui.finalCashe;
	printButton = ui.printButton;
	statusBar = ui.statusBar;
	allBar = ui.allBar;
	allBathEdit = ui.allBathEdit;
	allHookahEdit = ui.allHookahEdit;
	cashToBankPrev = ui.cashToBankPrev;
	finalBank = ui.finalBank;
	blueDisc = ui.blueDisc;
	whiteDisc = ui.whiteDisc;
	diffFromPrevDay = ui.diffFromPrevDay;
	writeOffs = ui.writeOffs;
	lostFolios = ui.lostFolios;
	lostFoliosButton = ui.lostFoliosButton;

	if (lostFoliosButton != nullptr)
		connect(lostFoliosButton, &QPushButton::pressed, this, &AquaPrinter::lostFoliosButtonPressed);

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
		connect(blueCashEdit, SIGNAL(valueChanged(int)), this, SLOT(blueCashEdited(int)));

	if (blueCardEdit != nullptr)
		connect(blueCardEdit, SIGNAL(valueChanged(int)), this, SLOT(blueCardEdited(int)));

	if (whiteCashEdit != nullptr)
		connect(whiteCashEdit, SIGNAL(valueChanged(int)), this, SLOT(whiteCashEdited(int)));

	if (whiteCardEdit != nullptr)
		connect(whiteCardEdit, SIGNAL(valueChanged(int)), this, SLOT(whiteCardEdited(int)));

	if (cashToBank != nullptr)
		connect(cashToBank, SIGNAL(valueChanged(int)), this, SLOT(cashToBankTextChanged(int)));
	if (cashToBankPrev != nullptr)
		connect(cashToBankPrev, SIGNAL(valueChanged(int)), this, SLOT(cashToBankPrevTextChanged(int)));

	if (vipVisitors!=nullptr)
		connect(vipVisitors, SIGNAL(valueChanged(int)), this, SLOT(vipVisitorsChanged(int)));

	if (writeOffs!=nullptr)
		connect(writeOffs, SIGNAL(valueChanged(int)), this, SLOT(writeOffTextChanged(int)));

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
		blueOriginalLabel->setText(Settings::fNum(curData.blueAllOrig));
		blueOriginalLabel->setVisible(false);
	}
	if (blueCashEdit != nullptr)
		blueCashEdit->setValue((curData.blueCash));
	if (blueCashOriginalLabel != nullptr)
	{
		blueCashOriginalLabel->setText(Settings::fNum(curData.blueCashOrig));
		blueCashOriginalLabel->setVisible(false);
	}
	if (blueCardEdit != nullptr)
		blueCardEdit->setValue((curData.blueCard));
	if (blueCardOriginalEdit != nullptr)
	{
		blueCardOriginalEdit->setText(Settings::fNum(curData.blueCardOrig));
		blueCardOriginalEdit->setVisible(false);
	}
	if (whiteAllEdit != nullptr)
		whiteAllEdit->setValue((curData.whiteAll));
	if (whiteAllOriginalLabel != nullptr)
	{
		whiteAllOriginalLabel->setText(Settings::fNum(curData.whiteAllOrig));
		whiteAllOriginalLabel->setVisible(false);
	}
	if (whiteCashEdit != nullptr)
		whiteCashEdit->setValue((curData.whiteCash));
	if (whiteOriginalCashEdit != nullptr)
	{
		whiteOriginalCashEdit->setText(Settings::fNum(curData.whiteCashOrig));
		whiteOriginalCashEdit->setVisible(false);
	}
	if (whiteCardEdit != nullptr)
		whiteCardEdit->setValue((curData.whiteCard));
	if (whiteCardOriginalLabel != nullptr)
	{
		whiteCardOriginalLabel->setText(Settings::fNum(curData.whiteCardOrig));
		whiteCardOriginalLabel->setVisible(false);
	}
	if (allKeysCount != nullptr)
		allKeysCount->setValue((curData.allKeysCount));

	if (vipVisitors != nullptr)
		vipVisitors->setValue(curData.vipVisitors);

	if (allVisitorsCount != nullptr)
		allVisitorsCount->setValue((curData.allVisitorsCount + curData.vipVisitors));

	if (allInEdit != nullptr)
		allInEdit->setValue((curData.allIn));
	if (allSitEdit != nullptr)
		allSitEdit->setValue((curData.allSit));
	if (allFoodEdit != nullptr)
		allFoodEdit->setValue((curData.allFood));
	if (allHotelEdit != nullptr)
		allHotelEdit->setValue((curData.allHotel));
	if (allAdditionalServicesEdit != nullptr)
		allAdditionalServicesEdit->setValue((curData.allAdditionalServices));
	if (allInvadersEdit != nullptr)
		allInvadersEdit->setValue((curData.allInvaders));
	if (allDiscountsEdit != nullptr)
		allDiscountsEdit->setValue((curData.allDiscounts));
	if (cashToBank != nullptr)
		cashToBank->setValue(curData.cashToBank);
	if (allBathEdit!=nullptr)
		allBathEdit->setValue(curData.allBath);
	if (allHookahEdit != nullptr)
		allHookahEdit->setValue(curData.allHookah);
	if (cashToBankPrev != nullptr)
		cashToBankPrev->setValue(curData.cashToBankPrev);
	if (finalBank != nullptr)
		finalBank->setValue(curData.finalBank);
	if (blueDisc != nullptr)
		blueDisc->setValue(curData.blueDisc);
	if (whiteDisc != nullptr)
		whiteDisc->setValue(curData.whiteDisc);
	if (allBar != nullptr)
		allBar->setValue(curData.allBar);
	if (diffFromPrevDay != nullptr)
		diffFromPrevDay->setValue(curData.diffFromPrevDay);
	if (lostFolios != nullptr)
		lostFolios->setValue(curData.lostFolios.size());
	if (writeOffs != nullptr)
		writeOffs->setValue(curData.writeOffs);
	updateFinalCash();
}

void AquaPrinter::updateStatusBar()
{
	QString s;
	s.append("Абонемент: ");
	s.append(SQL_STATE_NAMES.at(fbState));
	s.append(" | RKeeper: ");
	s.append(SQL_STATE_NAMES.at(msState));
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

void AquaPrinter::blueAllEdited(int i)
{
	if (blueAllEdit != nullptr && blueOriginalLabel != nullptr)
	{ 
		if (blueAllEdit->value()>0 && blueAllEdit->value() != curData.blueAllOrig)
		{
			blueOriginalLabel->setText(Settings::i()->uiOrigionalText + Settings::fNum(curData.blueAllOrig));
			blueOriginalLabel->setVisible(true);
		}
		else
			blueOriginalLabel->setVisible(false);
	}
	updateFinalCash();
}

void AquaPrinter::blueCashEdited(int i)
{
	if (blueCashEdit != nullptr && blueCashOriginalLabel != nullptr)
	{
		if (blueCashEdit->value()>0 && blueCashEdit->value()!=curData.blueCashOrig)
		{
			blueCashOriginalLabel->setText(Settings::i()->uiOrigionalText + Settings::fNum(curData.blueCashOrig));
			blueCashOriginalLabel->setVisible(true);
		}
		else
			blueCashOriginalLabel->setVisible(false);

		curData.blueCash = blueCashEdit->value();
		curData.blueAll = curData.blueCard + curData.blueCash;
		blueAllEdit->setValue(curData.blueAll);
		blueAllEdited(curData.blueAll);
	}
	updateFinalCash();
}

void AquaPrinter::blueCardEdited(int i)
{
	if (blueCardEdit != nullptr && blueCardOriginalEdit != nullptr)
	{
		if (blueCardEdit->value()>0 && blueCardEdit->value()!=curData.blueCardOrig)
		{
			blueCardOriginalEdit->setText(Settings::i()->uiOrigionalText + Settings::fNum(curData.blueCardOrig));
			blueCardOriginalEdit->setVisible(true);
		}
		else
			blueCardOriginalEdit->setVisible(false);
		curData.blueCard = blueCardEdit->value();
		curData.blueAll = curData.blueCard + curData.blueCash;
		blueAllEdit->setValue(curData.blueAll);
		blueAllEdited(curData.blueAll);
	}
}

void AquaPrinter::whiteAllEdited(int i)
{
	if (whiteAllEdit != nullptr && whiteAllOriginalLabel != nullptr)
	{
		if (whiteAllEdit->value()>0 && whiteAllEdit->value()!=curData.whiteAllOrig)
		{
			whiteAllOriginalLabel->setText(Settings::i()->uiOrigionalText + Settings::fNum(curData.whiteAllOrig));
			whiteAllOriginalLabel->setVisible(true);
		}
		else
			whiteAllOriginalLabel->setVisible(false);
	}
}

void AquaPrinter::whiteCashEdited(int i)
{	
	if (whiteCashEdit != nullptr && whiteOriginalCashEdit != nullptr)
	{
		if (whiteCashEdit->value()>0 && whiteCashEdit->value()!=curData.whiteCashOrig)
		{
			whiteOriginalCashEdit->setText(Settings::i()->uiOrigionalText + Settings::fNum(curData.whiteCashOrig));
			whiteOriginalCashEdit->setVisible(true);
		}
		else
			whiteOriginalCashEdit->setVisible(false);
		curData.whiteCash = whiteCashEdit->value();
		curData.whiteAll = curData.whiteCard + curData.whiteCash;
		whiteAllEdit->setValue(curData.whiteAll);
		whiteAllEdited(curData.whiteAll);
	}
	updateFinalCash();
}

void AquaPrinter::whiteCardEdited(int i)
{
	if (whiteCardEdit != nullptr && whiteCardOriginalLabel != nullptr)
	{
		if (whiteCardEdit->value()>0 && whiteCardEdit->value()!=curData.whiteCardOrig)
		{
			whiteCardOriginalLabel->setText(Settings::i()->uiOrigionalText + Settings::fNum(curData.whiteCardOrig));
			whiteCardOriginalLabel->setVisible(true);
		}
		else
			whiteCardOriginalLabel->setVisible(false);
		curData.whiteCard = whiteCardEdit->value();
		curData.whiteAll = curData.whiteCard + curData.whiteCash;
		whiteAllEdit->setValue(curData.whiteAll);
		whiteAllEdited(curData.whiteAll);
	}
	updateFinalCash();
}

void AquaPrinter::cashToBankTextChanged(int i)
{
	curData.cashToBank = i;
	updateFinalCash();
}

void AquaPrinter::cashToBankPrevTextChanged(int i)
{
	curData.cashToBankPrev = i;
	updateFinalCash();
}

void AquaPrinter::updateFinalCash()
{
	curData.finalCash = curData.whiteCash + curData.blueCash - curData.cashToBank - curData.writeOffs;
	curData.finalBank = curData.cashToBank + curData.cashToBankPrev+curData.whiteCard+curData.blueCard;
	if (finalCashe != nullptr)
		finalCashe->setValue(curData.finalCash);
	if (finalBank != nullptr)
		finalBank->setValue(curData.finalBank);
}

void AquaPrinter::mssqlStateChanged(quint64 state)
{
	msState = state;
	updateStatusBar();
}

void AquaPrinter::fbsqllStateChanged(quint64 state)
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

void AquaPrinter::vipVisitorsChanged(int i)
{
	curData.vipVisitors = i;
	if (allVisitorsCount != nullptr)
		allVisitorsCount->setValue(curData.allVisitorsCount + curData.vipVisitors);
}

void AquaPrinter::lostFoliosButtonPressed()
{
	QString name = QDir::currentPath() + "//" + Settings::i()->lostFolioUiName;
	QFile file(name);
	bool ok = file.open(QIODevice::ReadOnly);
	QWidget* wnd = (QWidget*)loader.load(&file, this);
	file.close();
	if (wnd != Q_NULLPTR)
	{
		wnd->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
		
		QTableWidget* table = wnd->findChild<QTableWidget*>(Settings::i()->lostFolioUiMainTable);
		if (table != nullptr)
		{
			table->setColumnCount(3);
			table->setHorizontalHeaderLabels(QStringList({Settings::i()->lostFolioUiMainTableC1Name, Settings::i()->lostFolioUiMainTableC2Name, Settings::i()->lostFolioUiMainTableC3Name}));
			table->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
			if (curData.lostFolios.size()>0)
			for (quint64 i=0; i<curData.lostFolios.size(); i++)
			{
				QVector<qint64> v = curData.lostFolios.at(i);
				int row = table->rowCount();
				table->setRowCount(row+1);
				if (v.size() > 0)
				{
					QTableWidgetItem* t = new QTableWidgetItem(Settings::fNum(v.at(0)));
					t->setTextAlignment(Qt::AlignCenter);
					table->setItem(row, 0, t);
				}
				if (v.size() > 1)
				{
					QTableWidgetItem* t = new QTableWidgetItem(Settings::fNum(v.at(1)));
					t->setTextAlignment(Qt::AlignCenter);
					table->setItem(row, 1, t);
				}
				if (v.size() > 2)
				{
					QTableWidgetItem* t = new QTableWidgetItem(Settings::fNum(v.at(2)));
					t->setTextAlignment(Qt::AlignCenter);
					table->setItem(row, 2, t);
				}
			}
		}

		QPushButton* okButton = wnd->findChild<QPushButton*>(Settings::i()->lostFolioUiCloseButton);
		if (okButton != Q_NULLPTR)
			connect(okButton, &QPushButton::pressed, wnd, &QWidget::close);

		wnd->show();
	}
}

void AquaPrinter::writeOffTextChanged(int i)
{
	curData.writeOffs = i;
	updateFinalCash();
}