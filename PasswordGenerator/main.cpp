#include "PasswordGenerator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PasswordGenerator w;
	w.show();
	return a.exec();
}
