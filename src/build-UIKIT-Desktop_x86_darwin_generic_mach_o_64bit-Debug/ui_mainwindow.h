/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *nums;
    QPushButton *pushButton_0;
    QPushButton *pushButton_6;
    QPushButton *pushButton_del;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_9;
    QPushButton *pushButton_1;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_coma;
    QPushButton *pushButton_unMin;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_8;
    QWidget *functions;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_del_5;
    QPushButton *pushButton_equal_5;
    QPushButton *pushButton_minus_5;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_x;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_log;
    QPushButton *pushButton_degree;
    QPushButton *pushButton_unMin_5;
    QPushButton *pushButton_mult_5;
    QPushButton *pushButton_mod_5;
    QPushButton *pushButton_Ln;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_clear_5;
    QPushButton *pushButton_plus_5;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_bracket_close;
    QLabel *label_output;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(321, 493);
        QFont font;
        font.setPointSize(16);
        MainWindow->setFont(font);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 80, 321, 381));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideRight);
        nums = new QWidget();
        nums->setObjectName(QString::fromUtf8("nums"));
        pushButton_0 = new QPushButton(nums);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(0, 280, 161, 80));
        QFont font1;
        font1.setPointSize(20);
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8(""));
        pushButton_0->setIconSize(QSize(16, 16));
        pushButton_6 = new QPushButton(nums);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(160, 140, 80, 80));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8(""));
        pushButton_6->setIconSize(QSize(16, 16));
        pushButton_del = new QPushButton(nums);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(240, 0, 80, 80));
        pushButton_del->setFont(font1);
        pushButton_del->setStyleSheet(QString::fromUtf8(""));
        pushButton_del->setIconSize(QSize(16, 16));
        pushButton_equal = new QPushButton(nums);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setGeometry(QRect(240, 280, 80, 80));
        pushButton_equal->setFont(font1);
        pushButton_equal->setStyleSheet(QString::fromUtf8(""));
        pushButton_equal->setIconSize(QSize(16, 16));
        pushButton_minus = new QPushButton(nums);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(240, 140, 80, 80));
        pushButton_minus->setFont(font1);
        pushButton_minus->setStyleSheet(QString::fromUtf8(""));
        pushButton_minus->setIconSize(QSize(16, 16));
        pushButton_9 = new QPushButton(nums);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(160, 70, 80, 80));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8(""));
        pushButton_9->setIconSize(QSize(16, 16));
        pushButton_1 = new QPushButton(nums);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(0, 210, 80, 80));
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8(""));
        pushButton_1->setIconSize(QSize(16, 16));
        pushButton_7 = new QPushButton(nums);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 70, 80, 80));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8(""));
        pushButton_7->setIconSize(QSize(16, 16));
        pushButton_3 = new QPushButton(nums);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(160, 210, 80, 80));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_3->setIconSize(QSize(16, 16));
        pushButton_coma = new QPushButton(nums);
        pushButton_coma->setObjectName(QString::fromUtf8("pushButton_coma"));
        pushButton_coma->setGeometry(QRect(160, 280, 80, 80));
        pushButton_coma->setFont(font1);
        pushButton_coma->setIconSize(QSize(16, 16));
        pushButton_unMin = new QPushButton(nums);
        pushButton_unMin->setObjectName(QString::fromUtf8("pushButton_unMin"));
        pushButton_unMin->setGeometry(QRect(80, 0, 80, 80));
        pushButton_unMin->setFont(font1);
        pushButton_unMin->setIconSize(QSize(16, 16));
        pushButton_mult = new QPushButton(nums);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(240, 70, 80, 80));
        pushButton_mult->setFont(font1);
        pushButton_mult->setStyleSheet(QString::fromUtf8(""));
        pushButton_mult->setIconSize(QSize(16, 16));
        pushButton_mod = new QPushButton(nums);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(160, 0, 80, 80));
        pushButton_mod->setFont(font1);
        pushButton_mod->setIconSize(QSize(16, 16));
        pushButton_2 = new QPushButton(nums);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 210, 80, 80));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_2->setIconSize(QSize(16, 16));
        pushButton_4 = new QPushButton(nums);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 140, 80, 80));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_4->setIconSize(QSize(16, 16));
        pushButton_5 = new QPushButton(nums);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 140, 80, 80));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_5->setIconSize(QSize(16, 16));
        pushButton_clear = new QPushButton(nums);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(0, 0, 80, 80));
        pushButton_clear->setFont(font1);
        pushButton_clear->setIconSize(QSize(16, 16));
        pushButton_plus = new QPushButton(nums);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(240, 210, 80, 80));
        pushButton_plus->setFont(font1);
        pushButton_plus->setStyleSheet(QString::fromUtf8(""));
        pushButton_plus->setIconSize(QSize(16, 16));
        pushButton_8 = new QPushButton(nums);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(80, 70, 80, 80));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8(""));
        pushButton_8->setIconSize(QSize(16, 16));
        tabWidget->addTab(nums, QString());
        functions = new QWidget();
        functions->setObjectName(QString::fromUtf8("functions"));
        pushButton_atan = new QPushButton(functions);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(160, 140, 80, 80));
        pushButton_atan->setFont(font1);
        pushButton_atan->setStyleSheet(QString::fromUtf8(""));
        pushButton_atan->setIconSize(QSize(16, 16));
        pushButton_del_5 = new QPushButton(functions);
        pushButton_del_5->setObjectName(QString::fromUtf8("pushButton_del_5"));
        pushButton_del_5->setGeometry(QRect(240, 0, 80, 80));
        pushButton_del_5->setFont(font1);
        pushButton_del_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_del_5->setIconSize(QSize(16, 16));
        pushButton_equal_5 = new QPushButton(functions);
        pushButton_equal_5->setObjectName(QString::fromUtf8("pushButton_equal_5"));
        pushButton_equal_5->setGeometry(QRect(240, 280, 80, 80));
        pushButton_equal_5->setFont(font1);
        pushButton_equal_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_equal_5->setIconSize(QSize(16, 16));
        pushButton_minus_5 = new QPushButton(functions);
        pushButton_minus_5->setObjectName(QString::fromUtf8("pushButton_minus_5"));
        pushButton_minus_5->setGeometry(QRect(240, 140, 80, 80));
        pushButton_minus_5->setFont(font1);
        pushButton_minus_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_minus_5->setIconSize(QSize(16, 16));
        pushButton_tan = new QPushButton(functions);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(160, 70, 80, 80));
        pushButton_tan->setFont(font1);
        pushButton_tan->setStyleSheet(QString::fromUtf8(""));
        pushButton_tan->setIconSize(QSize(16, 16));
        pushButton_sqrt = new QPushButton(functions);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(0, 210, 80, 80));
        pushButton_sqrt->setFont(font1);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8(""));
        pushButton_sqrt->setIconSize(QSize(16, 16));
        pushButton_x = new QPushButton(functions);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(0, 280, 81, 80));
        pushButton_x->setFont(font1);
        pushButton_x->setStyleSheet(QString::fromUtf8(""));
        pushButton_x->setIconSize(QSize(16, 16));
        pushButton_cos = new QPushButton(functions);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(0, 70, 80, 80));
        pushButton_cos->setFont(font1);
        pushButton_cos->setStyleSheet(QString::fromUtf8(""));
        pushButton_cos->setIconSize(QSize(16, 16));
        pushButton_log = new QPushButton(functions);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(160, 210, 80, 80));
        pushButton_log->setFont(font1);
        pushButton_log->setStyleSheet(QString::fromUtf8(""));
        pushButton_log->setIconSize(QSize(16, 16));
        pushButton_degree = new QPushButton(functions);
        pushButton_degree->setObjectName(QString::fromUtf8("pushButton_degree"));
        pushButton_degree->setGeometry(QRect(160, 280, 80, 80));
        pushButton_degree->setFont(font1);
        pushButton_degree->setIconSize(QSize(16, 16));
        pushButton_unMin_5 = new QPushButton(functions);
        pushButton_unMin_5->setObjectName(QString::fromUtf8("pushButton_unMin_5"));
        pushButton_unMin_5->setGeometry(QRect(80, 0, 80, 80));
        pushButton_unMin_5->setFont(font1);
        pushButton_unMin_5->setAutoFillBackground(false);
        pushButton_unMin_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_unMin_5->setIconSize(QSize(16, 16));
        pushButton_mult_5 = new QPushButton(functions);
        pushButton_mult_5->setObjectName(QString::fromUtf8("pushButton_mult_5"));
        pushButton_mult_5->setGeometry(QRect(240, 70, 80, 80));
        pushButton_mult_5->setFont(font1);
        pushButton_mult_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_mult_5->setIconSize(QSize(16, 16));
        pushButton_mod_5 = new QPushButton(functions);
        pushButton_mod_5->setObjectName(QString::fromUtf8("pushButton_mod_5"));
        pushButton_mod_5->setGeometry(QRect(160, 0, 80, 80));
        pushButton_mod_5->setFont(font1);
        pushButton_mod_5->setIconSize(QSize(16, 16));
        pushButton_Ln = new QPushButton(functions);
        pushButton_Ln->setObjectName(QString::fromUtf8("pushButton_Ln"));
        pushButton_Ln->setGeometry(QRect(80, 210, 80, 80));
        pushButton_Ln->setFont(font1);
        pushButton_Ln->setStyleSheet(QString::fromUtf8(""));
        pushButton_Ln->setIconSize(QSize(16, 16));
        pushButton_acos = new QPushButton(functions);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(0, 140, 80, 80));
        pushButton_acos->setFont(font1);
        pushButton_acos->setStyleSheet(QString::fromUtf8(""));
        pushButton_acos->setIconSize(QSize(16, 16));
        pushButton_asin = new QPushButton(functions);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(80, 140, 80, 80));
        pushButton_asin->setFont(font1);
        pushButton_asin->setStyleSheet(QString::fromUtf8(""));
        pushButton_asin->setIconSize(QSize(16, 16));
        pushButton_clear_5 = new QPushButton(functions);
        pushButton_clear_5->setObjectName(QString::fromUtf8("pushButton_clear_5"));
        pushButton_clear_5->setGeometry(QRect(0, 0, 80, 80));
        pushButton_clear_5->setFont(font1);
        pushButton_clear_5->setIconSize(QSize(16, 16));
        pushButton_plus_5 = new QPushButton(functions);
        pushButton_plus_5->setObjectName(QString::fromUtf8("pushButton_plus_5"));
        pushButton_plus_5->setGeometry(QRect(240, 210, 80, 80));
        pushButton_plus_5->setFont(font1);
        pushButton_plus_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_plus_5->setIconSize(QSize(16, 16));
        pushButton_sin = new QPushButton(functions);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(80, 70, 80, 80));
        pushButton_sin->setFont(font1);
        pushButton_sin->setStyleSheet(QString::fromUtf8(""));
        pushButton_sin->setIconSize(QSize(16, 16));
        pushButton_graph = new QPushButton(functions);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(80, 310, 80, 51));
        pushButton_graph->setFont(font1);
        pushButton_graph->setStyleSheet(QString::fromUtf8(""));
        pushButton_graph->setIconSize(QSize(16, 16));
        pushButton_bracket_close = new QPushButton(functions);
        pushButton_bracket_close->setObjectName(QString::fromUtf8("pushButton_bracket_close"));
        pushButton_bracket_close->setGeometry(QRect(79, 280, 81, 41));
        pushButton_bracket_close->setFont(font1);
        pushButton_bracket_close->setStyleSheet(QString::fromUtf8(""));
        pushButton_bracket_close->setIconSize(QSize(16, 16));
        tabWidget->addTab(functions, QString());
        label_output = new QLabel(centralwidget);
        label_output->setObjectName(QString::fromUtf8("label_output"));
        label_output->setGeometry(QRect(0, 0, 320, 80));
        QFont font2;
        font2.setPointSize(48);
        label_output->setFont(font2);
        label_output->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);"));
        label_output->setTextFormat(Qt::AutoText);
        label_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 470, 171, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_coma->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_unMin->setText(QCoreApplication::translate("MainWindow", "~/+", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(nums), QCoreApplication::translate("MainWindow", "NUM", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "ATAN", nullptr));
        pushButton_del_5->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_equal_5->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_minus_5->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "TAN", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "SQRT", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "COS", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        pushButton_degree->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_unMin_5->setText(QCoreApplication::translate("MainWindow", "~/+", nullptr));
        pushButton_mult_5->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_mod_5->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_Ln->setText(QCoreApplication::translate("MainWindow", "Ln", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "ACOS", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "ASIN", nullptr));
        pushButton_clear_5->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_plus_5->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "SIN", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "GRAPH", nullptr));
        pushButton_bracket_close->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(functions), QCoreApplication::translate("MainWindow", "FUNC", nullptr));
        label_output->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\302\251SuperboyAmira 2023", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
