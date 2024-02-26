/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit {
 public:
  QGridLayout *gridLayout_3;
  QGridLayout *gridLayout_2;
  QLabel *label_6;
  QLabel *label_total_sum;
  QLabel *label_overpayment;
  QLabel *label_7;
  QLabel *label_10;
  QLabel *label_month_pay;
  QGridLayout *gridLayout;
  QLineEdit *lineEdit_amount;
  QLabel *label_4;
  QLineEdit *lineEdit_rate;
  QLabel *label_2;
  QComboBox *comboBox_type;
  QLabel *label;
  QLabel *label_3;
  QComboBox *comboBox_timeframe;
  QPushButton *pushButton_calculate;

  void setupUi(QWidget *Credit) {
    if (Credit->objectName().isEmpty()) Credit->setObjectName("Credit");
    Credit->resize(568, 416);
    gridLayout_3 = new QGridLayout(Credit);
    gridLayout_3->setObjectName("gridLayout_3");
    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName("gridLayout_2");
    gridLayout_2->setHorizontalSpacing(200);
    label_6 = new QLabel(Credit);
    label_6->setObjectName("label_6");

    gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

    label_total_sum = new QLabel(Credit);
    label_total_sum->setObjectName("label_total_sum");

    gridLayout_2->addWidget(label_total_sum, 2, 1, 1, 1);

    label_overpayment = new QLabel(Credit);
    label_overpayment->setObjectName("label_overpayment");

    gridLayout_2->addWidget(label_overpayment, 1, 1, 1, 1);

    label_7 = new QLabel(Credit);
    label_7->setObjectName("label_7");

    gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

    label_10 = new QLabel(Credit);
    label_10->setObjectName("label_10");

    gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

    label_month_pay = new QLabel(Credit);
    label_month_pay->setObjectName("label_month_pay");

    gridLayout_2->addWidget(label_month_pay, 0, 1, 1, 1);

    gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName("gridLayout");
    lineEdit_amount = new QLineEdit(Credit);
    lineEdit_amount->setObjectName("lineEdit_amount");

    gridLayout->addWidget(lineEdit_amount, 0, 1, 1, 1);

    label_4 = new QLabel(Credit);
    label_4->setObjectName("label_4");

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    lineEdit_rate = new QLineEdit(Credit);
    lineEdit_rate->setObjectName("lineEdit_rate");

    gridLayout->addWidget(lineEdit_rate, 1, 1, 1, 1);

    label_2 = new QLabel(Credit);
    label_2->setObjectName("label_2");

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    comboBox_type = new QComboBox(Credit);
    comboBox_type->addItem(QString());
    comboBox_type->addItem(QString());
    comboBox_type->setObjectName("comboBox_type");

    gridLayout->addWidget(comboBox_type, 3, 1, 1, 1);

    label = new QLabel(Credit);
    label->setObjectName("label");

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_3 = new QLabel(Credit);
    label_3->setObjectName("label_3");

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    comboBox_timeframe = new QComboBox(Credit);
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->addItem(QString());
    comboBox_timeframe->setObjectName("comboBox_timeframe");

    gridLayout->addWidget(comboBox_timeframe, 2, 1, 1, 1);

    pushButton_calculate = new QPushButton(Credit);
    pushButton_calculate->setObjectName("pushButton_calculate");

    gridLayout->addWidget(pushButton_calculate, 4, 0, 1, 2);

    gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

    retranslateUi(Credit);

    comboBox_timeframe->setCurrentIndex(6);

    QMetaObject::connectSlotsByName(Credit);
  }  // setupUi

  void retranslateUi(QWidget *Credit) {
    Credit->setWindowTitle(
        QCoreApplication::translate("Credit", "Form", nullptr));
    label_6->setText(
        QCoreApplication::translate("Credit", "Overpayment", nullptr));
    label_total_sum->setText(
        QCoreApplication::translate("Credit", "0", nullptr));
    label_overpayment->setText(
        QCoreApplication::translate("Credit", "0", nullptr));
    label_7->setText(
        QCoreApplication::translate("Credit", "Total sum", nullptr));
    label_10->setText(
        QCoreApplication::translate("Credit", "Mothly payment", nullptr));
    label_month_pay->setText(
        QCoreApplication::translate("Credit", "0", nullptr));
    lineEdit_amount->setText(
        QCoreApplication::translate("Credit", "100000", nullptr));
    label_4->setText(QCoreApplication::translate("Credit", "Type", nullptr));
    lineEdit_rate->setText(
        QCoreApplication::translate("Credit", "12", nullptr));
    label_2->setText(QCoreApplication::translate("Credit", "Rate, %", nullptr));
    comboBox_type->setItemText(
        0, QCoreApplication::translate("Credit", "Annuity", nullptr));
    comboBox_type->setItemText(
        1, QCoreApplication::translate("Credit", "Differentaited", nullptr));

    label->setText(QCoreApplication::translate("Credit", "Amount", nullptr));
    label_3->setText(
        QCoreApplication::translate("Credit", "Timeframe", nullptr));
    comboBox_timeframe->setItemText(
        0, QCoreApplication::translate("Credit", "1 month", nullptr));
    comboBox_timeframe->setItemText(
        1, QCoreApplication::translate("Credit", "3 month", nullptr));
    comboBox_timeframe->setItemText(
        2, QCoreApplication::translate("Credit", "6 month", nullptr));
    comboBox_timeframe->setItemText(
        3, QCoreApplication::translate("Credit", "9 month", nullptr));
    comboBox_timeframe->setItemText(
        4, QCoreApplication::translate("Credit", "1 year", nullptr));
    comboBox_timeframe->setItemText(
        5, QCoreApplication::translate("Credit", "1.5 year", nullptr));
    comboBox_timeframe->setItemText(
        6, QCoreApplication::translate("Credit", "2 year", nullptr));
    comboBox_timeframe->setItemText(
        7, QCoreApplication::translate("Credit", "3 year", nullptr));
    comboBox_timeframe->setItemText(
        8, QCoreApplication::translate("Credit", "4 year", nullptr));
    comboBox_timeframe->setItemText(
        9, QCoreApplication::translate("Credit", "5 year", nullptr));
    comboBox_timeframe->setItemText(
        10, QCoreApplication::translate("Credit", "6 year", nullptr));
    comboBox_timeframe->setItemText(
        11, QCoreApplication::translate("Credit", "7 year", nullptr));
    comboBox_timeframe->setItemText(
        12, QCoreApplication::translate("Credit", "10 year", nullptr));
    comboBox_timeframe->setItemText(
        13, QCoreApplication::translate("Credit", "15 year", nullptr));
    comboBox_timeframe->setItemText(
        14, QCoreApplication::translate("Credit", "20 year", nullptr));
    comboBox_timeframe->setItemText(
        15, QCoreApplication::translate("Credit", "25 year", nullptr));
    comboBox_timeframe->setItemText(
        16, QCoreApplication::translate("Credit", "30 year", nullptr));

    pushButton_calculate->setText(
        QCoreApplication::translate("Credit", "Calculate", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Credit : public Ui_Credit {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_CREDIT_H
