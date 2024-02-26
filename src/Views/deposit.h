#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

#include "../Controllers/deposit_controller.h"

namespace Ui {
class Deposit;
}

class Deposit : public QWidget {
  Q_OBJECT

 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

 private slots:
  void on_pushButton_calculate_clicked();

 private:
  Ui::Deposit *ui;

  s21::DepositController controller;
};

#endif  // DEPOSIT_H
