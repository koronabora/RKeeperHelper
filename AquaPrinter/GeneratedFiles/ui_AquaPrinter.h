/********************************************************************************
** Form generated from reading UI file 'AquaPrinter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AQUAPRINTER_H
#define UI_AQUAPRINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AquaPrinterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QFrame *line_2;
    QLabel *label_4;
    QSpinBox *blueCashEdit;
    QLabel *blueCashOriginalLabel;
    QLabel *label_22;
    QSpinBox *blueCardEdit;
    QLabel *blueCardOriginalEdit;
    QLabel *label_3;
    QSpinBox *blueAllEdit;
    QLabel *blueOriginalLabel;
    QFrame *line_10;
    QLabel *label_18;
    QSpinBox *blueDisc;
    QFrame *line;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QFrame *line_3;
    QLabel *label_6;
    QSpinBox *whiteCashEdit;
    QLabel *whiteOriginalCashEdit;
    QLabel *label_23;
    QSpinBox *whiteCardEdit;
    QLabel *whiteCardOriginalLabel;
    QLabel *label_5;
    QSpinBox *whiteAllEdit;
    QLabel *whiteAllOriginalLabel;
    QFrame *line_11;
    QLabel *label_19;
    QSpinBox *whiteDisc;
    QFrame *frame_10;
    QGridLayout *gridLayout_3;
    QCalendarWidget *calendar;
    QFrame *line_8;
    QFrame *line_4;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QSpinBox *allKeysCount;
    QLabel *label_32;
    QSpinBox *lostFolios;
    QPushButton *lostFoliosButton;
    QFrame *line_9;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_29;
    QSpinBox *vipVisitors;
    QLabel *label_10;
    QSpinBox *allVisitorsCount;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QFrame *line_6;
    QFrame *frame_8;
    QFormLayout *formLayout;
    QLabel *label_11;
    QSpinBox *allInEdit;
    QLabel *label_12;
    QSpinBox *allSitEdit;
    QLabel *label_13;
    QSpinBox *allFoodEdit;
    QLabel *label_14;
    QSpinBox *allHotelEdit;
    QLabel *label_20;
    QSpinBox *allBathEdit;
    QLabel *label_26;
    QSpinBox *allHookahEdit;
    QLabel *label_15;
    QSpinBox *allAdditionalServicesEdit;
    QLabel *label_21;
    QSpinBox *allInvadersEdit;
    QLabel *label_16;
    QSpinBox *allDiscountsEdit;
    QLabel *label_28;
    QSpinBox *allBar;
    QLabel *label_30;
    QSpinBox *diffFromPrevDay;
    QFrame *line_5;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QFrame *line_7;
    QFrame *frame_9;
    QFormLayout *formLayout_2;
    QLabel *label_17;
    QSpinBox *cashToBankPrev;
    QLabel *label_24;
    QSpinBox *cashToBank;
    QFrame *line_12;
    QLabel *label_25;
    QSpinBox *finalCashe;
    QLabel *label_27;
    QSpinBox *finalBank;
    QLabel *label_31;
    QSpinBox *writeOffs;
    QPushButton *printButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AquaPrinterClass)
    {
        if (AquaPrinterClass->objectName().isEmpty())
            AquaPrinterClass->setObjectName(QStringLiteral("AquaPrinterClass"));
        AquaPrinterClass->resize(1340, 1363);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AquaPrinterClass->setWindowIcon(icon);
        centralWidget = new QWidget(AquaPrinterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        line_2 = new QFrame(frame_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_4);

        blueCashEdit = new QSpinBox(frame_3);
        blueCashEdit->setObjectName(QStringLiteral("blueCashEdit"));
        blueCashEdit->setProperty("showGroupSeparator", QVariant(true));
        blueCashEdit->setMinimum(-999999999);
        blueCashEdit->setMaximum(999999999);

        verticalLayout_2->addWidget(blueCashEdit);

        blueCashOriginalLabel = new QLabel(frame_3);
        blueCashOriginalLabel->setObjectName(QStringLiteral("blueCashOriginalLabel"));
        blueCashOriginalLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(blueCashOriginalLabel);

        label_22 = new QLabel(frame_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_22);

        blueCardEdit = new QSpinBox(frame_3);
        blueCardEdit->setObjectName(QStringLiteral("blueCardEdit"));
        blueCardEdit->setProperty("showGroupSeparator", QVariant(true));
        blueCardEdit->setMinimum(-999999999);
        blueCardEdit->setMaximum(999999999);

        verticalLayout_2->addWidget(blueCardEdit);

        blueCardOriginalEdit = new QLabel(frame_3);
        blueCardOriginalEdit->setObjectName(QStringLiteral("blueCardOriginalEdit"));
        blueCardOriginalEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(blueCardOriginalEdit);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_3);

        blueAllEdit = new QSpinBox(frame_3);
        blueAllEdit->setObjectName(QStringLiteral("blueAllEdit"));
        blueAllEdit->setReadOnly(true);
        blueAllEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        blueAllEdit->setProperty("showGroupSeparator", QVariant(true));
        blueAllEdit->setMinimum(-999999999);
        blueAllEdit->setMaximum(999999999);

        verticalLayout_2->addWidget(blueAllEdit);

        blueOriginalLabel = new QLabel(frame_3);
        blueOriginalLabel->setObjectName(QStringLiteral("blueOriginalLabel"));
        blueOriginalLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(blueOriginalLabel);

        line_10 = new QFrame(frame_3);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_10);

        label_18 = new QLabel(frame_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_18);

        blueDisc = new QSpinBox(frame_3);
        blueDisc->setObjectName(QStringLiteral("blueDisc"));
        blueDisc->setReadOnly(true);
        blueDisc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        blueDisc->setProperty("showGroupSeparator", QVariant(true));
        blueDisc->setMinimum(-999999999);
        blueDisc->setMaximum(999999999);

        verticalLayout_2->addWidget(blueDisc);


        horizontalLayout->addWidget(frame_3);

        line = new QFrame(frame_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        line_3 = new QFrame(frame_4);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_6);

        whiteCashEdit = new QSpinBox(frame_4);
        whiteCashEdit->setObjectName(QStringLiteral("whiteCashEdit"));
        whiteCashEdit->setProperty("showGroupSeparator", QVariant(true));
        whiteCashEdit->setMinimum(-999999999);
        whiteCashEdit->setMaximum(999999999);

        verticalLayout->addWidget(whiteCashEdit);

        whiteOriginalCashEdit = new QLabel(frame_4);
        whiteOriginalCashEdit->setObjectName(QStringLiteral("whiteOriginalCashEdit"));
        whiteOriginalCashEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(whiteOriginalCashEdit);

        label_23 = new QLabel(frame_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_23);

        whiteCardEdit = new QSpinBox(frame_4);
        whiteCardEdit->setObjectName(QStringLiteral("whiteCardEdit"));
        whiteCardEdit->setProperty("showGroupSeparator", QVariant(true));
        whiteCardEdit->setMinimum(-999999999);
        whiteCardEdit->setMaximum(999999999);

        verticalLayout->addWidget(whiteCardEdit);

        whiteCardOriginalLabel = new QLabel(frame_4);
        whiteCardOriginalLabel->setObjectName(QStringLiteral("whiteCardOriginalLabel"));
        whiteCardOriginalLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(whiteCardOriginalLabel);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_5);

        whiteAllEdit = new QSpinBox(frame_4);
        whiteAllEdit->setObjectName(QStringLiteral("whiteAllEdit"));
        whiteAllEdit->setEnabled(true);
        whiteAllEdit->setWrapping(false);
        whiteAllEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        whiteAllEdit->setReadOnly(true);
        whiteAllEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        whiteAllEdit->setProperty("showGroupSeparator", QVariant(true));
        whiteAllEdit->setMinimum(-999999999);
        whiteAllEdit->setMaximum(999999999);

        verticalLayout->addWidget(whiteAllEdit);

        whiteAllOriginalLabel = new QLabel(frame_4);
        whiteAllOriginalLabel->setObjectName(QStringLiteral("whiteAllOriginalLabel"));
        whiteAllOriginalLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(whiteAllOriginalLabel);

        line_11 = new QFrame(frame_4);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_11);

        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_19);

        whiteDisc = new QSpinBox(frame_4);
        whiteDisc->setObjectName(QStringLiteral("whiteDisc"));
        whiteDisc->setReadOnly(true);
        whiteDisc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        whiteDisc->setProperty("showGroupSeparator", QVariant(true));
        whiteDisc->setMinimum(-999999999);
        whiteDisc->setMaximum(999999999);

        verticalLayout->addWidget(whiteDisc);


        horizontalLayout->addWidget(frame_4);


        gridLayout->addWidget(frame_2, 0, 2, 1, 1);

        frame_10 = new QFrame(frame);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setMinimumSize(QSize(0, 0));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_10);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        calendar = new QCalendarWidget(frame_10);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setMaximumSize(QSize(16777215, 400));
        calendar->setGridVisible(true);
        calendar->setNavigationBarVisible(true);
        calendar->setDateEditEnabled(true);

        gridLayout_3->addWidget(calendar, 0, 0, 1, 1);


        gridLayout->addWidget(frame_10, 0, 0, 1, 2);

        line_8 = new QFrame(frame);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setMinimumSize(QSize(0, 0));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 5, 0, 1, 3);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setMinimumSize(QSize(0, 0));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 3, 0, 1, 3);

        frame_11 = new QFrame(frame);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_11);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frame_12 = new QFrame(frame_11);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_12);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(frame_12);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(150, 16777215));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_9);

        allKeysCount = new QSpinBox(frame_12);
        allKeysCount->setObjectName(QStringLiteral("allKeysCount"));
        allKeysCount->setMaximumSize(QSize(100, 16777215));
        allKeysCount->setReadOnly(true);
        allKeysCount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allKeysCount->setProperty("showGroupSeparator", QVariant(true));
        allKeysCount->setMinimum(-999999999);
        allKeysCount->setMaximum(999999999);

        horizontalLayout_3->addWidget(allKeysCount);

        label_32 = new QLabel(frame_12);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(label_32);

        lostFolios = new QSpinBox(frame_12);
        lostFolios->setObjectName(QStringLiteral("lostFolios"));
        lostFolios->setMaximumSize(QSize(100, 16777215));
        lostFolios->setReadOnly(true);
        lostFolios->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lostFolios->setProperty("showGroupSeparator", QVariant(true));
        lostFolios->setMaximum(9999999);

        horizontalLayout_3->addWidget(lostFolios);

        lostFoliosButton = new QPushButton(frame_12);
        lostFoliosButton->setObjectName(QStringLiteral("lostFoliosButton"));
        lostFoliosButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_3->addWidget(lostFoliosButton);


        horizontalLayout_5->addWidget(frame_12);

        line_9 = new QFrame(frame_11);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_9);

        frame_13 = new QFrame(frame_11);
        frame_13->setObjectName(QStringLiteral("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_13);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_29 = new QLabel(frame_13);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setMaximumSize(QSize(50, 16777215));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_29);

        vipVisitors = new QSpinBox(frame_13);
        vipVisitors->setObjectName(QStringLiteral("vipVisitors"));
        vipVisitors->setMaximumSize(QSize(100, 16777215));
        vipVisitors->setMaximum(999);

        horizontalLayout_4->addWidget(vipVisitors);

        label_10 = new QLabel(frame_13);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(200, 16777215));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_10);

        allVisitorsCount = new QSpinBox(frame_13);
        allVisitorsCount->setObjectName(QStringLiteral("allVisitorsCount"));
        allVisitorsCount->setMaximumSize(QSize(100, 16777215));
        allVisitorsCount->setReadOnly(true);
        allVisitorsCount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allVisitorsCount->setProperty("showGroupSeparator", QVariant(true));
        allVisitorsCount->setMinimum(-999999999);
        allVisitorsCount->setMaximum(999999999);

        horizontalLayout_4->addWidget(allVisitorsCount);


        horizontalLayout_5->addWidget(frame_13);


        gridLayout->addWidget(frame_11, 4, 0, 1, 3);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(frame_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        line_6 = new QFrame(frame_6);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_6);

        frame_8 = new QFrame(frame_6);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_8);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_11 = new QLabel(frame_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_11);

        allInEdit = new QSpinBox(frame_8);
        allInEdit->setObjectName(QStringLiteral("allInEdit"));
        allInEdit->setReadOnly(true);
        allInEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allInEdit->setProperty("showGroupSeparator", QVariant(true));
        allInEdit->setMinimum(-999999999);
        allInEdit->setMaximum(999999999);

        formLayout->setWidget(0, QFormLayout::FieldRole, allInEdit);

        label_12 = new QLabel(frame_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_12);

        allSitEdit = new QSpinBox(frame_8);
        allSitEdit->setObjectName(QStringLiteral("allSitEdit"));
        allSitEdit->setReadOnly(true);
        allSitEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allSitEdit->setProperty("showGroupSeparator", QVariant(true));
        allSitEdit->setMinimum(-999999999);
        allSitEdit->setMaximum(999999999);

        formLayout->setWidget(1, QFormLayout::FieldRole, allSitEdit);

        label_13 = new QLabel(frame_8);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        allFoodEdit = new QSpinBox(frame_8);
        allFoodEdit->setObjectName(QStringLiteral("allFoodEdit"));
        allFoodEdit->setReadOnly(true);
        allFoodEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allFoodEdit->setProperty("showGroupSeparator", QVariant(true));
        allFoodEdit->setMinimum(-999999999);
        allFoodEdit->setMaximum(999999999);

        formLayout->setWidget(2, QFormLayout::FieldRole, allFoodEdit);

        label_14 = new QLabel(frame_8);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_14);

        allHotelEdit = new QSpinBox(frame_8);
        allHotelEdit->setObjectName(QStringLiteral("allHotelEdit"));
        allHotelEdit->setReadOnly(true);
        allHotelEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allHotelEdit->setProperty("showGroupSeparator", QVariant(true));
        allHotelEdit->setMinimum(-999999999);
        allHotelEdit->setMaximum(999999999);

        formLayout->setWidget(4, QFormLayout::FieldRole, allHotelEdit);

        label_20 = new QLabel(frame_8);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_20);

        allBathEdit = new QSpinBox(frame_8);
        allBathEdit->setObjectName(QStringLiteral("allBathEdit"));
        allBathEdit->setReadOnly(true);
        allBathEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allBathEdit->setProperty("showGroupSeparator", QVariant(true));
        allBathEdit->setMinimum(-999999999);
        allBathEdit->setMaximum(999999999);

        formLayout->setWidget(5, QFormLayout::FieldRole, allBathEdit);

        label_26 = new QLabel(frame_8);
        label_26->setObjectName(QStringLiteral("label_26"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_26);

        allHookahEdit = new QSpinBox(frame_8);
        allHookahEdit->setObjectName(QStringLiteral("allHookahEdit"));
        allHookahEdit->setReadOnly(true);
        allHookahEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allHookahEdit->setProperty("showGroupSeparator", QVariant(true));
        allHookahEdit->setMinimum(-999999999);
        allHookahEdit->setMaximum(999999999);

        formLayout->setWidget(6, QFormLayout::FieldRole, allHookahEdit);

        label_15 = new QLabel(frame_8);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_15);

        allAdditionalServicesEdit = new QSpinBox(frame_8);
        allAdditionalServicesEdit->setObjectName(QStringLiteral("allAdditionalServicesEdit"));
        allAdditionalServicesEdit->setReadOnly(true);
        allAdditionalServicesEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allAdditionalServicesEdit->setProperty("showGroupSeparator", QVariant(true));
        allAdditionalServicesEdit->setMinimum(-999999999);
        allAdditionalServicesEdit->setMaximum(999999999);

        formLayout->setWidget(7, QFormLayout::FieldRole, allAdditionalServicesEdit);

        label_21 = new QLabel(frame_8);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_21);

        allInvadersEdit = new QSpinBox(frame_8);
        allInvadersEdit->setObjectName(QStringLiteral("allInvadersEdit"));
        allInvadersEdit->setReadOnly(true);
        allInvadersEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allInvadersEdit->setProperty("showGroupSeparator", QVariant(true));
        allInvadersEdit->setMinimum(-999999999);
        allInvadersEdit->setMaximum(999999999);

        formLayout->setWidget(9, QFormLayout::FieldRole, allInvadersEdit);

        label_16 = new QLabel(frame_8);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_16);

        allDiscountsEdit = new QSpinBox(frame_8);
        allDiscountsEdit->setObjectName(QStringLiteral("allDiscountsEdit"));
        allDiscountsEdit->setReadOnly(true);
        allDiscountsEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allDiscountsEdit->setProperty("showGroupSeparator", QVariant(true));
        allDiscountsEdit->setMinimum(-999999999);
        allDiscountsEdit->setMaximum(999999999);

        formLayout->setWidget(10, QFormLayout::FieldRole, allDiscountsEdit);

        label_28 = new QLabel(frame_8);
        label_28->setObjectName(QStringLiteral("label_28"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_28);

        allBar = new QSpinBox(frame_8);
        allBar->setObjectName(QStringLiteral("allBar"));
        allBar->setReadOnly(true);
        allBar->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allBar->setProperty("showGroupSeparator", QVariant(true));
        allBar->setMinimum(-999999999);
        allBar->setMaximum(999999999);

        formLayout->setWidget(3, QFormLayout::FieldRole, allBar);

        label_30 = new QLabel(frame_8);
        label_30->setObjectName(QStringLiteral("label_30"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_30);

        diffFromPrevDay = new QSpinBox(frame_8);
        diffFromPrevDay->setObjectName(QStringLiteral("diffFromPrevDay"));
        diffFromPrevDay->setReadOnly(true);
        diffFromPrevDay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diffFromPrevDay->setProperty("showGroupSeparator", QVariant(true));
        diffFromPrevDay->setMinimum(-999999999);
        diffFromPrevDay->setMaximum(999999999);

        formLayout->setWidget(8, QFormLayout::FieldRole, diffFromPrevDay);


        verticalLayout_4->addWidget(frame_8);


        horizontalLayout_2->addWidget(frame_6);

        line_5 = new QFrame(frame_5);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        frame_7 = new QFrame(frame_5);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setMinimumSize(QSize(500, 0));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_7);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_8 = new QLabel(frame_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(16777215, 20));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        line_7 = new QFrame(frame_7);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_7);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setMinimumSize(QSize(0, 0));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_9);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_17 = new QLabel(frame_9);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_17);

        cashToBankPrev = new QSpinBox(frame_9);
        cashToBankPrev->setObjectName(QStringLiteral("cashToBankPrev"));
        cashToBankPrev->setProperty("showGroupSeparator", QVariant(true));
        cashToBankPrev->setMinimum(-999999999);
        cashToBankPrev->setMaximum(999999999);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, cashToBankPrev);

        label_24 = new QLabel(frame_9);
        label_24->setObjectName(QStringLiteral("label_24"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_24);

        cashToBank = new QSpinBox(frame_9);
        cashToBank->setObjectName(QStringLiteral("cashToBank"));
        cashToBank->setProperty("showGroupSeparator", QVariant(true));
        cashToBank->setMinimum(-999999999);
        cashToBank->setMaximum(999999999);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cashToBank);

        line_12 = new QFrame(frame_9);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, line_12);

        label_25 = new QLabel(frame_9);
        label_25->setObjectName(QStringLiteral("label_25"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_25);

        finalCashe = new QSpinBox(frame_9);
        finalCashe->setObjectName(QStringLiteral("finalCashe"));
        finalCashe->setReadOnly(true);
        finalCashe->setButtonSymbols(QAbstractSpinBox::NoButtons);
        finalCashe->setProperty("showGroupSeparator", QVariant(true));
        finalCashe->setMinimum(-999999999);
        finalCashe->setMaximum(999999999);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, finalCashe);

        label_27 = new QLabel(frame_9);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_27);

        finalBank = new QSpinBox(frame_9);
        finalBank->setObjectName(QStringLiteral("finalBank"));
        finalBank->setReadOnly(true);
        finalBank->setButtonSymbols(QAbstractSpinBox::NoButtons);
        finalBank->setProperty("showGroupSeparator", QVariant(true));
        finalBank->setMinimum(-1000000009);
        finalBank->setMaximum(999999999);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, finalBank);

        label_31 = new QLabel(frame_9);
        label_31->setObjectName(QStringLiteral("label_31"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_31);

        writeOffs = new QSpinBox(frame_9);
        writeOffs->setObjectName(QStringLiteral("writeOffs"));
        writeOffs->setProperty("showGroupSeparator", QVariant(true));
        writeOffs->setMinimum(-999999999);
        writeOffs->setMaximum(999999999);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, writeOffs);


        verticalLayout_3->addWidget(frame_9);

        printButton = new QPushButton(frame_7);
        printButton->setObjectName(QStringLiteral("printButton"));

        verticalLayout_3->addWidget(printButton);


        horizontalLayout_2->addWidget(frame_7);


        gridLayout->addWidget(frame_5, 6, 0, 1, 3);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        AquaPrinterClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AquaPrinterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AquaPrinterClass->setStatusBar(statusBar);

        retranslateUi(AquaPrinterClass);

        QMetaObject::connectSlotsByName(AquaPrinterClass);
    } // setupUi

    void retranslateUi(QMainWindow *AquaPrinterClass)
    {
        AquaPrinterClass->setWindowTitle(QApplication::translate("AquaPrinterClass", "AquaPrinter", Q_NULLPTR));
        label->setText(QApplication::translate("AquaPrinterClass", "\320\241\320\270\320\275\320\270\320\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("AquaPrinterClass", "\320\235\320\260\320\273\320\270\321\207\320\275\321\213\320\274\320\270:", Q_NULLPTR));
        blueCashOriginalLabel->setText(QString());
        label_22->setText(QApplication::translate("AquaPrinterClass", "\320\232\320\260\321\200\321\202\320\260\320\274\320\270:", Q_NULLPTR));
        blueCardOriginalEdit->setText(QString());
        label_3->setText(QApplication::translate("AquaPrinterClass", "\320\222\321\201\320\265\320\263\320\276:", Q_NULLPTR));
        blueOriginalLabel->setText(QString());
        label_18->setText(QApplication::translate("AquaPrinterClass", "\320\241\320\272\320\270\320\264\320\272\320\270 \320\270 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\321\213:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AquaPrinterClass", "\320\221\320\265\320\273\321\213\320\271", Q_NULLPTR));
        label_6->setText(QApplication::translate("AquaPrinterClass", "\320\235\320\260\320\273\320\270\321\207\320\275\321\213\320\274\320\270:", Q_NULLPTR));
        whiteOriginalCashEdit->setText(QString());
        label_23->setText(QApplication::translate("AquaPrinterClass", "\320\232\320\260\321\200\321\202\320\260\320\274\320\270:", Q_NULLPTR));
        whiteCardOriginalLabel->setText(QString());
        label_5->setText(QApplication::translate("AquaPrinterClass", "\320\222\321\201\320\265\320\263\320\276:", Q_NULLPTR));
        whiteAllOriginalLabel->setText(QString());
        label_19->setText(QApplication::translate("AquaPrinterClass", "\320\241\320\272\320\270\320\264\320\272\320\270 \320\270 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\321\213:", Q_NULLPTR));
        label_9->setText(QApplication::translate("AquaPrinterClass", "\320\222\321\201\320\265\320\263\320\276 \320\261\321\200\320\260\321\201\320\273\320\265\321\202\320\276\320\262:", Q_NULLPTR));
        label_32->setText(QApplication::translate("AquaPrinterClass", "\320\237\320\276\321\202\320\265\321\200\321\217\320\275\321\213\321\205 \320\267\320\260\320\272\320\260\320\267\320\276\320\262:", Q_NULLPTR));
        lostFoliosButton->setText(QApplication::translate("AquaPrinterClass", "...", Q_NULLPTR));
        label_29->setText(QApplication::translate("AquaPrinterClass", "VIP:", Q_NULLPTR));
        label_10->setText(QApplication::translate("AquaPrinterClass", "\320\222\321\201\320\265\320\263\320\276 \320\277\320\276\321\201\321\202\320\265\321\202\320\270\321\202\320\265\320\273\320\265\320\271:", Q_NULLPTR));
        label_7->setText(QApplication::translate("AquaPrinterClass", "\320\240\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265:", Q_NULLPTR));
        label_11->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \320\262\321\205\320\276\320\264 \320\275\320\260\320\273\320\270\321\207\320\275\321\213\320\274\320\270 (A):", Q_NULLPTR));
        label_12->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\262\321\201\320\265\320\263\320\276 (R):", Q_NULLPTR));
        label_13->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \320\272\321\203\321\205\320\275\321\216 \320\262\321\201\320\265\320\263\320\276 (R):", Q_NULLPTR));
        label_14->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \320\276\321\202\320\265\320\273\321\214 \320\262\321\201\320\265\320\263\320\276 (R):", Q_NULLPTR));
        label_20->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \320\261\320\260\320\275\320\270 \320\270 \321\201\320\260\321\203\320\275\321\213 \320\262\321\201\320\265\320\263\320\276 (R):", Q_NULLPTR));
        label_26->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \320\272\320\260\320\273\321\214\321\217\320\275\321\213 \320\262\321\201\320\265\320\263\320\276 (R):", Q_NULLPTR));
        label_15->setText(QApplication::translate("AquaPrinterClass", "\320\236\321\201\321\202\320\260\320\273\321\214\320\275\320\276\320\265 (R):", Q_NULLPTR));
        label_21->setText(QApplication::translate("AquaPrinterClass", "\320\235\320\265\320\277\320\273\320\260\321\202\320\265\320\273\321\214\321\211\320\270\320\272\320\270 (R):", Q_NULLPTR));
        label_16->setText(QApplication::translate("AquaPrinterClass", "\320\241\320\272\320\270\320\264\320\272\320\270 (R):", Q_NULLPTR));
        label_28->setText(QApplication::translate("AquaPrinterClass", "\320\227\320\260 \320\261\320\260\321\200 (R):", Q_NULLPTR));
        label_30->setText(QApplication::translate("AquaPrinterClass", "\320\241 \320\277\321\200\320\276\321\210\320\273\320\276\320\263\320\276 \320\264\320\275\321\217 (R):", Q_NULLPTR));
        label_8->setText(QApplication::translate("AquaPrinterClass", "\320\230\321\202\320\276\320\263\320\270:", Q_NULLPTR));
        label_17->setText(QApplication::translate("AquaPrinterClass", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\276\321\201\321\202\320\260\321\202\320\276\320\272:", Q_NULLPTR));
        label_24->setText(QApplication::translate("AquaPrinterClass", "\320\230\320\275\320\272\320\260\321\201\321\201\320\260\321\206\320\270\321\217:", Q_NULLPTR));
        label_25->setText(QApplication::translate("AquaPrinterClass", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272 \320\275\320\260\320\273\320\270\321\207\320\275\321\213\321\205:", Q_NULLPTR));
        label_27->setText(QApplication::translate("AquaPrinterClass", "\320\222\321\201\320\265\320\263\320\276 \320\262 \320\261\320\260\320\275\320\272:", Q_NULLPTR));
        label_31->setText(QApplication::translate("AquaPrinterClass", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213 \320\277\320\276 \320\260\320\272\321\202\320\260\320\274:", Q_NULLPTR));
        printButton->setText(QApplication::translate("AquaPrinterClass", "\320\237\320\265\321\207\320\260\321\202\321\214!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AquaPrinterClass: public Ui_AquaPrinterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AQUAPRINTER_H
