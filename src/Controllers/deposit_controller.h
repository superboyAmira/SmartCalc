#ifndef DEPOSIT_CONTROLLER_H
#define DEPOSIT_CONTROLLER_H

#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QLabel>
#include <QLineEdit>

#include "../Models/deposit_model.h"

namespace s21 {

class DepositController {
 public:
  void updateViewModel(QLineEdit* amount, QComboBox* timeframe, QLineEdit* rate,
                       QLineEdit* tax, QComboBox* frequency,
                       QCheckBox* capitalization, QCheckBox* supplementions,
                       QLineEdit* supp_value, QComboBox* supp_frequency,
                       QDateEdit* supp_day, QCheckBox* eliminations,
                       QLineEdit* elim_value, QComboBox* elim_frequency,
                       QDateEdit* elim_day, QLabel* label_procent,
                       QLabel* label_total, QLabel* label_tax) noexcept {
    model.ClearModel();
    if (capitalization->isChecked()) {
      model.SetCapitalisation();
    }
    model.SetAmount(amount->text().toDouble());
    model.SetTimeframeType((s21::timeframe_t)frequency->currentIndex());
    model.SetTimeframe(ParseTimeframe(timeframe, frequency));
    model.SetRate(rate->text().toDouble());
    model.SetTaxRate(tax->text().toDouble());
    if (supplementions->isChecked()) {
      model.SetSupplementionData(
          (s21::elim_supp_t)supp_frequency->currentIndex(),
          supp_value->text().toDouble(),
          std::vector<int>{supp_day->date().day(), supp_day->date().month(),
                           supp_day->date().year()});
    }
    if (eliminations->isChecked()) {
      model.SetSupplementionData(
          (s21::elim_supp_t)elim_frequency->currentIndex(),
          elim_value->text().toDouble(),
          std::vector<int>{elim_day->date().day(), elim_day->date().month(),
                           elim_day->date().year()});
    }
    model.UpdateModel();
    label_procent->setText(QString::asprintf("%.2lf", model.GetTotalRate()));
    label_total->setText(QString::asprintf("%.2lf", model.GetTotalProfit()));
    label_tax->setText(QString::asprintf("%.2lf", model.GetTotalTax()));
  };

 private:
  DepositModel model;

  /*
   * Возвращяет количество временных отрезков вклада
   */
  int ParseTimeframe(QComboBox* time, QComboBox* frequency) const noexcept {
    const double kMonthDay[12] = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};

    int result = 0;
    int type = frequency->currentIndex();

    switch (time->currentIndex()) {
      case 0:
        if (type == 0)
          result = 31;
        else if (type == 1)
          result = 1;
        break;
      case 1:
        if (type == 0)
          for (int i = 0; i < 3; i++) result += kMonthDay[i];
        else if (type == 1)
          result = 3;
        break;
      case 2:
        if (type == 0)
          for (int i = 0; i < 6; i++) result += kMonthDay[i];
        else if (type == 1)
          result = 6;
        else if (type == 2)
          result = 1;
        break;
      case 3:
        if (type == 0)
          for (int i = 0; i < 9; i++) result += kMonthDay[i];
        else if (type == 1)
          result = 9;
        else if (type == 2)
          result = 2;
        break;
      case 4:
        if (type == 0)
          for (int i = 0; i < 12; i++) result += kMonthDay[i];
        else if (type == 1)
          result = 12;
        else if (type == 2)
          result = 4;
        else if (type == 3)
          result = 1;
        break;
      case 5:
        if (type == 0)
          for (int i = 0; i < 24; i++) result += kMonthDay[i % 12];
        else if (type == 1)
          result = 24;
        else if (type == 2)
          result = 8;
        else if (type == 3)
          result = 2;
        break;
      case 6:
        if (type == 0)
          for (int i = 0; i < 36; i++) result += kMonthDay[i % 12];
        else if (type == 1)
          result = 36;
        else if (type == 2)
          result = 12;
        else if (type == 3)
          result = 3;
        break;
      case 7:
        if (type == 0)
          for (int i = 0; i < 48; i++) result += kMonthDay[i % 12];
        else if (type == 1)
          result = 48;
        else if (type == 2)
          result = 16;
        else if (type == 3)
          result = 4;
        break;
      case 8:
        if (type == 0)
          for (int i = 0; i < 60; i++) result += kMonthDay[i % 12];
        else if (type == 1)
          result = 60;
        else if (type == 2)
          result = 20;
        else if (type == 3)
          result = 5;
        break;
      case 9:
        if (type == 0)
          for (int i = 0; i < 120; i++) result += kMonthDay[i % 12];
        else if (type == 1)
          result = 120;
        else if (type == 2)
          result = 40;
        else if (type == 3)
          result = 10;
        break;
      case 10:
        if (type == 0)
          for (int i = 0; i < 240; i++) result += kMonthDay[i % 12];
        else if (type == 1)
          result = 240;
        else if (type == 2)
          result = 80;
        else if (type == 3)
          result = 20;
        break;
    }

    return result;
  };
};

}  // namespace s21

#endif  // DEPOSIT_CONTROLLER_H
