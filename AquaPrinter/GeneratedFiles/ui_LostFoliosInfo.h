/********************************************************************************
** Form generated from reading UI file 'LostFoliosInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSTFOLIOSINFO_H
#define UI_LOSTFOLIOSINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableWidget *mainTable;
    QPushButton *closeButton;

    void setupUi(QMainWindow *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName(QStringLiteral("Information"));
        Information->resize(638, 831);
        centralwidget = new QWidget(Information);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mainTable = new QTableWidget(centralwidget);
        mainTable->setObjectName(QStringLiteral("mainTable"));
        mainTable->setAlternatingRowColors(true);
        mainTable->setSelectionMode(QAbstractItemView::MultiSelection);
        mainTable->setSortingEnabled(true);
        mainTable->horizontalHeader()->setCascadingSectionResizes(true);
        mainTable->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(mainTable, 0, 0, 1, 1);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout->addWidget(closeButton, 1, 0, 1, 1);

        Information->setCentralWidget(centralwidget);

        retranslateUi(Information);

        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QMainWindow *Information)
    {
        Information->setWindowTitle(QApplication::translate("Information", "\320\232\320\260\321\200\321\202\321\213", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Information", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSTFOLIOSINFO_H
