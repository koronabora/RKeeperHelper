/********************************************************************************
** Form generated from reading UI file 'PasswordGenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDGENERATOR_H
#define UI_PASSWORDGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordGeneratorClass
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *pass;
    QLabel *label_2;
    QLineEdit *hash;

    void setupUi(QMainWindow *PasswordGeneratorClass)
    {
        if (PasswordGeneratorClass->objectName().isEmpty())
            PasswordGeneratorClass->setObjectName(QStringLiteral("PasswordGeneratorClass"));
        PasswordGeneratorClass->resize(600, 85);
        QIcon icon;
        icon.addFile(QStringLiteral(":/iconpg.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PasswordGeneratorClass->setWindowIcon(icon);
        centralWidget = new QWidget(PasswordGeneratorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pass = new QLineEdit(centralWidget);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, pass);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        hash = new QLineEdit(centralWidget);
        hash->setObjectName(QStringLiteral("hash"));
        hash->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, hash);

        PasswordGeneratorClass->setCentralWidget(centralWidget);

        retranslateUi(PasswordGeneratorClass);

        QMetaObject::connectSlotsByName(PasswordGeneratorClass);
    } // setupUi

    void retranslateUi(QMainWindow *PasswordGeneratorClass)
    {
        PasswordGeneratorClass->setWindowTitle(QApplication::translate("PasswordGeneratorClass", "PasswordGenerator", Q_NULLPTR));
        label->setText(QApplication::translate("PasswordGeneratorClass", "\320\237\320\260\321\200\320\276\320\273\321\214:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PasswordGeneratorClass", "\320\245\321\215\321\210:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PasswordGeneratorClass: public Ui_PasswordGeneratorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDGENERATOR_H
