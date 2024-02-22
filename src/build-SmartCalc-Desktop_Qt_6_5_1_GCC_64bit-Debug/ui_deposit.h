/********************************************************************************
** Form generated from reading UI file 'deposit.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_H
#define UI_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deposit
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_rate;
    QComboBox *comboBox_frequency;
    QLabel *label;
    QLineEdit *lineEdit_tax;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *lineEdit_amount;
    QComboBox *comboBox_timeframe;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QDateEdit *dateEdit_elim;
    QLineEdit *lineEdit_supp;
    QDateEdit *dateEdit_supp;
    QComboBox *comboBox_supp;
    QCheckBox *checkBox_supplementions;
    QCheckBox *checkBox_eliminations;
    QLineEdit *lineEdit_elim;
    QComboBox *comboBox_elim;
    QPushButton *pushButton_calculate;
    QCheckBox *checkBox_capitalization;
    QGridLayout *gridLayout_3;
    QLabel *label_procent;
    QLabel *label_9;
    QLabel *label_tax;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_total;
    QLabel *label_7;

    void setupUi(QWidget *Deposit)
    {
        if (Deposit->objectName().isEmpty())
            Deposit->setObjectName("Deposit");
        Deposit->resize(686, 425);
        gridLayout_4 = new QGridLayout(Deposit);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_3 = new QLabel(Deposit);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_rate = new QLineEdit(Deposit);
        lineEdit_rate->setObjectName("lineEdit_rate");

        gridLayout_2->addWidget(lineEdit_rate, 2, 1, 1, 1);

        comboBox_frequency = new QComboBox(Deposit);
        comboBox_frequency->setObjectName("comboBox_frequency");

        gridLayout_2->addWidget(comboBox_frequency, 4, 1, 1, 1);

        label = new QLabel(Deposit);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        lineEdit_tax = new QLineEdit(Deposit);
        lineEdit_tax->setObjectName("lineEdit_tax");

        gridLayout_2->addWidget(lineEdit_tax, 3, 1, 1, 1);

        label_5 = new QLabel(Deposit);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_2 = new QLabel(Deposit);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_amount = new QLineEdit(Deposit);
        lineEdit_amount->setObjectName("lineEdit_amount");

        gridLayout_2->addWidget(lineEdit_amount, 0, 1, 1, 1);

        comboBox_timeframe = new QComboBox(Deposit);
        comboBox_timeframe->setObjectName("comboBox_timeframe");

        gridLayout_2->addWidget(comboBox_timeframe, 1, 1, 1, 1);

        label_4 = new QLabel(Deposit);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        dateEdit_elim = new QDateEdit(Deposit);
        dateEdit_elim->setObjectName("dateEdit_elim");

        gridLayout->addWidget(dateEdit_elim, 3, 2, 1, 1);

        lineEdit_supp = new QLineEdit(Deposit);
        lineEdit_supp->setObjectName("lineEdit_supp");

        gridLayout->addWidget(lineEdit_supp, 2, 3, 1, 1);

        dateEdit_supp = new QDateEdit(Deposit);
        dateEdit_supp->setObjectName("dateEdit_supp");

        gridLayout->addWidget(dateEdit_supp, 2, 2, 1, 1);

        comboBox_supp = new QComboBox(Deposit);
        comboBox_supp->setObjectName("comboBox_supp");

        gridLayout->addWidget(comboBox_supp, 2, 1, 1, 1);

        checkBox_supplementions = new QCheckBox(Deposit);
        checkBox_supplementions->setObjectName("checkBox_supplementions");

        gridLayout->addWidget(checkBox_supplementions, 2, 0, 1, 1);

        checkBox_eliminations = new QCheckBox(Deposit);
        checkBox_eliminations->setObjectName("checkBox_eliminations");

        gridLayout->addWidget(checkBox_eliminations, 3, 0, 1, 1);

        lineEdit_elim = new QLineEdit(Deposit);
        lineEdit_elim->setObjectName("lineEdit_elim");

        gridLayout->addWidget(lineEdit_elim, 3, 3, 1, 1);

        comboBox_elim = new QComboBox(Deposit);
        comboBox_elim->setObjectName("comboBox_elim");

        gridLayout->addWidget(comboBox_elim, 3, 1, 1, 1);

        pushButton_calculate = new QPushButton(Deposit);
        pushButton_calculate->setObjectName("pushButton_calculate");

        gridLayout->addWidget(pushButton_calculate, 4, 0, 1, 4);

        checkBox_capitalization = new QCheckBox(Deposit);
        checkBox_capitalization->setObjectName("checkBox_capitalization");

        gridLayout->addWidget(checkBox_capitalization, 1, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(70);
        label_procent = new QLabel(Deposit);
        label_procent->setObjectName("label_procent");

        gridLayout_3->addWidget(label_procent, 1, 1, 1, 1);

        label_9 = new QLabel(Deposit);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        label_tax = new QLabel(Deposit);
        label_tax->setObjectName("label_tax");

        gridLayout_3->addWidget(label_tax, 2, 1, 1, 1);

        label_10 = new QLabel(Deposit);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        label_6 = new QLabel(Deposit);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        label_total = new QLabel(Deposit);
        label_total->setObjectName("label_total");

        gridLayout_3->addWidget(label_total, 3, 1, 1, 1);

        label_7 = new QLabel(Deposit);
        label_7->setObjectName("label_7");

        gridLayout_3->addWidget(label_7, 0, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 2, 1);


        retranslateUi(Deposit);

        QMetaObject::connectSlotsByName(Deposit);
    } // setupUi

    void retranslateUi(QWidget *Deposit)
    {
        Deposit->setWindowTitle(QCoreApplication::translate("Deposit", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Deposit", "Rate", nullptr));
        label->setText(QCoreApplication::translate("Deposit", "Timeframe", nullptr));
        label_5->setText(QCoreApplication::translate("Deposit", "Frequency", nullptr));
        label_2->setText(QCoreApplication::translate("Deposit", "Amount", nullptr));
        label_4->setText(QCoreApplication::translate("Deposit", "Tax Rate", nullptr));
        checkBox_supplementions->setText(QCoreApplication::translate("Deposit", "Supplementions", nullptr));
        checkBox_eliminations->setText(QCoreApplication::translate("Deposit", "Eliminations", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("Deposit", "Calculate", nullptr));
        checkBox_capitalization->setText(QCoreApplication::translate("Deposit", "Capitalization", nullptr));
        label_procent->setText(QCoreApplication::translate("Deposit", "0", nullptr));
        label_9->setText(QCoreApplication::translate("Deposit", "Tax", nullptr));
        label_tax->setText(QCoreApplication::translate("Deposit", "0", nullptr));
        label_10->setText(QCoreApplication::translate("Deposit", "Total", nullptr));
        label_6->setText(QCoreApplication::translate("Deposit", "Accured interest", nullptr));
        label_total->setText(QCoreApplication::translate("Deposit", "0", nullptr));
        label_7->setText(QCoreApplication::translate("Deposit", "Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deposit: public Ui_Deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_H
