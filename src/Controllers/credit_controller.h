#ifndef CREDIT_CONTROLLER_H
#define CREDIT_CONTROLLER_H

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>

#include "../Models/credit_model.h"

namespace s21 {

class CreditController {
 public:
  void updateViewModel(QLineEdit* amount, QLineEdit* rate, QComboBox* timeframe,
                       QComboBox* type, QLabel* month_pay, QLabel* overpayment,
                       QLabel* total) {
    bool status = true;
    model.clear();
    model.SetAmount(amount->text().toDouble(&status));
    model.SetRate(rate->text().toDouble(&status));
    model.SetMonths(ParseMonths(timeframe));
    model.SetType(ParseType(type));

    if (!status) {
      QMessageBox::critical(amount, "Error", "BAD INPUT");
      return;
    }
    model.UpdateModel();
    if (model.GetType() == credit_t::DIFF) {
      month_pay->setText(
          QString::asprintf("%.2lf", model.GetMonthPay()) + "..." +
          QString::asprintf("%.2lf", model.GetMinDiffMonthPay()));
    } else {
      month_pay->setText(QString::asprintf("%.2lf", model.GetMonthPay()));
    }
    overpayment->setText(QString::asprintf("%.2lf", model.GetOverpayment()));
    total->setText(QString::asprintf("%.2lf", model.GetTotal()));
  };

 private:
  CreditModel model;

  int ParseMonths(QComboBox* timeframe) const noexcept {
    int credit_month = 0;
    switch (timeframe->currentIndex()) {
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
    return credit_month;
  };

  credit_t ParseType(QComboBox* type) const noexcept {
    credit_t res_type = credit_t::ANN;
    switch (type->currentIndex()) {
      case 0:
        res_type = credit_t::ANN;
        break;
      case 1:
        res_type = credit_t::DIFF;
        break;
    }
    return res_type;
  };
};

}  // namespace s21

#endif  // CREDIT_CONTROLLER_H
