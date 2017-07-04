// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once

#include <Qobject.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include "Settings.h"

class PrintHandler : public QObject
{
	Q_OBJECT
public:
	PrintHandler();
	~PrintHandler();

private: 
	QString fNum(qint64 num);

public slots :
	void run();
	void printInfo(AllData s);

signals:
	void workFinished();
};