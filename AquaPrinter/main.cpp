// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define QT_MESSAGELOGCONTEXT

#include "AquaPrinter.h"
#include <QtWidgets/QApplication>
#include <QThread>
#include <QObject>
#include <QDir>
#include "Worker.h"
#include "PrintHandler.h"
#include "Settings.h"

// thanks to PavelK
void myMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString &msg)
{
	QString txt;
	static long long uid = 0;
	QRegExp rx("([\\w-]+::[\\w-]+)");
	if (rx.indexIn(context.function) == -1)
		txt = msg;
	else
	{
		QString function = rx.cap(1);

		QString msgSep = (msg.length() > 0) ? ">> " : "";

		switch (type) {
		case QtInfoMsg:
			txt = QString("Info: %1%2%3").arg(function).arg(msgSep).arg(msg);
			break;
		case QtDebugMsg:
			txt = QString("Debug: %1%2%3").arg(function).arg(msgSep).arg(msg);
			break;
		case QtWarningMsg:
			txt = QString("Warning: %1%2%3").arg(function).arg(msgSep).arg(msg);
			break;
		case QtCriticalMsg:
			txt = QString("Critical: %1%2%3").arg(function).arg(msgSep).arg(msg);
			break;
		case QtFatalMsg:
			txt = QString("Fatal: %1%2%3").arg(function).arg(msgSep).arg(msg);
			abort();
			break;
		}
	}

	QDateTime dateTime = QDateTime::currentDateTime();
	uid++;
	txt = QString("%1:%2 %3").arg(dateTime.toString(Qt::ISODate)).arg(uid).arg(txt);

	QString path = QString("%1/log-%2.log").arg("./Logs").arg(QDate::currentDate().toString("dd.MM.yy"));
	QFile outFile(path);
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&outFile);
	ts << txt << endl;
	outFile.close();
}

int main(int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("AQUA");
	QCoreApplication::setApplicationName("AquaPrinter");
	QApplication a(argc, argv);
	qInstallMessageHandler(myMessageHandler);
	qRegisterMetaType<AllData>("AllData");

	qInfo() << "Starting an application!";

	Settings::i()->init();
	AquaPrinter ui;

	qInfo() << "Loading worker!";
	Worker w;
	QThread* wt = new QThread();
	w.moveToThread(wt);
	QObject::connect(wt, SIGNAL(started()), &w, SLOT(run()));
	QObject::connect(&w, SIGNAL(workFinished()), wt, SLOT(quit()));
	QObject::connect(wt, SIGNAL(finished()), wt, SLOT(deleteLater()));

	qInfo() << "Loading print handler!";
	PrintHandler ph;

	if (wt != nullptr) {
		qDebug() << "Starting worker!";
		wt->start();
	}

	qDebug() << "Starting print handler!";
	ph.run();

	QObject::connect(&ui, &AquaPrinter::getInfo, &w, &Worker::getInfo);
	QObject::connect(&ui, &AquaPrinter::printInfo, &ph, &PrintHandler::printInfo);
	QObject::connect(&w, &Worker::haveInfo, &ui, &AquaPrinter::haveInfo);
	QObject::connect(&w, &Worker::mssqlStateChanged, &ui, &AquaPrinter::mssqlStateChanged);
	QObject::connect(&w, &Worker::fbsqllStateChanged, &ui, &AquaPrinter::fbsqllStateChanged);
	QObject::connect(&w, &Worker::updateProgressBar, &ui, &AquaPrinter::updateProgressBar);

	ui.showMaximized();
	// read password
	bool ready = false;
	while (!ready)
	{
		bool ok;
		QString text = QInputDialog::getText(&ui, QObject::tr("Внимание!"), QObject::tr("Введите пароль:"), QLineEdit::Normal, QDir::home().dirName(), &ok);
		qint64 hash = qHash(text);
		if (ok && hash == Settings::i()->pass)
			ready = true;
	}
	return a.exec();
}
