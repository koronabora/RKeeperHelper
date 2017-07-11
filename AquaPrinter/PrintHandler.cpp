// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "PrintHandler.h"

PrintHandler::PrintHandler()
{}

PrintHandler::~PrintHandler()
{
	emit workFinished();
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
		QFont font = QFont(Settings::i()->printFont, Settings::i()->printFontSize + 4);
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

		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Синий ресепшн:");
		if (s.blueCash == s.blueCashOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Наличными: " + Settings::fNum(s.blueCash));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Наличными: " + Settings::fNum(s.blueCash) + " (" + Settings::i()->uiOrigionalText + Settings::fNum(s.blueCashOrig) + ")");
		font.setBold(false);
		painter.setFont(font);
		if (s.blueCard == s.blueCardOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Картами: " + Settings::fNum(s.blueCard));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Картами: " + Settings::fNum(s.blueCard) + " (" + Settings::i()->uiOrigionalText + Settings::fNum(s.blueCardOrig) + ")");

		if (s.blueAll == s.blueAllOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Общий приход: " + Settings::fNum(s.blueAll));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Общий приход: " + Settings::fNum(s.blueAll) + " (" + Settings::i()->uiOrigionalText + Settings::fNum(s.blueAllOrig) + ")");

		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Скидки и отмены: " + Settings::fNum(s.blueDisc));

		k++;
		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Белый ресепшн:");
		if (s.whiteCash == s.whiteCashOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными: ") + Settings::fNum(s.whiteCash));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Наличными: ") + Settings::fNum(s.whiteCash) + " (" + Settings::i()->uiOrigionalText + Settings::fNum(s.whiteCashOrig) + ")");
		font.setBold(false);
		painter.setFont(font);

		if (s.whiteCard == s.whiteCardOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами: ") + Settings::fNum(s.whiteCard));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Картами: ") + Settings::fNum(s.whiteCard) + " (" + Settings::i()->uiOrigionalText + Settings::fNum(s.whiteCardOrig) + ")");
		if (s.whiteAll == s.whiteAllOrig)
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Общий приход: ") + Settings::fNum(s.whiteAll));
		else
			painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Общий приход: ") + Settings::fNum(s.whiteAll) + " (" + Settings::i()->uiOrigionalText + Settings::fNum(s.whiteAllOrig) + ")");
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, "Скидки и отмены: " + Settings::fNum(s.whiteDisc));
		k++;
		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Посетители:"));
		font.setBold(false);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Браслетов: ") + Settings::fNum(s.allKeysCount));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Посетителей: ") + Settings::fNum(s.allVisitorsCount));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Из них VIP: ")+Settings::fNum(s.vipVisitors));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Неоткрепленных браслетов: ") + Settings::fNum(s.lostFolios.size()));
		k++;
		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Разделение:"));
		font.setBold(false);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За вход (A): ") + Settings::fNum(s.allIn));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За размещение гостей (R): ") + Settings::fNum(s.allSit));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За питание (R): ") + Settings::fNum(s.allFood));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За бар (R): ") + Settings::fNum(s.allBar));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За за номера гостиницы (R): ") + Settings::fNum(s.allHotel));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За бани и сауны (R): ") + Settings::fNum(s.allBath));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("За кальяны (R): ") + Settings::fNum(s.allHookah));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Прочие услуги (R): ") + Settings::fNum(s.allAdditionalServices));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("С предыдущего дня (R): ") + Settings::fNum(s.diffFromPrevDay));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Неплательщики (R): ") + Settings::fNum(s.allInvaders));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Скидки (R): ") + Settings::fNum(s.allDiscounts));
		k++;
		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Итоги:"));
		font.setBold(false);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Приход в инкассацию с предыдущего дня: ") + Settings::fNum(s.cashToBankPrev));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Инкассированно за день: ") + Settings::fNum(s.cashToBank));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Всего поступило в банк: ") + Settings::fNum(s.finalBank));
		font.setBold(true);
		painter.setFont(font);
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Расход по актам: ") + Settings::fNum(s.writeOffs));
		painter.drawText(Settings::i()->printHorizontalLineShift*lX, (lineShift + lineWrap*(k++))*lY, tr("Итог наличными: ") + Settings::fNum(s.finalCash));
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
