#include "deposit.h"

#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QWidget(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
}

Deposit::~Deposit() { delete ui; }

void Deposit::on_pushButton_calculate_clicked() {
  controller.updateViewModel(
      ui->lineEdit_amount, ui->comboBox_timeframe, ui->lineEdit_rate,
      ui->lineEdit_tax, ui->comboBox_frequency, ui->checkBox_capitalization,
      ui->checkBox_supplementions, ui->lineEdit_supp, ui->comboBox_supp,
      ui->dateEdit_supp, ui->checkBox_eliminations, ui->lineEdit_elim,
      ui->comboBox_elim, ui->dateEdit_elim, ui->label_procent, ui->label_total,
      ui->label_tax);
}
