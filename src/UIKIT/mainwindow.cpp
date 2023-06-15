#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ViewBracket() {
    QPushButton * button = static_cast<QPushButton*>(QObject::sender());
    ui->label_output->setText(ui->label_output->text() + button->text());
}


void MainWindow::FormatFont() {
    static int max_size = 9;
    static int font_size = 48;
//    qDebug() << "\nm_size" << max_size;
//    qDebug() << "f_size" << font_size;
//    qDebug() << "Len" << ui->label_output->text().length();

    if (ui->label_output->text().length() > max_size) {
        font_size -= 4;
        (font_size > 24) ? max_size += 1 : max_size += 12;

        QFont tmp_font = ui->label_output->font();
//        qDebug() << "font" << tmp_font;

        tmp_font.setPixelSize(font_size);
        ui->label_output->setFont(tmp_font);

    }
}

void MainWindow::ViewNums() {
    FormatFont();

    QPushButton * button = static_cast<QPushButton*>(QObject::sender());
    ui->label_output->setText(ui->label_output->text() + button->text());
}

void MainWindow::ViewFuncs() {
    FormatFont();

    QPushButton * button = static_cast<QPushButton*>(QObject::sender());
    ui->label_output->setText(ui->label_output->text() + button->text().toLower());
}


void MainWindow::ViewOperators()
{
    FormatFont();
    QPushButton * button = static_cast<QPushButton*>(QObject::sender());

    if (button->objectName() == "pushButton_unMin") {
        double all_nums = (ui->label_output->text()).toDouble();
        all_nums = 0 - all_nums;
        QString output = QString::number(all_nums, 'g', 255);
        ui->label_output->setText(output);
    } else if (button->objectName() == "pushButton_clear") {
        ui->label_output->clear();
    } else if (button->objectName() == "pushButton_coma") {
        if (ui->label_output->text().contains('.') == false && ui->label_output->text() != "") {
            ui->label_output->setText(ui->label_output->text() + ".");
        }
    } else if (button->objectName() == "pushButton_equal") {
        // здесь как раз вставим функцию вычисления

    } else {
        QChar tmp_qchar = ui->label_output->text().at(ui->label_output->text().length() - 1);

        if ((tmp_qchar.isNumber() || tmp_qchar == ')') && button->objectName() != "pushButton_mod") {
            ui->label_output->setText(ui->label_output->text() + button->text());
        } else if (button->objectName() == "pushButton_mod") {
            ui->label_output->setText(ui->label_output->text() + "mod");
        }
    }
}
