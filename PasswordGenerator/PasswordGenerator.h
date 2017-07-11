#pragma once

#include <QLineEdit>
#include <QtWidgets/QMainWindow>
#include "ui_PasswordGenerator.h"

class PasswordGenerator : public QMainWindow
{
	Q_OBJECT

public:
	PasswordGenerator(QWidget *parent = Q_NULLPTR);

private:
	Ui::PasswordGeneratorClass ui;
	QLineEdit* pass;
	QLineEdit* hash;

public slots:
	void passwordChaned(QString text);
};
