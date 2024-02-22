#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_pushButton_calculate_clicked()
{
    controller.updateViewModel(ui->lineEdit_amount, ui->lineEdit_rate, ui->comboBox_timeframe, ui->comboBox_type, ui->label_month_pay, ui->label_overpayment, ui->label_total_sum);
}

