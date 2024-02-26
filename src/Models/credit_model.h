#ifndef CREDIT_MODEL_H
#define CREDIT_MODEL_H

#include <cmath>
#include <cstddef>

namespace s21 {

enum credit_t { ANN, DIFF };

class CreditModel {
 public:
  CreditModel() noexcept {
    amount_ = 0;
    rate_ = 0;
    months_ = 0;
    type_ = ANN;

    month_pay_ = 0;
    month_pay_diff_min_ = 0;
    overpayment_ = 0;
    total_ = 0;
  };

  ~CreditModel() noexcept = default;

  void SetAmount(double amount) noexcept { amount_ = amount; };

  void SetRate(double rate) noexcept { rate_ = rate; };

  void SetMonths(int moths) noexcept { months_ = moths; };

  void SetType(credit_t type) noexcept { type_ = type; };

  double GetMonthPay() const noexcept { return month_pay_; };

  double GetMinDiffMonthPay() const noexcept { return month_pay_diff_min_; };

  double GetOverpayment() const noexcept { return overpayment_; };

  double GetTotal() const noexcept { return total_; };

  credit_t GetType() const noexcept { return type_; };

  void UpdateModel() noexcept {
    if (type_ == ANN) {
      month_pay_ = amount_ * (rate_ / (100 * 12)) /
                   (1 - pow(1 + (rate_ / (100 * 12)), -1 * months_));
      month_pay_ = (int)(month_pay_ * 100 + 0.5) / 100.0;
      overpayment_ = (month_pay_ * months_) - amount_;
      total_ = overpayment_ + amount_;
    } else {
      double pay_main_credit = (amount_ / months_);
      month_pay_ =
          pay_main_credit + ((amount_ * (rate_ / 100) * 30.416666667) / 365);
      month_pay_ = (int)(month_pay_ * 100 + 0.5) / 100.0;
      total_ += month_pay_;

      size_t pos = months_ - 1;
      for (double max_sum = amount_ - pay_main_credit; pos > 0;
           max_sum -= pay_main_credit, pos--) {
        month_pay_diff_min_ =
            pay_main_credit + ((max_sum * (rate_ / 100) * 30.416666667) / 365);
        month_pay_diff_min_ = (int)(month_pay_diff_min_ * 100 + 0.5) / 100.0;
        total_ += month_pay_diff_min_;
      }
      overpayment_ = total_ - amount_;
    }
  };

  void clear() noexcept {
    amount_ = 0;
    rate_ = 0;
    months_ = 0;
    type_ = ANN;

    month_pay_ = 0;
    month_pay_diff_min_ = 0;
    overpayment_ = 0;
    total_ = 0;
  };

 private:
  double amount_;
  double rate_;
  int months_;
  credit_t type_;

  double month_pay_;
  double month_pay_diff_min_;
  double overpayment_;
  double total_;
};

}  // namespace s21

#endif  // CREDIT_MODEL_H
