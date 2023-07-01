/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *nums;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_unMin;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_coma;
    QPushButton *pushButton_log;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_2;
    QPushButton *pushButton_degree;
    QPushButton *pushButton_7;
    QPushButton *pushButton_bracket_open;
    QPushButton *pushButton_del;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_equal;
    QCheckBox *input_x;
    QPushButton *pushButton_8;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_bracket_close;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_x;
    QPushButton *pushButton_atan;
    QLineEdit *lineEdit_input_x;
    QPushButton *pushButton_6;
    QPushButton *pushButton_0;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_Ln;
    QPushButton *pushButton_acos;
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_x_max;
    QSpinBox *spinBox_x_min;
    QLabel *label_y_min;
    QLabel *label_x_min;
    QSpinBox *spinBox_y_min;
    QLabel *label_x_max;
    QSpinBox *spinBox_y_max;
    QLabel *label_y_max;
    QPushButton *pushButton_draw_graph;
    QLabel *label_output;
    QWidget *tab;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_rate;
    QComboBox *comboBox_timeframe;
    QRadioButton *radioButton_ann;
    QRadioButton *radioButton_diff;
    QLabel *label_type;
    QLabel *label_rate;
    QLineEdit *lineEdit_credit_amount;
    QPushButton *pushButton;
    QLabel *label_credi_amount;
    QLabel *label_timeframe;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QLabel *label_total_output;
    QLabel *label_rub_3;
    QLabel *label_rub_2;
    QLabel *label_total;
    QLabel *label_overpayment_output;
    QLabel *label_rub_1;
    QLabel *label_monthly_pay;
    QLabel *label_monthly_pay_output;
    QLabel *label_overpayment;
    QWidget *tab_2;
    QLabel *label_3;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QCheckBox *checkBox_capital;
    QLineEdit *lineEdit_rate_2;
    QDateEdit *dateEdit_elim;
    QLabel *label_8;
    QLabel *label_7;
    QComboBox *comboBox_frequency;
    QDateEdit *dateEdit_depo;
    QLineEdit *lineEdit_elim;
    QLabel *label_4;
    QPushButton *pushButton_10;
    QComboBox *comboBox_deposit;
    QLineEdit *lineEdit_tax;
    QLabel *label_6;
    QLineEdit *lineEdit_amount;
    QLineEdit *lineEdit_depo;
    QComboBox *comboBox_timeframe_depos;
    QComboBox *comboBox_elim;
    QCheckBox *checkBox_supplemention;
    QCheckBox *checkBox_elim;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QLabel *label_tax_output;
    QLabel *label_11;
    QLabel *label_interest_output;
    QLabel *label_total_sum_output;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1031, 494);
        QFont font;
        font.setPointSize(16);
        MainWindow->setFont(font);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1031, 471));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideRight);
        nums = new QWidget();
        nums->setObjectName(QString::fromUtf8("nums"));
        gridLayoutWidget_3 = new QWidget(nums);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(500, 80, 523, 351));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_sin = new QPushButton(gridLayoutWidget_3);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        QFont font1;
        font1.setPointSize(20);
        pushButton_sin->setFont(font1);
        pushButton_sin->setStyleSheet(QString::fromUtf8(""));
        pushButton_sin->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_sin, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_4->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_4, 2, 3, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget_3);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8(""));
        pushButton_1->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_1, 3, 3, 1, 1);

        pushButton_minus = new QPushButton(gridLayoutWidget_3);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setFont(font1);
        pushButton_minus->setStyleSheet(QString::fromUtf8(""));
        pushButton_minus->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_minus, 2, 6, 1, 1);

        pushButton_unMin = new QPushButton(gridLayoutWidget_3);
        pushButton_unMin->setObjectName(QString::fromUtf8("pushButton_unMin"));
        pushButton_unMin->setFont(font1);
        pushButton_unMin->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_unMin, 0, 4, 1, 1);

        pushButton_mult = new QPushButton(gridLayoutWidget_3);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setFont(font1);
        pushButton_mult->setStyleSheet(QString::fromUtf8(""));
        pushButton_mult->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_mult, 1, 6, 1, 1);

        pushButton_clear = new QPushButton(gridLayoutWidget_3);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setFont(font1);
        pushButton_clear->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_clear, 0, 3, 1, 1);

        pushButton_asin = new QPushButton(gridLayoutWidget_3);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setFont(font1);
        pushButton_asin->setStyleSheet(QString::fromUtf8(""));
        pushButton_asin->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_asin, 2, 1, 1, 1);

        pushButton_coma = new QPushButton(gridLayoutWidget_3);
        pushButton_coma->setObjectName(QString::fromUtf8("pushButton_coma"));
        pushButton_coma->setFont(font1);
        pushButton_coma->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_coma, 5, 5, 1, 1);

        pushButton_log = new QPushButton(gridLayoutWidget_3);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setFont(font1);
        pushButton_log->setStyleSheet(QString::fromUtf8(""));
        pushButton_log->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_log, 3, 2, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_3->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_3, 3, 5, 1, 1);

        pushButton_plus = new QPushButton(gridLayoutWidget_3);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setFont(font1);
        pushButton_plus->setStyleSheet(QString::fromUtf8(""));
        pushButton_plus->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_plus, 3, 6, 1, 1);

        pushButton_tan = new QPushButton(gridLayoutWidget_3);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setFont(font1);
        pushButton_tan->setStyleSheet(QString::fromUtf8(""));
        pushButton_tan->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_tan, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_2->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_2, 3, 4, 1, 1);

        pushButton_degree = new QPushButton(gridLayoutWidget_3);
        pushButton_degree->setObjectName(QString::fromUtf8("pushButton_degree"));
        pushButton_degree->setFont(font1);
        pushButton_degree->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_degree, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8(""));
        pushButton_7->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_7, 1, 3, 1, 1);

        pushButton_bracket_open = new QPushButton(gridLayoutWidget_3);
        pushButton_bracket_open->setObjectName(QString::fromUtf8("pushButton_bracket_open"));
        pushButton_bracket_open->setFont(font1);
        pushButton_bracket_open->setStyleSheet(QString::fromUtf8(""));
        pushButton_bracket_open->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_bracket_open, 0, 0, 1, 1);

        pushButton_del = new QPushButton(gridLayoutWidget_3);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setFont(font1);
        pushButton_del->setStyleSheet(QString::fromUtf8(""));
        pushButton_del->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_del, 0, 6, 1, 1);

        pushButton_mod = new QPushButton(gridLayoutWidget_3);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setFont(font1);
        pushButton_mod->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_mod, 0, 5, 1, 1);

        pushButton_equal = new QPushButton(gridLayoutWidget_3);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setFont(font1);
        pushButton_equal->setStyleSheet(QString::fromUtf8(""));
        pushButton_equal->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_equal, 5, 6, 1, 1);

        input_x = new QCheckBox(gridLayoutWidget_3);
        input_x->setObjectName(QString::fromUtf8("input_x"));
        QFont font2;
        font2.setPointSize(18);
        input_x->setFont(font2);
        input_x->setTristate(false);

        gridLayout_3->addWidget(input_x, 5, 0, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8(""));
        pushButton_8->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_8, 1, 4, 1, 1);

        pushButton_sqrt = new QPushButton(gridLayoutWidget_3);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setFont(font1);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8(""));
        pushButton_sqrt->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_sqrt, 3, 0, 1, 1);

        pushButton_bracket_close = new QPushButton(gridLayoutWidget_3);
        pushButton_bracket_close->setObjectName(QString::fromUtf8("pushButton_bracket_close"));
        pushButton_bracket_close->setFont(font1);
        pushButton_bracket_close->setStyleSheet(QString::fromUtf8(""));
        pushButton_bracket_close->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_bracket_close, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_5->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_5, 2, 4, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8(""));
        pushButton_9->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_9, 1, 5, 1, 1);

        pushButton_x = new QPushButton(gridLayoutWidget_3);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setFont(font1);
        pushButton_x->setAutoFillBackground(false);
        pushButton_x->setStyleSheet(QString::fromUtf8(""));
        pushButton_x->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_x, 5, 2, 1, 1);

        pushButton_atan = new QPushButton(gridLayoutWidget_3);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setFont(font1);
        pushButton_atan->setStyleSheet(QString::fromUtf8(""));
        pushButton_atan->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_atan, 2, 2, 1, 1);

        lineEdit_input_x = new QLineEdit(gridLayoutWidget_3);
        lineEdit_input_x->setObjectName(QString::fromUtf8("lineEdit_input_x"));
        lineEdit_input_x->setEnabled(true);

        gridLayout_3->addWidget(lineEdit_input_x, 5, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8(""));
        pushButton_6->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_6, 2, 5, 1, 1);

        pushButton_0 = new QPushButton(gridLayoutWidget_3);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8(""));
        pushButton_0->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_0, 5, 3, 1, 2);

        pushButton_cos = new QPushButton(gridLayoutWidget_3);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setFont(font1);
        pushButton_cos->setStyleSheet(QString::fromUtf8(""));
        pushButton_cos->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_cos, 1, 0, 1, 1);

        pushButton_Ln = new QPushButton(gridLayoutWidget_3);
        pushButton_Ln->setObjectName(QString::fromUtf8("pushButton_Ln"));
        pushButton_Ln->setFont(font1);
        pushButton_Ln->setStyleSheet(QString::fromUtf8(""));
        pushButton_Ln->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_Ln, 3, 1, 1, 1);

        pushButton_acos = new QPushButton(gridLayoutWidget_3);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setFont(font1);
        pushButton_acos->setStyleSheet(QString::fromUtf8(""));
        pushButton_acos->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(pushButton_acos, 2, 0, 1, 1);

        widget = new QCustomPlot(nums);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 200, 481, 231));
        widget->setStyleSheet(QString::fromUtf8("background-color:grey;"));
        layoutWidget = new QWidget(nums);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 80, 481, 112));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_x_max = new QSpinBox(layoutWidget);
        spinBox_x_max->setObjectName(QString::fromUtf8("spinBox_x_max"));
        spinBox_x_max->setMinimum(-1000000);
        spinBox_x_max->setMaximum(1000000);

        gridLayout->addWidget(spinBox_x_max, 0, 3, 1, 1);

        spinBox_x_min = new QSpinBox(layoutWidget);
        spinBox_x_min->setObjectName(QString::fromUtf8("spinBox_x_min"));
        spinBox_x_min->setMinimum(-1000000);
        spinBox_x_min->setMaximum(1000000);

        gridLayout->addWidget(spinBox_x_min, 0, 1, 1, 1);

        label_y_min = new QLabel(layoutWidget);
        label_y_min->setObjectName(QString::fromUtf8("label_y_min"));

        gridLayout->addWidget(label_y_min, 1, 0, 1, 1);

        label_x_min = new QLabel(layoutWidget);
        label_x_min->setObjectName(QString::fromUtf8("label_x_min"));

        gridLayout->addWidget(label_x_min, 0, 0, 1, 1);

        spinBox_y_min = new QSpinBox(layoutWidget);
        spinBox_y_min->setObjectName(QString::fromUtf8("spinBox_y_min"));
        spinBox_y_min->setMinimum(-1000000);
        spinBox_y_min->setMaximum(1000000);

        gridLayout->addWidget(spinBox_y_min, 1, 1, 1, 1);

        label_x_max = new QLabel(layoutWidget);
        label_x_max->setObjectName(QString::fromUtf8("label_x_max"));

        gridLayout->addWidget(label_x_max, 0, 2, 1, 1);

        spinBox_y_max = new QSpinBox(layoutWidget);
        spinBox_y_max->setObjectName(QString::fromUtf8("spinBox_y_max"));
        spinBox_y_max->setMinimum(-1000000);
        spinBox_y_max->setMaximum(1000000);

        gridLayout->addWidget(spinBox_y_max, 1, 3, 1, 1);

        label_y_max = new QLabel(layoutWidget);
        label_y_max->setObjectName(QString::fromUtf8("label_y_max"));

        gridLayout->addWidget(label_y_max, 1, 2, 1, 1);

        pushButton_draw_graph = new QPushButton(layoutWidget);
        pushButton_draw_graph->setObjectName(QString::fromUtf8("pushButton_draw_graph"));

        gridLayout->addWidget(pushButton_draw_graph, 2, 0, 1, 4);

        label_output = new QLabel(nums);
        label_output->setObjectName(QString::fromUtf8("label_output"));
        label_output->setGeometry(QRect(0, 0, 1021, 80));
        QFont font3;
        font3.setPointSize(48);
        label_output->setFont(font3);
        label_output->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);"));
        label_output->setTextFormat(Qt::AutoText);
        label_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(nums, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 221, 21));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        label_2->setFont(font4);
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 451, 361));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_rate = new QLineEdit(gridLayoutWidget);
        lineEdit_rate->setObjectName(QString::fromUtf8("lineEdit_rate"));

        gridLayout_2->addWidget(lineEdit_rate, 1, 1, 1, 1);

        comboBox_timeframe = new QComboBox(gridLayoutWidget);
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
        comboBox_timeframe->setObjectName(QString::fromUtf8("comboBox_timeframe"));

        gridLayout_2->addWidget(comboBox_timeframe, 2, 1, 1, 1);

        radioButton_ann = new QRadioButton(gridLayoutWidget);
        radioButton_ann->setObjectName(QString::fromUtf8("radioButton_ann"));

        gridLayout_2->addWidget(radioButton_ann, 3, 1, 1, 1);

        radioButton_diff = new QRadioButton(gridLayoutWidget);
        radioButton_diff->setObjectName(QString::fromUtf8("radioButton_diff"));

        gridLayout_2->addWidget(radioButton_diff, 4, 1, 1, 1);

        label_type = new QLabel(gridLayoutWidget);
        label_type->setObjectName(QString::fromUtf8("label_type"));
        label_type->setFont(font2);

        gridLayout_2->addWidget(label_type, 3, 0, 2, 1);

        label_rate = new QLabel(gridLayoutWidget);
        label_rate->setObjectName(QString::fromUtf8("label_rate"));
        label_rate->setFont(font2);

        gridLayout_2->addWidget(label_rate, 1, 0, 1, 1);

        lineEdit_credit_amount = new QLineEdit(gridLayoutWidget);
        lineEdit_credit_amount->setObjectName(QString::fromUtf8("lineEdit_credit_amount"));

        gridLayout_2->addWidget(lineEdit_credit_amount, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 5, 0, 1, 2);

        label_credi_amount = new QLabel(gridLayoutWidget);
        label_credi_amount->setObjectName(QString::fromUtf8("label_credi_amount"));
        label_credi_amount->setFont(font2);

        gridLayout_2->addWidget(label_credi_amount, 0, 0, 1, 1);

        label_timeframe = new QLabel(gridLayoutWidget);
        label_timeframe->setObjectName(QString::fromUtf8("label_timeframe"));
        label_timeframe->setFont(font2);

        gridLayout_2->addWidget(label_timeframe, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(tab);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(470, 40, 541, 361));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_total_output = new QLabel(gridLayoutWidget_2);
        label_total_output->setObjectName(QString::fromUtf8("label_total_output"));
        label_total_output->setFont(font2);
        label_total_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_total_output, 2, 1, 1, 1);

        label_rub_3 = new QLabel(gridLayoutWidget_2);
        label_rub_3->setObjectName(QString::fromUtf8("label_rub_3"));
        label_rub_3->setFont(font2);

        gridLayout_4->addWidget(label_rub_3, 2, 2, 1, 1);

        label_rub_2 = new QLabel(gridLayoutWidget_2);
        label_rub_2->setObjectName(QString::fromUtf8("label_rub_2"));
        label_rub_2->setFont(font2);

        gridLayout_4->addWidget(label_rub_2, 0, 2, 1, 1);

        label_total = new QLabel(gridLayoutWidget_2);
        label_total->setObjectName(QString::fromUtf8("label_total"));
        label_total->setFont(font2);
        label_total->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_total, 2, 0, 1, 1);

        label_overpayment_output = new QLabel(gridLayoutWidget_2);
        label_overpayment_output->setObjectName(QString::fromUtf8("label_overpayment_output"));
        label_overpayment_output->setFont(font2);
        label_overpayment_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_overpayment_output, 1, 1, 1, 1);

        label_rub_1 = new QLabel(gridLayoutWidget_2);
        label_rub_1->setObjectName(QString::fromUtf8("label_rub_1"));
        label_rub_1->setFont(font2);

        gridLayout_4->addWidget(label_rub_1, 1, 2, 1, 1);

        label_monthly_pay = new QLabel(gridLayoutWidget_2);
        label_monthly_pay->setObjectName(QString::fromUtf8("label_monthly_pay"));
        label_monthly_pay->setFont(font2);

        gridLayout_4->addWidget(label_monthly_pay, 0, 0, 1, 1);

        label_monthly_pay_output = new QLabel(gridLayoutWidget_2);
        label_monthly_pay_output->setObjectName(QString::fromUtf8("label_monthly_pay_output"));
        label_monthly_pay_output->setFont(font2);
        label_monthly_pay_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_monthly_pay_output, 0, 1, 1, 1);

        label_overpayment = new QLabel(gridLayoutWidget_2);
        label_overpayment->setObjectName(QString::fromUtf8("label_overpayment"));
        label_overpayment->setFont(font2);

        gridLayout_4->addWidget(label_overpayment, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 221, 21));
        label_3->setFont(font4);
        gridLayoutWidget_4 = new QWidget(tab_2);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 60, 591, 361));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        checkBox_capital = new QCheckBox(gridLayoutWidget_4);
        checkBox_capital->setObjectName(QString::fromUtf8("checkBox_capital"));
        checkBox_capital->setFont(font1);

        gridLayout_5->addWidget(checkBox_capital, 5, 0, 1, 4);

        lineEdit_rate_2 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_rate_2->setObjectName(QString::fromUtf8("lineEdit_rate_2"));

        gridLayout_5->addWidget(lineEdit_rate_2, 2, 1, 1, 3);

        dateEdit_elim = new QDateEdit(gridLayoutWidget_4);
        dateEdit_elim->setObjectName(QString::fromUtf8("dateEdit_elim"));
        dateEdit_elim->setFont(font2);
        dateEdit_elim->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(23, 59, 56)));
        dateEdit_elim->setMinimumDateTime(QDateTime(QDate(2023, 1, 1), QTime(23, 59, 56)));
        dateEdit_elim->setMinimumDate(QDate(2023, 1, 1));

        gridLayout_5->addWidget(dateEdit_elim, 7, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        gridLayout_5->addWidget(label_8, 4, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        gridLayout_5->addWidget(label_7, 3, 0, 1, 1);

        comboBox_frequency = new QComboBox(gridLayoutWidget_4);
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->setObjectName(QString::fromUtf8("comboBox_frequency"));
        comboBox_frequency->setFont(font2);

        gridLayout_5->addWidget(comboBox_frequency, 4, 1, 1, 3);

        dateEdit_depo = new QDateEdit(gridLayoutWidget_4);
        dateEdit_depo->setObjectName(QString::fromUtf8("dateEdit_depo"));
        dateEdit_depo->setFont(font2);
        dateEdit_depo->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(23, 59, 56)));
        dateEdit_depo->setMinimumDateTime(QDateTime(QDate(2023, 1, 1), QTime(23, 59, 56)));
        dateEdit_depo->setMinimumDate(QDate(2023, 1, 1));

        gridLayout_5->addWidget(dateEdit_depo, 6, 2, 1, 1);

        lineEdit_elim = new QLineEdit(gridLayoutWidget_4);
        lineEdit_elim->setObjectName(QString::fromUtf8("lineEdit_elim"));

        gridLayout_5->addWidget(lineEdit_elim, 7, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_5->addWidget(pushButton_10, 8, 0, 1, 4);

        comboBox_deposit = new QComboBox(gridLayoutWidget_4);
        comboBox_deposit->addItem(QString());
        comboBox_deposit->addItem(QString());
        comboBox_deposit->addItem(QString());
        comboBox_deposit->addItem(QString());
        comboBox_deposit->setObjectName(QString::fromUtf8("comboBox_deposit"));
        comboBox_deposit->setFont(font2);

        gridLayout_5->addWidget(comboBox_deposit, 6, 1, 1, 1);

        lineEdit_tax = new QLineEdit(gridLayoutWidget_4);
        lineEdit_tax->setObjectName(QString::fromUtf8("lineEdit_tax"));

        gridLayout_5->addWidget(lineEdit_tax, 3, 1, 1, 3);

        label_6 = new QLabel(gridLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_5->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_amount = new QLineEdit(gridLayoutWidget_4);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));

        gridLayout_5->addWidget(lineEdit_amount, 0, 1, 1, 3);

        lineEdit_depo = new QLineEdit(gridLayoutWidget_4);
        lineEdit_depo->setObjectName(QString::fromUtf8("lineEdit_depo"));

        gridLayout_5->addWidget(lineEdit_depo, 6, 3, 1, 1);

        comboBox_timeframe_depos = new QComboBox(gridLayoutWidget_4);
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->addItem(QString());
        comboBox_timeframe_depos->setObjectName(QString::fromUtf8("comboBox_timeframe_depos"));
        comboBox_timeframe_depos->setFont(font2);

        gridLayout_5->addWidget(comboBox_timeframe_depos, 1, 1, 1, 3);

        comboBox_elim = new QComboBox(gridLayoutWidget_4);
        comboBox_elim->addItem(QString());
        comboBox_elim->addItem(QString());
        comboBox_elim->addItem(QString());
        comboBox_elim->addItem(QString());
        comboBox_elim->setObjectName(QString::fromUtf8("comboBox_elim"));
        comboBox_elim->setFont(font2);

        gridLayout_5->addWidget(comboBox_elim, 7, 1, 1, 1);

        checkBox_supplemention = new QCheckBox(gridLayoutWidget_4);
        checkBox_supplemention->setObjectName(QString::fromUtf8("checkBox_supplemention"));
        checkBox_supplemention->setFont(font1);

        gridLayout_5->addWidget(checkBox_supplemention, 6, 0, 1, 1);

        checkBox_elim = new QCheckBox(gridLayoutWidget_4);
        checkBox_elim->setObjectName(QString::fromUtf8("checkBox_elim"));
        checkBox_elim->setFont(font1);

        gridLayout_5->addWidget(checkBox_elim, 7, 0, 1, 1);

        gridLayoutWidget_5 = new QWidget(tab_2);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(610, 60, 401, 361));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_tax_output = new QLabel(gridLayoutWidget_5);
        label_tax_output->setObjectName(QString::fromUtf8("label_tax_output"));
        label_tax_output->setFont(font1);
        label_tax_output->setAutoFillBackground(false);
        label_tax_output->setStyleSheet(QString::fromUtf8(""));
        label_tax_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_tax_output, 2, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font5;
        font5.setPointSize(29);
        label_11->setFont(font5);
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 85, 87);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_11, 0, 0, 1, 2);

        label_interest_output = new QLabel(gridLayoutWidget_5);
        label_interest_output->setObjectName(QString::fromUtf8("label_interest_output"));
        label_interest_output->setFont(font1);
        label_interest_output->setAutoFillBackground(false);
        label_interest_output->setStyleSheet(QString::fromUtf8(""));
        label_interest_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_interest_output, 1, 1, 1, 1);

        label_total_sum_output = new QLabel(gridLayoutWidget_5);
        label_total_sum_output->setObjectName(QString::fromUtf8("label_total_sum_output"));
        label_total_sum_output->setFont(font1);
        label_total_sum_output->setAutoFillBackground(false);
        label_total_sum_output->setStyleSheet(QString::fromUtf8(""));
        label_total_sum_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_total_sum_output, 3, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 85, 87);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setAutoFillBackground(false);
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 85, 87);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_14, 3, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setAutoFillBackground(false);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 85, 87);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_12, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(800, 470, 221, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator v1.0", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "SIN", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_unMin->setText(QCoreApplication::translate("MainWindow", "~/+", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "ASIN", nullptr));
        pushButton_coma->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "TAN", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_degree->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_bracket_open->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        input_x->setText(QCoreApplication::translate("MainWindow", "Input X", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "SQRT", nullptr));
        pushButton_bracket_close->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "ATAN", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "COS", nullptr));
        pushButton_Ln->setText(QCoreApplication::translate("MainWindow", "Ln", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "ACOS", nullptr));
        label_y_min->setText(QCoreApplication::translate("MainWindow", "Y min = ", nullptr));
        label_x_min->setText(QCoreApplication::translate("MainWindow", "X min = ", nullptr));
        label_x_max->setText(QCoreApplication::translate("MainWindow", "X max = ", nullptr));
        label_y_max->setText(QCoreApplication::translate("MainWindow", "Y max = ", nullptr));
        pushButton_draw_graph->setText(QCoreApplication::translate("MainWindow", "Draw Graphic", nullptr));
        label_output->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(nums), QCoreApplication::translate("MainWindow", "CALC", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        comboBox_timeframe->setItemText(0, QCoreApplication::translate("MainWindow", "1 month", nullptr));
        comboBox_timeframe->setItemText(1, QCoreApplication::translate("MainWindow", "3 month", nullptr));
        comboBox_timeframe->setItemText(2, QCoreApplication::translate("MainWindow", "6 month", nullptr));
        comboBox_timeframe->setItemText(3, QCoreApplication::translate("MainWindow", "9 month", nullptr));
        comboBox_timeframe->setItemText(4, QCoreApplication::translate("MainWindow", "1 year", nullptr));
        comboBox_timeframe->setItemText(5, QCoreApplication::translate("MainWindow", "1.5 year", nullptr));
        comboBox_timeframe->setItemText(6, QCoreApplication::translate("MainWindow", "2 year", nullptr));
        comboBox_timeframe->setItemText(7, QCoreApplication::translate("MainWindow", "3 year", nullptr));
        comboBox_timeframe->setItemText(8, QCoreApplication::translate("MainWindow", "4 year", nullptr));
        comboBox_timeframe->setItemText(9, QCoreApplication::translate("MainWindow", "5 year", nullptr));
        comboBox_timeframe->setItemText(10, QCoreApplication::translate("MainWindow", "6 year", nullptr));
        comboBox_timeframe->setItemText(11, QCoreApplication::translate("MainWindow", "7 year", nullptr));
        comboBox_timeframe->setItemText(12, QCoreApplication::translate("MainWindow", "10 year", nullptr));
        comboBox_timeframe->setItemText(13, QCoreApplication::translate("MainWindow", "15 year", nullptr));
        comboBox_timeframe->setItemText(14, QCoreApplication::translate("MainWindow", "20 year", nullptr));
        comboBox_timeframe->setItemText(15, QCoreApplication::translate("MainWindow", "25 year", nullptr));
        comboBox_timeframe->setItemText(16, QCoreApplication::translate("MainWindow", "30 year", nullptr));

        radioButton_ann->setText(QCoreApplication::translate("MainWindow", "annuity", nullptr));
        radioButton_diff->setText(QCoreApplication::translate("MainWindow", "differentiated", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_rate->setText(QCoreApplication::translate("MainWindow", "Rate, %", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_credi_amount->setText(QCoreApplication::translate("MainWindow", "Credit amount, \342\202\275", nullptr));
        label_timeframe->setText(QCoreApplication::translate("MainWindow", "Timeframe, m/y", nullptr));
        label_total_output->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_rub_3->setText(QCoreApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_rub_2->setText(QCoreApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_total->setText(QCoreApplication::translate("MainWindow", "Total sum", nullptr));
        label_overpayment_output->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_rub_1->setText(QCoreApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_monthly_pay->setText(QCoreApplication::translate("MainWindow", "Monthly payment", nullptr));
        label_monthly_pay_output->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_overpayment->setText(QCoreApplication::translate("MainWindow", "Overpayment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "CREDIT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Timeframe", nullptr));
        checkBox_capital->setText(QCoreApplication::translate("MainWindow", "Capitalization", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Frequency of payments", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Tax Rate", nullptr));
        comboBox_frequency->setItemText(0, QCoreApplication::translate("MainWindow", "every day", nullptr));
        comboBox_frequency->setItemText(1, QCoreApplication::translate("MainWindow", "every month", nullptr));
        comboBox_frequency->setItemText(2, QCoreApplication::translate("MainWindow", "every quarter", nullptr));
        comboBox_frequency->setItemText(3, QCoreApplication::translate("MainWindow", "every year", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        comboBox_deposit->setItemText(0, QCoreApplication::translate("MainWindow", "one-time", nullptr));
        comboBox_deposit->setItemText(1, QCoreApplication::translate("MainWindow", "once a month", nullptr));
        comboBox_deposit->setItemText(2, QCoreApplication::translate("MainWindow", "once a quarter", nullptr));
        comboBox_deposit->setItemText(3, QCoreApplication::translate("MainWindow", "once a year", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Rate", nullptr));
        comboBox_timeframe_depos->setItemText(0, QCoreApplication::translate("MainWindow", "1 month", nullptr));
        comboBox_timeframe_depos->setItemText(1, QCoreApplication::translate("MainWindow", "3 month", nullptr));
        comboBox_timeframe_depos->setItemText(2, QCoreApplication::translate("MainWindow", "6 month", nullptr));
        comboBox_timeframe_depos->setItemText(3, QCoreApplication::translate("MainWindow", "9 month", nullptr));
        comboBox_timeframe_depos->setItemText(4, QCoreApplication::translate("MainWindow", "1 year", nullptr));
        comboBox_timeframe_depos->setItemText(5, QCoreApplication::translate("MainWindow", "2 year", nullptr));
        comboBox_timeframe_depos->setItemText(6, QCoreApplication::translate("MainWindow", "3 year", nullptr));
        comboBox_timeframe_depos->setItemText(7, QCoreApplication::translate("MainWindow", "4 year", nullptr));
        comboBox_timeframe_depos->setItemText(8, QCoreApplication::translate("MainWindow", "5 year", nullptr));
        comboBox_timeframe_depos->setItemText(9, QCoreApplication::translate("MainWindow", "10 year", nullptr));
        comboBox_timeframe_depos->setItemText(10, QCoreApplication::translate("MainWindow", "20 year", nullptr));

        comboBox_elim->setItemText(0, QCoreApplication::translate("MainWindow", "one-time", nullptr));
        comboBox_elim->setItemText(1, QCoreApplication::translate("MainWindow", "once a month", nullptr));
        comboBox_elim->setItemText(2, QCoreApplication::translate("MainWindow", "once a quarter", nullptr));
        comboBox_elim->setItemText(3, QCoreApplication::translate("MainWindow", "once a year", nullptr));

        checkBox_supplemention->setText(QCoreApplication::translate("MainWindow", "Supplementions", nullptr));
        checkBox_elim->setText(QCoreApplication::translate("MainWindow", "Eliminations", nullptr));
        label_tax_output->setText(QCoreApplication::translate("MainWindow", "0 \342\202\275", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        label_interest_output->setText(QCoreApplication::translate("MainWindow", "0 \342\202\275", nullptr));
        label_total_sum_output->setText(QCoreApplication::translate("MainWindow", "0 \342\202\275", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Tax", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Accrued interest", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "DEPOSIT", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\302\251SuperboyAmira 2023", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
