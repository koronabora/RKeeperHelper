// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <QtWidgets/QMainWindow>
#include <QProgressBar>
#include <QSpinBox>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QTableWidget>
#include <QUiLoader> 
#include "ui_AquaPrinter.h"
#include "Settings.h"

class AquaPrinter : public QMainWindow
{
	Q_OBJECT

public:
	AquaPrinter(QWidget *parent = Q_NULLPTR);

private:
	Ui::AquaPrinterClass ui;

	AllData curData;

	QCalendarWidget* calendar;
	QSpinBox* blueAllEdit;
	QLabel* blueOriginalLabel;
	QSpinBox* blueCashEdit;
	QLabel* blueCashOriginalLabel;
	QSpinBox* blueCardEdit;
	QLabel* blueCardOriginalEdit;
	QSpinBox* 	whiteAllEdit;
	QLabel* whiteAllOriginalLabel;
	QSpinBox* whiteCashEdit;
	QLabel* whiteOriginalCashEdit;
	QSpinBox* whiteCardEdit;
	QLabel* whiteCardOriginalLabel;
	
	QSpinBox* allKeysCount;
	QSpinBox* allVisitorsCount;
	QSpinBox* vipVisitors;

	QSpinBox* allInEdit;
	QSpinBox* allSitEdit;
	QSpinBox* allFoodEdit;
	QSpinBox* allBar;
	QSpinBox* allHotelEdit;
	QSpinBox* allAdditionalServicesEdit;
	QSpinBox* allInvadersEdit;
	QSpinBox* allDiscountsEdit;
	QSpinBox* cashToBank;
	QSpinBox* finalCashe;

	QSpinBox* allBathEdit;
	QSpinBox* allHookahEdit;
	QSpinBox* cashToBankPrev;
	QSpinBox* finalBank;
	QSpinBox* blueDisc;
	QSpinBox* whiteDisc;
	QSpinBox* diffFromPrevDay;

	QSpinBox* writeOffs;
	QSpinBox* lostFolios;
	QPushButton* lostFoliosButton;

	QPushButton* printButton;
	QStatusBar* statusBar;
	QLabel* statusBarLabel;
	QProgressBar* statusProgressBar;

	void fillData();
	quint64 fbState;
	quint64 msState;
	void updateStatusBar();
	void updateFinalCash();

	QUiLoader loader;
signals:
	void getInfo(QDate date);
	void printInfo(AllData s);

public slots :
	void calendarSelected();
	void buttonPressed();
	void lostFoliosButtonPressed();
	void haveInfo(AllData s);
	void blueAllEdited(int i);
	void blueCashEdited(int i);
	void blueCardEdited(int i);
	void whiteAllEdited(int i);
	void whiteCashEdited(int i);
	void whiteCardEdited(int i);
	void cashToBankTextChanged(int i);
	void cashToBankPrevTextChanged(int i);
	void writeOffTextChanged(int i);
	void mssqlStateChanged(quint64 state);
	void fbsqllStateChanged(quint64 state);
	void updateProgressBar();
	void vipVisitorsChanged(int i);
};
