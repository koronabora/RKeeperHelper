// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "PrintHandler.h"

PrintHandler::PrintHandler()
{}

PrintHandler::~PrintHandler()
{
	emit workFinished();
}

QString PrintHandler::fNum(qint64 num)
{
	QString src = QString::number(num);
	QString res;
	if (src.size() > 0)
		for (quint64 i = 0; i < src.size(); i++)
		{
			if ((src.size() - i) % 3 == 0)
				res.append(' ');
			res.append(src.at(i));
		}

	return res;
}

void PrintHandler::printInfo(AllData s)
{
	QPrinter printer;
	QPrintDialog dialog(&printer);
	dialog.setWindowTitle(tr("Печать отчета"));
	dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
	if (dialog.exec() != QDialog::Accepted) {
		return;
	}
	else
	{
		QPainter painter(&printer); // create a painter which will paint 'on printer'.
		QFont font = QFont(Settings::i()->printFont, Settings::i()->printFontSize + 2);
		painter.setFont(font);
		qint64 lineWrap = Settings::i()->printVerticalLineWrap;
		qint64 lineShift = Settings::i()->printVerticalLineShift;
		QString caption = tr("Отчет за ") + s.date.toString(Settings::i()->dateFormat);
		qreal lX = printer.pageRect().width() / (Settings::i()->printDTx * 1.0);
		qreal lY = printer.pageRect().height() / (Settings::i()->printDTy * 1.0);
		qreal capSize = lX*caption.size();
		qint64 k = 0;
		painter.drawText(printer.pageRect().width() / 2 - capSize / 2, (lineShift + lineWrap*(k++))*lY, caption);
		k++;
		font.setPointSize(Settings::i()->printFontSize);
		painter.setFont(font);

		if (s.blueAll == s.blueAllOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Общий приход синий ресепшн: " + fNum(s.blueAll));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Общий приход синий ресепшн: " + fNum(s.blueAll) + " (" + Settings::i()->uiOrigionalText + fNum(s.blueAllOrig) + ")");

		font.setBold(true);
		painter.setFont(font);
		if (s.blueCash == s.blueCashOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Из них наличными: " + fNum(s.blueCash));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Из них наличными: " + fNum(s.blueCash) + " (" + Settings::i()->uiOrigionalText + fNum(s.blueCashOrig) + ")");
		font.setBold(false);
		painter.setFont(font);

		if (s.blueCard == s.blueCardOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Картами: " + fNum(s.blueCard));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Картами: " + fNum(s.blueCard) + " (" + Settings::i()->uiOrigionalText + fNum(s.blueCardOrig) + ")");

		k++;
		if (s.whiteAll == s.whiteAllOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Общий приход белый ресепшн: ") + fNum(s.whiteAll));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Общий приход белый ресепшн: ") + fNum(s.whiteAll) + " (" + Settings::i()->uiOrigionalText + fNum(s.whiteAllOrig) + ")");

		font.setBold(true);
		painter.setFont(font);
		if (s.whiteCash == s.whiteCashOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Из них наличными: ") + fNum(s.whiteCash));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Из них наличными: ") + fNum(s.whiteCash) + " (" + Settings::i()->uiOrigionalText + fNum(s.whiteCashOrig) + ")");
		font.setBold(false);
		painter.setFont(font);

		if (s.whiteCard == s.whiteCardOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами: ") + fNum(s.whiteCard));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами: ") + fNum(s.whiteCard) + " (" + Settings::i()->uiOrigionalText + fNum(s.whiteCardOrig) + ")");

		k++;
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Браслетов: ") + fNum(s.allKeysCount));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Посетителей: ") + fNum(s.allVisitorsCount));
		k++;
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными входных: ") + fNum(s.cashIn));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными размещение гостей: ") + fNum(s.cashSit));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными питание:  ") + fNum(s.cashFood));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными за номера гостиницы: ") + fNum(s.cashHotel));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными доп. услуги: ") + fNum(s.cashAdditionalServices));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Неплательщики ") + fNum(s.cashInvaders));
		k++;
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами входных: ") + fNum(s.cardIn));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами размещение гостей: ") + fNum(s.cardSit));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами питание:  ") + fNum(s.cardFood));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами за номера гостиницы: ") + fNum(s.cardHotel));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами доп. услуги: ") + fNum(s.cardAdditionalServices));
		k++;
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Инкассированно в банк: ") + fNum(s.cashToBank));
		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Итог наличными: ") + fNum(s.finalCash));
		font.setBold(false);
		painter.setFont(font);

		QString info = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
		painter.drawText(printer.pageRect().width() - lX*info.size(), printer.pageRect().height() - lY, info);

		painter.end();
	}
}

void PrintHandler::run()
{

}
