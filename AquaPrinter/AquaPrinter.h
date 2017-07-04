// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <QtWidgets/QMainWindow>
#include <QProgressBar>
#include <QSpinBox>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
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
	QSpinBox* cashInEdit;
	QSpinBox* cashSitEdit;
	QSpinBox* cashFoodEdit;
	QSpinBox* cashHotelEdit;
	QSpinBox* cashAdditionalServicesEdit;
	QSpinBox* cashInvadersEdit;
	QSpinBox* cardInEdit;
	QSpinBox* cardSitEdit;
	QSpinBox* cardFoodEdit;
	QSpinBox* cardHotelEdit;
	QSpinBox* cardAdditionalServicesEdit;
	QSpinBox* cashToBank;
	QSpinBox* finalCashe;
	QPushButton* printButton;
	QStatusBar* statusBar;
	QLabel* statusBarLabel;
	QProgressBar* statusProgressBar;

	void fillData();
	bool fbState;
	bool msState;
	void updateStatusBar();
	void updateFinalCash();

signals:
	void getInfo(QDate date);
	void printInfo(AllData s);

public slots :
	void calendarSelected();
	void buttonPressed();
	void haveInfo(AllData s);
	void blueAllEdited();
	void blueCashEdited();
	void blueCardEdited();
	void whiteAllEdited();
	void whiteCashEdited();
	void whiteCardEdited();
	void cashToBankTextChanged(int i);
	void mssqlStateChanged(bool state);
	void fbsqllStateChanged(bool state);
	void updateProgressBar();
};
