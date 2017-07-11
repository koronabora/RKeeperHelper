#include "PasswordGenerator.h"

PasswordGenerator::PasswordGenerator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowIcon(QIcon(":/iconpg.ico"));
	pass = ui.pass;
	hash = ui.hash;
	if (pass != nullptr)
		connect(pass, &QLineEdit::textChanged, this, &PasswordGenerator::passwordChaned);
}

void PasswordGenerator::passwordChaned(QString text)
{
	if (hash != nullptr)
		hash->setText(QString::number(qHash(text)));
}