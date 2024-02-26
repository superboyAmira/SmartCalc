/********************************************************************************
** Form generated from reading UI file 'calc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALC_H
#define UI_CALC_H

#include <qcustomplot.h>

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calc {
 public:
  QWidget *centralwidget;
  QGridLayout *gridLayout_2;
  QCustomPlot *widget_graph;
  QGridLayout *gridLayout;
  QPushButton *pushButton_tan;
  QPushButton *pushButton_0;
  QPushButton *pushButton_draw_graph;
  QDoubleSpinBox *doubleSpinBox_x_min;
  QPushButton *pushButton_Deposit;
  QPushButton *pushButton_3;
  QPushButton *pushButton_atan;
  QPushButton *pushButton_equal_sign;
  QDoubleSpinBox *doubleSpinBox_y_max;
  QPushButton *pushButton_acos;
  QPushButton *pushButton_2;
  QPushButton *pushButton_plus;
  QPushButton *pushButton_7;
  QPushButton *pushButton_x;
  QPushButton *pushButton_cos;
  QDoubleSpinBox *doubleSpinBox_y_min;
  QPushButton *pushButton_9;
  QPushButton *pushButton_sqrt;
  QPushButton *pushButton_minus;
  QLabel *label_y_max;
  QPushButton *pushButton_bracket_open;
  QPushButton *pushButton_bracket_close;
  QPushButton *pushButton_4;
  QDoubleSpinBox *doubleSpinBox_x_max;
  QPushButton *pushButton_8;
  QPushButton *pushButton_1;
  QPushButton *pushButton_mul;
  QPushButton *pushButton_asin;
  QCheckBox *checkBox_x;
  QPushButton *pushButton_log;
  QPushButton *pushButton_credit;
  QPushButton *pushButton_clear;
  QLabel *label_x_max;
  QPushButton *pushButton_un_minus;
  QLabel *label_x_min;
  QPushButton *pushButton_mod;
  QPushButton *pushButton_ln;
  QLabel *label_y_min;
  QPushButton *pushButton_dot;
  QPushButton *pushButton_scale;
  QPushButton *pushButton_del;
  QPushButton *pushButton_6;
  QDoubleSpinBox *doubleSpinBox_x;
  QPushButton *pushButton_5;
  QPushButton *pushButton_sin;
  QLabel *label_equation;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *Calc) {
    if (Calc->objectName().isEmpty()) Calc->setObjectName("Calc");
    Calc->resize(1102, 777);
    centralwidget = new QWidget(Calc);
    centralwidget->setObjectName("centralwidget");
    gridLayout_2 = new QGridLayout(centralwidget);
    gridLayout_2->setObjectName("gridLayout_2");
    widget_graph = new QCustomPlot(centralwidget);
    widget_graph->setObjectName("widget_graph");
    QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding,
                           QSizePolicy::Policy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(
        widget_graph->sizePolicy().hasHeightForWidth());
    widget_graph->setSizePolicy(sizePolicy);
    widget_graph->setStyleSheet(
        QString::fromUtf8("background-color: rgb(246, 245, 244);"));

    gridLayout_2->addWidget(widget_graph, 1, 1, 1, 1);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName("gridLayout");
    pushButton_tan = new QPushButton(centralwidget);
    pushButton_tan->setObjectName("pushButton_tan");

    gridLayout->addWidget(pushButton_tan, 3, 2, 1, 1);

    pushButton_0 = new QPushButton(centralwidget);
    pushButton_0->setObjectName("pushButton_0");

    gridLayout->addWidget(pushButton_0, 6, 3, 1, 2);

    pushButton_draw_graph = new QPushButton(centralwidget);
    pushButton_draw_graph->setObjectName("pushButton_draw_graph");

    gridLayout->addWidget(pushButton_draw_graph, 0, 4, 1, 1);

    doubleSpinBox_x_min = new QDoubleSpinBox(centralwidget);
    doubleSpinBox_x_min->setObjectName("doubleSpinBox_x_min");
    doubleSpinBox_x_min->setMinimum(-1000000.000000000000000);
    doubleSpinBox_x_min->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_x_min, 0, 1, 1, 1);

    pushButton_Deposit = new QPushButton(centralwidget);
    pushButton_Deposit->setObjectName("pushButton_Deposit");

    gridLayout->addWidget(pushButton_Deposit, 0, 6, 1, 1);

    pushButton_3 = new QPushButton(centralwidget);
    pushButton_3->setObjectName("pushButton_3");

    gridLayout->addWidget(pushButton_3, 3, 5, 1, 1);

    pushButton_atan = new QPushButton(centralwidget);
    pushButton_atan->setObjectName("pushButton_atan");

    gridLayout->addWidget(pushButton_atan, 4, 2, 1, 1);

    pushButton_equal_sign = new QPushButton(centralwidget);
    pushButton_equal_sign->setObjectName("pushButton_equal_sign");

    gridLayout->addWidget(pushButton_equal_sign, 6, 6, 1, 1);

    doubleSpinBox_y_max = new QDoubleSpinBox(centralwidget);
    doubleSpinBox_y_max->setObjectName("doubleSpinBox_y_max");
    doubleSpinBox_y_max->setMinimum(-1000000.000000000000000);
    doubleSpinBox_y_max->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_y_max, 1, 3, 1, 1);

    pushButton_acos = new QPushButton(centralwidget);
    pushButton_acos->setObjectName("pushButton_acos");

    gridLayout->addWidget(pushButton_acos, 4, 0, 1, 1);

    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setObjectName("pushButton_2");

    gridLayout->addWidget(pushButton_2, 3, 4, 1, 1);

    pushButton_plus = new QPushButton(centralwidget);
    pushButton_plus->setObjectName("pushButton_plus");

    gridLayout->addWidget(pushButton_plus, 5, 6, 1, 1);

    pushButton_7 = new QPushButton(centralwidget);
    pushButton_7->setObjectName("pushButton_7");

    gridLayout->addWidget(pushButton_7, 5, 3, 1, 1);

    pushButton_x = new QPushButton(centralwidget);
    pushButton_x->setObjectName("pushButton_x");

    gridLayout->addWidget(pushButton_x, 6, 2, 1, 1);

    pushButton_cos = new QPushButton(centralwidget);
    pushButton_cos->setObjectName("pushButton_cos");

    gridLayout->addWidget(pushButton_cos, 3, 0, 1, 1);

    doubleSpinBox_y_min = new QDoubleSpinBox(centralwidget);
    doubleSpinBox_y_min->setObjectName("doubleSpinBox_y_min");
    doubleSpinBox_y_min->setMinimum(-1000000.000000000000000);
    doubleSpinBox_y_min->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_y_min, 1, 1, 1, 1);

    pushButton_9 = new QPushButton(centralwidget);
    pushButton_9->setObjectName("pushButton_9");

    gridLayout->addWidget(pushButton_9, 5, 5, 1, 1);

    pushButton_sqrt = new QPushButton(centralwidget);
    pushButton_sqrt->setObjectName("pushButton_sqrt");

    gridLayout->addWidget(pushButton_sqrt, 5, 0, 1, 1);

    pushButton_minus = new QPushButton(centralwidget);
    pushButton_minus->setObjectName("pushButton_minus");

    gridLayout->addWidget(pushButton_minus, 4, 6, 1, 1);

    label_y_max = new QLabel(centralwidget);
    label_y_max->setObjectName("label_y_max");
    label_y_max->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                              Qt::AlignVCenter);

    gridLayout->addWidget(label_y_max, 1, 2, 1, 1);

    pushButton_bracket_open = new QPushButton(centralwidget);
    pushButton_bracket_open->setObjectName("pushButton_bracket_open");

    gridLayout->addWidget(pushButton_bracket_open, 2, 0, 1, 1);

    pushButton_bracket_close = new QPushButton(centralwidget);
    pushButton_bracket_close->setObjectName("pushButton_bracket_close");

    gridLayout->addWidget(pushButton_bracket_close, 2, 1, 1, 1);

    pushButton_4 = new QPushButton(centralwidget);
    pushButton_4->setObjectName("pushButton_4");

    gridLayout->addWidget(pushButton_4, 4, 3, 1, 1);

    doubleSpinBox_x_max = new QDoubleSpinBox(centralwidget);
    doubleSpinBox_x_max->setObjectName("doubleSpinBox_x_max");
    doubleSpinBox_x_max->setMinimum(-1000000.000000000000000);
    doubleSpinBox_x_max->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_x_max, 0, 3, 1, 1);

    pushButton_8 = new QPushButton(centralwidget);
    pushButton_8->setObjectName("pushButton_8");

    gridLayout->addWidget(pushButton_8, 5, 4, 1, 1);

    pushButton_1 = new QPushButton(centralwidget);
    pushButton_1->setObjectName("pushButton_1");

    gridLayout->addWidget(pushButton_1, 3, 3, 1, 1);

    pushButton_mul = new QPushButton(centralwidget);
    pushButton_mul->setObjectName("pushButton_mul");

    gridLayout->addWidget(pushButton_mul, 3, 6, 1, 1);

    pushButton_asin = new QPushButton(centralwidget);
    pushButton_asin->setObjectName("pushButton_asin");

    gridLayout->addWidget(pushButton_asin, 4, 1, 1, 1);

    checkBox_x = new QCheckBox(centralwidget);
    checkBox_x->setObjectName("checkBox_x");

    gridLayout->addWidget(checkBox_x, 6, 0, 1, 1);

    pushButton_log = new QPushButton(centralwidget);
    pushButton_log->setObjectName("pushButton_log");

    gridLayout->addWidget(pushButton_log, 5, 2, 1, 1);

    pushButton_credit = new QPushButton(centralwidget);
    pushButton_credit->setObjectName("pushButton_credit");

    gridLayout->addWidget(pushButton_credit, 0, 5, 1, 1);

    pushButton_clear = new QPushButton(centralwidget);
    pushButton_clear->setObjectName("pushButton_clear");

    gridLayout->addWidget(pushButton_clear, 2, 3, 1, 1);

    label_x_max = new QLabel(centralwidget);
    label_x_max->setObjectName("label_x_max");
    label_x_max->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                              Qt::AlignVCenter);

    gridLayout->addWidget(label_x_max, 0, 0, 1, 1);

    pushButton_un_minus = new QPushButton(centralwidget);
    pushButton_un_minus->setObjectName("pushButton_un_minus");

    gridLayout->addWidget(pushButton_un_minus, 2, 4, 1, 1);

    label_x_min = new QLabel(centralwidget);
    label_x_min->setObjectName("label_x_min");
    label_x_min->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                              Qt::AlignVCenter);

    gridLayout->addWidget(label_x_min, 0, 2, 1, 1);

    pushButton_mod = new QPushButton(centralwidget);
    pushButton_mod->setObjectName("pushButton_mod");

    gridLayout->addWidget(pushButton_mod, 2, 5, 1, 1);

    pushButton_ln = new QPushButton(centralwidget);
    pushButton_ln->setObjectName("pushButton_ln");

    gridLayout->addWidget(pushButton_ln, 5, 1, 1, 1);

    label_y_min = new QLabel(centralwidget);
    label_y_min->setObjectName("label_y_min");
    label_y_min->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                              Qt::AlignVCenter);

    gridLayout->addWidget(label_y_min, 1, 0, 1, 1);

    pushButton_dot = new QPushButton(centralwidget);
    pushButton_dot->setObjectName("pushButton_dot");

    gridLayout->addWidget(pushButton_dot, 6, 5, 1, 1);

    pushButton_scale = new QPushButton(centralwidget);
    pushButton_scale->setObjectName("pushButton_scale");

    gridLayout->addWidget(pushButton_scale, 2, 2, 1, 1);

    pushButton_del = new QPushButton(centralwidget);
    pushButton_del->setObjectName("pushButton_del");

    gridLayout->addWidget(pushButton_del, 2, 6, 1, 1);

    pushButton_6 = new QPushButton(centralwidget);
    pushButton_6->setObjectName("pushButton_6");

    gridLayout->addWidget(pushButton_6, 4, 5, 1, 1);

    doubleSpinBox_x = new QDoubleSpinBox(centralwidget);
    doubleSpinBox_x->setObjectName("doubleSpinBox_x");
    doubleSpinBox_x->setMinimum(-10000000.000000000000000);
    doubleSpinBox_x->setMaximum(10000000.000000000000000);
    doubleSpinBox_x->setSingleStep(0.100000000000000);

    gridLayout->addWidget(doubleSpinBox_x, 6, 1, 1, 1);

    pushButton_5 = new QPushButton(centralwidget);
    pushButton_5->setObjectName("pushButton_5");

    gridLayout->addWidget(pushButton_5, 4, 4, 1, 1);

    pushButton_sin = new QPushButton(centralwidget);
    pushButton_sin->setObjectName("pushButton_sin");

    gridLayout->addWidget(pushButton_sin, 3, 1, 1, 1);

    gridLayout_2->addLayout(gridLayout, 3, 1, 1, 1);

    label_equation = new QLabel(centralwidget);
    label_equation->setObjectName("label_equation");
    QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred,
                            QSizePolicy::Policy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(
        label_equation->sizePolicy().hasHeightForWidth());
    label_equation->setSizePolicy(sizePolicy1);
    label_equation->setMinimumSize(QSize(0, 50));
    label_equation->setAutoFillBackground(false);
    label_equation->setStyleSheet(
        QString::fromUtf8("background-color: rgb(94, 92, 100);"));
    label_equation->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                                 Qt::AlignVCenter);

    gridLayout_2->addWidget(label_equation, 2, 1, 1, 1);

    Calc->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Calc);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 1102, 22));
    Calc->setMenuBar(menubar);
    statusbar = new QStatusBar(Calc);
    statusbar->setObjectName("statusbar");
    Calc->setStatusBar(statusbar);

    retranslateUi(Calc);

    QMetaObject::connectSlotsByName(Calc);
  }  // setupUi

  void retranslateUi(QMainWindow *Calc) {
    Calc->setWindowTitle(QCoreApplication::translate("Calc", "Calc", nullptr));
    pushButton_tan->setText(
        QCoreApplication::translate("Calc", "tan", nullptr));
    pushButton_0->setText(QCoreApplication::translate("Calc", "0", nullptr));
    pushButton_draw_graph->setText(
        QCoreApplication::translate("Calc", "Draw", nullptr));
    pushButton_Deposit->setText(
        QCoreApplication::translate("Calc", "Deposit", nullptr));
    pushButton_3->setText(QCoreApplication::translate("Calc", "3", nullptr));
    pushButton_atan->setText(
        QCoreApplication::translate("Calc", "atan", nullptr));
    pushButton_equal_sign->setText(
        QCoreApplication::translate("Calc", "=", nullptr));
    pushButton_acos->setText(
        QCoreApplication::translate("Calc", "acos", nullptr));
    pushButton_2->setText(QCoreApplication::translate("Calc", "2", nullptr));
    pushButton_plus->setText(QCoreApplication::translate("Calc", "+", nullptr));
    pushButton_7->setText(QCoreApplication::translate("Calc", "7", nullptr));
    pushButton_x->setText(QCoreApplication::translate("Calc", "x", nullptr));
    pushButton_cos->setText(
        QCoreApplication::translate("Calc", "cos", nullptr));
    pushButton_9->setText(QCoreApplication::translate("Calc", "9", nullptr));
    pushButton_sqrt->setText(
        QCoreApplication::translate("Calc", "sqrt", nullptr));
    pushButton_minus->setText(
        QCoreApplication::translate("Calc", "-", nullptr));
    label_y_max->setText(
        QCoreApplication::translate("Calc", "Y max =", nullptr));
    pushButton_bracket_open->setText(
        QCoreApplication::translate("Calc", "(", nullptr));
    pushButton_bracket_close->setText(
        QCoreApplication::translate("Calc", ")", nullptr));
    pushButton_4->setText(QCoreApplication::translate("Calc", "4", nullptr));
    pushButton_8->setText(QCoreApplication::translate("Calc", "8", nullptr));
    pushButton_1->setText(QCoreApplication::translate("Calc", "1", nullptr));
    pushButton_mul->setText(QCoreApplication::translate("Calc", "*", nullptr));
    pushButton_asin->setText(
        QCoreApplication::translate("Calc", "asin", nullptr));
    checkBox_x->setText(
        QCoreApplication::translate("Calc", "X inside?", nullptr));
    pushButton_log->setText(
        QCoreApplication::translate("Calc", "log", nullptr));
    pushButton_credit->setText(
        QCoreApplication::translate("Calc", "Credit", nullptr));
    pushButton_clear->setText(
        QCoreApplication::translate("Calc", "AC", nullptr));
    label_x_max->setText(
        QCoreApplication::translate("Calc", "X min =", nullptr));
    pushButton_un_minus->setText(
        QCoreApplication::translate("Calc", "~", nullptr));
    label_x_min->setText(
        QCoreApplication::translate("Calc", "X max =", nullptr));
    pushButton_mod->setText(QCoreApplication::translate("Calc", "%", nullptr));
    pushButton_ln->setText(QCoreApplication::translate("Calc", "ln", nullptr));
    label_y_min->setText(
        QCoreApplication::translate("Calc", "Y min =", nullptr));
    pushButton_dot->setText(QCoreApplication::translate("Calc", ",", nullptr));
    pushButton_scale->setText(
        QCoreApplication::translate("Calc", "^", nullptr));
    pushButton_del->setText(QCoreApplication::translate("Calc", "/", nullptr));
    pushButton_6->setText(QCoreApplication::translate("Calc", "6", nullptr));
    pushButton_5->setText(QCoreApplication::translate("Calc", "5", nullptr));
    pushButton_sin->setText(
        QCoreApplication::translate("Calc", "sin", nullptr));
    label_equation->setText(QString());
  }  // retranslateUi
};

namespace Ui {
class Calc : public Ui_Calc {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_CALC_H
