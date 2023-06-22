#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../s21_calc.h"
#include "../s21_calc.c"

#include <QDebug>

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
    connect(ui->pushButton_unMin_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_clear_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_equal_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_plus_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_minus_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_mult_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_del_5, SIGNAL(clicked()), this, SLOT(ViewOperators()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(ViewOperators()));

    connect(ui->pushButton_draw_graph, SIGNAL(clicked()), this, SLOT(DrawGraph()));
}

// another func

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FormatFont() {
    static int max_size = 9;

    static int font_size = 48;

    if (ui->label_output->text().length() == 0) {
        max_size = 9;

        font_size = 48;

        QFont tmp_font = ui->label_output->font();

        tmp_font.setPixelSize(font_size);

        ui->label_output->setFont(tmp_font);
    }

    if (ui->label_output->text().length() > max_size) {
        font_size -= 4;

        (font_size > 24) ? max_size += 1 : max_size += 12;

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

        QString all_nums = (ui->label_output->text());

        (all_nums.at(0) == '-') ? all_nums.remove(0, 1) : all_nums.insert(0, '-');

        ui->label_output->setText(all_nums);

    } else if (button->text() == "AC" && ui->label_output->text().length() > 0) {

        ui->label_output->clear();

    } else if (button->text() == "." && ui->label_output->text().length() > 0) {

        if (ui->label_output->text() != "") {
            ui->label_output->setText(ui->label_output->text() + ".");
        }

    } else if (button->text() == "=" && (ui->label_output->text().length() > 0 && ui->label_output->text().toDouble() == 0.0 && ui->label_output->text().at(0) != '0')) {

        char *equation = QStringToChar(ui->label_output->text());

        double x = 0.0;
        bool status = true;

        if (ui->input_x->isChecked()) {
            x = ui->lineEdit_input_x->text().toDouble();
            if (ui->lineEdit_input_x->text() == "") {
                QMessageBox::critical(this, "Error", "INVALID INPUT!");
            }
        } else {
            if (ui->label_output->text().contains('x')) {
                QMessageBox::critical(this, "Error", "INVALID INPUT!");
            }
        }

        double result_dbl = Calc(equation, x, &status);

        if (result_dbl == 0.0 && !status) {
            QMessageBox::critical(this, "Error", "INVALID INPUT!");
        } else {
            QString result_qstr = (fabs(result_dbl - (int)result_dbl) < 0.00000001) ? QString::asprintf("%d", (int)result_dbl) : QString::asprintf("%.7lf", result_dbl);

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
    if (ui->label_output->text() != "" && ui->spinBox_x_max->value() != 0 && ui->spinBox_x_min->value() != 0
            && ui->spinBox_y_min->value() != 0 && ui->spinBox_y_max->value() != 0 && CheckEquation(QStringToChar(ui->label_output->text()))) {
        bool _t = true;
        step = 0.1;
        xBegin = ui->spinBox_x_min->value();
        xEnd = ui->spinBox_x_max->value() + step;

        ui->widget->xAxis->setRange(xBegin,xEnd);
        ui->widget->yAxis->setRange(ui->spinBox_y_min->value(), ui->spinBox_y_max->value());

        for (X = xBegin; X <= xEnd; X += step) {
            x.push_back(X);
            y.push_back(Calc(QStringToChar(ui->label_output->text()), X, &_t));
        }

        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x,y);
        ui->widget->replot();
        x.clear();
        y.clear();
    } else {
        QMessageBox::critical(this, "Error", "INVALID INPUT!");
    }
}

// ------------------
