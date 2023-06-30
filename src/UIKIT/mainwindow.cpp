#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../s21_calc.h"
#include "../s21_calc.c"
#include "../s21_credit.c"
#include "../s21_deposit.c"

#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_output->setText("");

    connect(ui->pushButton_bracket_open, SIGNAL(clicked()), this, SLOT(ViewBracket()));
    connect(ui->pushButton_bracket_close, SIGNAL(clicked()), this, SLOT(ViewBracket()));

    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_Ln, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(ViewFuncs()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(ViewOperators()));

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(ViewNums()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(ViewNums()));

    connect(ui->pushButton_coma, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_unMin, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(ViewOperators()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(ViewOperators()));

    connect(ui->pushButton_draw_graph, SIGNAL(clicked()), this, SLOT(DrawGraph()));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ResultCredit()));

    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(ResultDeposit()));

    ui->spinBox_x_max->setValue(10);
    ui->spinBox_x_min->setValue(-10);
    ui->spinBox_y_max->setValue(10);
    ui->spinBox_y_min->setValue(-10);

    ui->lineEdit_amount->setText("100000");
    ui->lineEdit_rate_2->setText("12");
    ui->lineEdit_tax->setText("12");
    ui->checkBox_capital->checkState();
}

// another func

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FormatFont() {
    static int max_size = 35;

    static int font_size = 48;

    if (ui->label_output->text().length() == 0) {
        max_size = 35;

        font_size = 48;

        QFont tmp_font = ui->label_output->font();

        tmp_font.setPixelSize(font_size);

        ui->label_output->setFont(tmp_font);
    }

    if (ui->label_output->text().length() > max_size) {
        font_size -= 4;

        (font_size > 24) ? max_size += 1 : max_size += 20;

        QFont tmp_font = ui->label_output->font();

        tmp_font.setPixelSize(font_size);

        ui->label_output->setFont(tmp_font);

    }
}

char * QStringToChar(QString src) {
    QByteArray _t = src.toLocal8Bit();

    char *_returned = _t.data();

    return _returned;
}

// ------------------

// Nums and Functions

void MainWindow::ViewBracket() {
     QPushButton * button = static_cast<QPushButton*>(QObject::sender());

     ui->label_output->setText(ui->label_output->text() + button->text());
}

void MainWindow::ViewNums() {
    FormatFont();

    QPushButton * button = static_cast<QPushButton*>(QObject::sender());

    if (ui->label_output->text().length() == 1) {
        if (ui->label_output->text().at(0) == '0') {
            ui->label_output->setText(button->text());
        } else {
            ui->label_output->setText(ui->label_output->text() + button->text());
        }
    } else {
        ui->label_output->setText(ui->label_output->text() + button->text());
    }
}

void MainWindow::ViewFuncs() {
    FormatFont();

    QPushButton * button = static_cast<QPushButton*>(QObject::sender());

    if (ui->label_output->text().length() == 1) {
        if (ui->label_output->text().at(0) == '0') {
            ui->label_output->setText(button->text().toLower() + "(");
        } else {
             ui->label_output->setText(ui->label_output->text() + button->text().toLower() + "(");
        }
    } else {
         ui->label_output->setText(ui->label_output->text() + button->text().toLower() + "(");
    }
}


void MainWindow::ViewOperators()
{
    FormatFont();

    QPushButton * button = static_cast<QPushButton*>(QObject::sender());



    if (button->text() == "~/+" && ui->label_output->text().length() > 0) {

        if (ui->label_output->text().at(ui->label_output->text().length() - 1) == '(') {
            ui->label_output->setText(ui->label_output->text() + "-");
        }

    } else if (button->text() == "AC" && ui->label_output->text().length() > 0) {

        ui->label_output->clear();

    } else if (button->text() == "." && ui->label_output->text().length() > 0) {

        if (ui->label_output->text() != "") {
            ui->label_output->setText(ui->label_output->text() + ".");
        }

    } else if (button->text() == "=" && (ui->label_output->text().length() > 0 && ui->label_output->text().toDouble() == 0.0 && ui->label_output->text().at(0) != '0')) {

//        std::string s = ui->label_output->text().toStdString();

//        char equation[NMAX] = {'\0'};

//        strcpy(equation, s.c_str());

        char *equation = QStringToChar(ui->label_output->text());

        double x = 0.0;
        bool status = true;
        bool num = false;

        if (ui->input_x->isChecked()) {
            x = ui->lineEdit_input_x->text().toDouble();
            if (ui->lineEdit_input_x->text() == "") {
                status = false;
            }
        } else {
            if (ui->label_output->text().contains('x')) {
                status = false;
            }
        }

        double result_dbl = Calc(equation, x, &status);

        if (!status) {
            QMessageBox::critical(this, "Error", "INVALID INPUT!<CALC>");
        } else {
            QString result_qstr = (fabs(result_dbl - (int)result_dbl) < 0.00000001) ? QString::asprintf("%d", (int)result_dbl) : QString::asprintf("%.7lf", result_dbl);

            if (result_qstr.contains('.')) {
                for (int i = result_qstr.length() - 1; i != 0; i--) {
                    if (result_qstr.at(i) == '0' && !num) {
                        result_qstr.resize(i);
                    } else if (result_qstr.at(i) != '0') {
                        num = true;
                    }
                }
            }

            ui->label_output->setText(result_qstr);
        }

    } else if (button->text() == "X") {

        ui->label_output->setText(ui->label_output->text() + button->text().toLower());

    } else if (ui->label_output->text().length() > 0 && button->text() != "=") {

        QChar tmp_qchar = ui->label_output->text().at(ui->label_output->text().length() - 1);

        if ((tmp_qchar.isNumber() || tmp_qchar == ')' || tmp_qchar == '(' || tmp_qchar == 'x') && button->text() != "%") {
            ui->label_output->setText(ui->label_output->text() + button->text());
        } else if ((tmp_qchar.isNumber() || tmp_qchar == ')' || tmp_qchar == 'x') && button->text() == "%") {
            ui->label_output->setText(ui->label_output->text() + "mod");
        }
    }
}


// ------------------

// Graphics

void MainWindow::DrawGraph() {
    ui->widget->clearPlottables();
    if (ui->label_output->text().length() == 0 || (ui->spinBox_x_max->value() == 0 && ui->spinBox_x_min->value() == 0
            && ui->spinBox_y_min->value() == 0 && ui->spinBox_y_max->value() == 0) || !CheckEquation(QStringToChar(ui->label_output->text()))) {
         QMessageBox::critical(this, "Error", "INVALID INPUT!<GRAPH>");
    } else {
        double tmp = 0.0;
        bool _t = true;
        step = 0.1;
        xBegin = ui->spinBox_x_min->value();
        xEnd = ui->spinBox_x_max->value() + step;

        ui->widget->xAxis->setRange(xBegin,xEnd);
        ui->widget->yAxis->setRange(ui->spinBox_y_min->value(), ui->spinBox_y_max->value());

        for (X = xBegin; X <= xEnd; X += step) {
            if (fabs(X) < 1e-7)
                X = 0.0;
            _t = true;

            tmp = Calc(QStringToChar(ui->label_output->text()), X, &_t);
            if (_t) {
                x.push_back(X);
                y.push_back(tmp);
            }
        }

        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x,y);
        ui->widget->replot();
        x.clear();
        y.clear();

    }
}

// ------------------

// credit

void MainWindow::ResultCredit() {
    if (ui->lineEdit_credit_amount->text().length() == 0 || ui->lineEdit_rate->text().length() == 0) {
        QMessageBox::critical(this, "Error", "INVALID INPUT!<CREDIT>");
    } else {
        credit_data info = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        info.credit_sum = ui->lineEdit_credit_amount->text().toInt();
        int credit_timeframe_index = ui->comboBox_timeframe->currentIndex();
        int credit_month = 0;
        switch (credit_timeframe_index) {
            case 0:
                credit_month = 1;
                break;
            case 1:
                credit_month = 3;
                break;
            case 2:
                credit_month = 6;
                break;
            case 3:
                credit_month = 9;
                break;
            case 4:
                credit_month = 12;
                break;
            case 5:
                credit_month = 18;
                break;
            case 6:
                credit_month = 24;
                break;
            case 7:
                credit_month = 36;
                break;
            case 8:
                credit_month = 48;
                break;
            case 9:
                credit_month = 60;
                break;
            case 10:
                credit_month = 72;
                break;
            case 11:
                credit_month = 84;
                break;
            case 12:
                credit_month = 120;
                break;
            case 13:
                credit_month = 180;
                break;
            case 14:
                credit_month = 240;
                break;
            case 15:
                credit_month = 300;
                break;
            case 16:
                credit_month = 360;
                break;
        }
        info.timeframe = credit_month;
        info.rate = ui->lineEdit_rate->text().toDouble();
        if (ui->radioButton_ann->isChecked()) {
            info.type = ANN;
        } else {
            info.type = DIFF;
        }
        MainCredit(&info);
        QString tmp;
        if (info.type == ANN) {
            tmp = QString::asprintf("%.2lf", info.month_pay_ann);
            ui->label_monthly_pay_output->setText(tmp);
        } else {
            QString result_min = QString::asprintf("%.2lf", info.month_pay_diff_min);
            QString result_max = QString::asprintf("%.2lf", info.month_pay_diff_max);
            ui->label_monthly_pay_output->setText(result_min + "..." + result_max);
        }
        tmp = QString::asprintf("%.2lf", info.overpayment);
        ui->label_overpayment_output->setText(tmp);
        tmp = QString::asprintf("%.2lf", info.total_payment);
        ui->label_total_output->setText(tmp);
    }
}

// ------------------

int timeframeParser(int index, int type) {
    const double month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int result = 0;

        switch (index) {
            case 0:
                if (type == 0) result = 31;
                else if (type == 1) result = 1;
                break;
            case 1:
                if (type == 0) for (int i = 0; i < 3; i++) result += month_day[i];
                else if (type == 1) result = 3;
                break;
            case 2:
                if (type == 0) for (int i = 0; i < 6; i++) result += month_day[i];
                else if (type == 1) result = 6;
                else if (type == 2) result = 1;
                break;
            case 3:
                if (type == 0) for (int i = 0; i < 9; i++) result += month_day[i];
                else if (type == 1) result = 9;
                else if (type == 2) result = 2;
                break;
            case 4:
                if (type == 0) for (int i = 0; i < 12; i++) result += month_day[i];
                else if (type == 1) result = 12;
                else if (type == 2) result = 4;
                else if (type == 3) result = 1;
                break;
            case 5:
                if (type == 0) for (int i = 0; i < 24; i++) result += month_day[i % 12];
                else if (type == 1) result = 24;
                else if (type == 2) result = 8;
                else if (type == 3) result = 2;
                break;
            case 6:
                if (type == 0) for (int i = 0; i < 36; i++) result += month_day[i % 12];
                else if (type == 1) result = 36;
                else if (type == 2) result = 12;
                else if (type == 3) result = 3;
                break;
            case 7:
                if (type == 0) for (int i = 0; i < 48; i++) result += month_day[i % 12];
                else if (type == 1) result = 48;
                else if (type == 2) result = 16;
                else if (type == 3) result = 4;
                break;
            case 8:
                if (type == 0) for (int i = 0; i < 60; i++) result += month_day[i % 12];
                else if (type == 1) result = 60;
                else if (type == 2) result = 20;
                else if (type == 3) result = 5;
                break;
            case 9:
                if (type == 0) for (int i = 0; i < 120; i++) result += month_day[i % 12];
                else if (type == 1) result = 120;
                else if (type == 2) result = 40;
                else if (type == 3) result = 10;
                break;
            case 10:
                if (type == 0) for (int i = 0; i < 240; i++) result += month_day[i % 12];
                else if (type == 1) result = 240;
                else if (type == 2) result = 80;
                else if (type == 3) result = 20;
                break;
        }

    return result;
}

// deposit

void MainWindow::ResultDeposit() {
    deposit_data info = {0,0,0,0,0,false,{0,0,0},0,0,0,{0,0,0},0,0,0,0,0,0,0};
    (ui->checkBox_capital->isChecked()) ? info.capitalisation = true : info.capitalisation = false;
    info.sum = ui->lineEdit_amount->text().toDouble();
    info.timeframe_type = ui->comboBox_frequency->currentIndex();
    if (!info.capitalisation) {
        info.timeframe = timeframeParser(ui->comboBox_timeframe_depos->currentIndex(), 0);
    } else {
        info.timeframe = timeframeParser(ui->comboBox_timeframe_depos->currentIndex(), info.timeframe_type);
    }
    if (info.timeframe == 0) {
        QMessageBox::critical(this, "Error", "INVALID INPUT!<DEPOSIT>");
    } else {
        info.interest_rate = ui->lineEdit_rate_2->text().toDouble();
        info.tax_rate = ui->lineEdit_tax->text().toDouble();


        if (ui->checkBox_supplemention->isChecked()) {
            info.supplement_type = ui->comboBox_deposit->currentIndex();
            info.supplement_date_arr[0] = ui->dateEdit_depo->date().day();
            info.supplement_date_arr[1] = ui->dateEdit_depo->date().month();
            info.supplement_date_arr[2] = ui->dateEdit_depo->date().year();
            info.supplement_value = ui->lineEdit_depo->text().toDouble();
        }
        if (ui->checkBox_elim->isChecked()) {
            info.elimination_type = ui->comboBox_elim->currentIndex();
            info.elimination_date_arr[0] = ui->dateEdit_elim->date().day();
            info.elimination_date_arr[1] = ui->dateEdit_elim->date().month();
            info.elimination_date_arr[2] = ui->dateEdit_elim->date().year();
            info.elimination_value = ui->lineEdit_elim->text().toDouble();
        }
        MainDeposit(&info);
        QString interset = QString::asprintf("%.2lf", info.total_profit);
        QString total_sum = QString::asprintf("%.2lf", info.total_sum);
        QString total_tax = QString::asprintf("%.2lf", info.total_tax);

        ui->label_interest_output->setText(interset);
        ui->label_total_sum_output->setText(total_sum);
        ui->label_tax_output->setText(total_tax);
    }
}


// ------------------
