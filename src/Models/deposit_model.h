#ifndef DEPOSIT_MODEL_H
#define DEPOSIT_MODEL_H

#include <cmath>
#include <iomanip>
#include <vector>

namespace s21 {

enum elim_supp_t { ONETIME, MONTH, QUATER, YEAR };
enum timeframe_t { TDAY, TMONTH, TQUATER, TYEAR };

class DepositModel {
 public:
  DepositModel() noexcept {
    amount_ = 0;
    timeframe_type_ = TDAY;
    timeframe_ = 0;
    interest_rate_ = 0;
    tax_rate_ = 0;
    capitalisation_ = false;
    supplement_type_ = ONETIME;
    supplement_date_ = 0;
    supplement_value_ = 0;
    elimination_type_ = ONETIME;
    elimination_date_ = 0;
    elimination_value_ = 0;
    total_rate_ = 0;
    total_tax_ = 0;
    total_sum_ = 0;
    total_profit_ = 0;
  };

  ~DepositModel() noexcept = default;

  void SetAmount(double amount) noexcept { amount_ = amount; };

  void SetTimeframeType(timeframe_t type) noexcept { timeframe_type_ = type; };

  void SetTimeframe(int timeframe) noexcept { timeframe_ = timeframe; };

  void SetRate(double rate) noexcept { interest_rate_ = rate; };

  void SetTaxRate(double rate) noexcept { tax_rate_ = rate; };

  void SetCapitalisation() noexcept { capitalisation_ = true; };

  void SetEliminationData(elim_supp_t type, double value,
                          std::vector<int> date_list) noexcept {
    elimination_type_ = type;
    elimination_value_ = value;
    elimination_date_arr_.swap(date_list);
  };

  void SetSupplementionData(elim_supp_t type, double value,
                            std::vector<int> date_list) noexcept {
    supplement_type_ = type;
    supplement_value_ = value;
    supplement_date_arr_.swap(date_list);
  };

  double GetTotalAmount() const noexcept { return total_sum_; };

  double GetTotalProfit() const noexcept { return total_profit_; };

  double GetTotalTax() const noexcept { return total_tax_; };

  double GetTotalRate() const noexcept { return total_rate_; };

  void ClearModel() noexcept {
    amount_ = 0;
    timeframe_type_ = TDAY;
    timeframe_ = 0;
    interest_rate_ = 0;
    tax_rate_ = 0;
    capitalisation_ = false;

    supplement_date_arr_.clear();
    supplement_type_ = ONETIME;
    supplement_date_ = 0;
    supplement_value_ = 0;

    elimination_date_arr_.clear();
    elimination_type_ = ONETIME;
    elimination_date_ = 0;
    elimination_value_ = 0;

    total_rate_ = 0;
    total_tax_ = 0;
    total_sum_ = 0;
    total_profit_ = 0;
  };

  void UpdateModel() noexcept {
    if (!capitalisation_) timeframe_type_ = TDAY;
    parserDate(true, true);

    double balance[1000] = {0};
    balance[0] = amount_;

    for (int i = 0; i <= timeframe_; i++) {
      if (supplement_type_ == ONETIME && supplement_value_ > 0) {
        addSupp(balance);
        break;
      } else if (supplement_type_ == MONTH) {
        addSupp(balance);

        supplement_date_arr_[1]++;
        if (supplement_date_arr_[1] > 12) {
          supplement_date_arr_[2]++;
          supplement_date_arr_[1] = 1;
        }
        supplement_date_ = 0;
        parserDate(true, false);
      } else if (supplement_type_ == QUATER) {
        addSupp(balance);
        supplement_date_arr_[1] += 3;
        if (supplement_date_arr_[1] > 12) {
          supplement_date_arr_[2]++;
          supplement_date_arr_[1] = supplement_date_arr_[1] - 12;
        }
        supplement_date_ = 0;
        parserDate(true, false);
      } else if (supplement_type_ == YEAR) {
        addSupp(balance);
        supplement_date_arr_[2]++;
        supplement_date_ = 0;
        parserDate(true, false);
      }
      if (elimination_type_ == ONETIME && elimination_value_ > 0) {
        addElim(balance);
        break;
      } else if (elimination_type_ == MONTH) {
        addElim(balance);

        elimination_date_arr_[1]++;
        if (elimination_date_arr_[1] > 12) {
          elimination_date_arr_[2]++;
          elimination_date_arr_[1] = 1;
        }
        elimination_date_ = 0;
        parserDate(false, true);
      } else if (elimination_type_ == QUATER) {
        addElim(balance);
        elimination_date_arr_[1] += 3;
        if (elimination_date_arr_[1] > 12) {
          elimination_date_arr_[2]++;
          elimination_date_arr_[1] = elimination_date_arr_[1] - 12;
        }
        elimination_date_ = 0;
        parserDate(false, true);
      } else if (elimination_type_ == YEAR) {
        addElim(balance);
        elimination_date_arr_[2]++;
        elimination_date_ = 0;
        parserDate(false, true);
      }
    }

    if (!capitalisation_) {
      /*
       * добавить пополнения и снятия и итоговая сумма с их учетом
       */
      for (int i = 1; i <= timeframe_; i++) {
        total_profit_ += balance[i - 1] * ((interest_rate_ / 100.0) / 365);
        balance[i] += balance[i - 1];
      }
      round_2(total_profit_);
      total_sum_ = balance[timeframe_];
      total_rate_ = total_profit_ / amount_ * 100.0;
      round_2(total_rate_);
    } else {
      if (timeframe_type_ == TDAY) {
        for (int i = 1; i <= timeframe_; i++) {
          balance[i] += balance[i - 1] +
                        balance[i - 1] * (((interest_rate_ / 100.0) / 365));
        }
      } else if (timeframe_type_ == TMONTH) {
        for (int i = 1; i <= timeframe_; i++) {
          balance[i] += balance[i - 1] +
                        balance[i - 1] * (((interest_rate_ / 100.0) / 365) *
                                          kDayInMonth[(i - 1) % 12]);
        }
      } else if (timeframe_type_ == TQUATER) {
        for (int i = 1; i <= timeframe_; i++) {
          balance[i] += balance[i - 1] +
                        balance[i - 1] * (((interest_rate_ / 100.0) / 365) *
                                          kDayInQuater[(i - 1) % 4]);
        }
      } else {
        for (int i = 1; i <= timeframe_; i++) {
          balance[i] =
              balance[i - 1] +
              balance[i - 1] * (((interest_rate_ / 100.0) / 365) * 365);
        }
      }
      total_sum_ = balance[timeframe_];
      total_profit_ += total_sum_ - amount_;
      total_rate_ = total_profit_ / amount_ * 100.0;
      round_2(total_sum_);
      round_2(total_profit_);
      round_2(total_rate_);
    }
    Tax();
  };

 private:
  /*
   * сумма вклада, срок размещения,
   * процентная ставка, налоговая ставка, периодичность выплат,
   * капитализация процентов, список пополнений, список частичных снятий
   */
  double amount_;
  timeframe_t timeframe_type_;
  int timeframe_;
  double interest_rate_;
  double tax_rate_;
  bool capitalisation_;

  std::vector<int> supplement_date_arr_;
  elim_supp_t supplement_type_;
  int supplement_date_;
  double supplement_value_;

  std::vector<int> elimination_date_arr_;
  elim_supp_t elimination_type_;
  int elimination_date_;
  double elimination_value_;
  /*
   * Выход: начисленные проценты, сумма налога, сумма на вкладе к концу срока
   */
  double total_rate_;
  double total_tax_;
  double total_sum_;
  double total_profit_;

  const double kDayInMonth[12] = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 30.9976};
  const double kDayInQuater[4] = {90, 91, 92, 91.9976};

  void parserDate(bool supp, bool elim) {
    if (timeframe_type_ == TDAY) {
      if (supplement_value_ != 0.0 && supp) {
        for (int i = 0; i < (supplement_date_arr_[1] +
                             (12 * (supplement_date_arr_[2] - 2024)) - 1);
             i++) {
          supplement_date_ += round(kDayInMonth[i % 12]);
        }
        supplement_date_ += supplement_date_arr_[0];
      }
      if (elimination_value_ != 0.0 && elim) {
        for (int i = 0; i < (elimination_date_arr_[1] +
                             (12 * (elimination_date_arr_[2] - 2024)) - 1);
             i++) {
          elimination_date_ += round(kDayInMonth[i % 12]);
        }
        elimination_date_ += elimination_date_arr_[0];
      }
    } else if (timeframe_type_ == TMONTH) {
      if (supplement_value_ != 0.0 && supp) {
        supplement_date_ =
            supplement_date_arr_[1] + 12 * (supplement_date_arr_[2] - 2024);
      }
      if (elimination_value_ != 0.0 && elim) {
        elimination_date_ =
            elimination_date_arr_[1] + 12 * (elimination_date_arr_[2] - 2024);
      }
    } else if (timeframe_type_ == TQUATER) {
      if (supplement_value_ != 0.0 && supp) {
        supplement_date_ = supplement_date_arr_[1];
        if (supplement_date_ >= 1 && supplement_date_ <= 3)
          supplement_date_ = 1 + 4 * (supplement_date_arr_[2] - 2024);
        else if (supplement_date_ >= 4 && supplement_date_ <= 6)
          supplement_date_ = 2 + 4 * (supplement_date_arr_[2] - 2024);
        else if (supplement_date_ >= 7 && supplement_date_ <= 9)
          supplement_date_ = 3 + 4 * (supplement_date_arr_[2] - 2024);
        else if (supplement_date_ >= 10 && supplement_date_ <= 12)
          supplement_date_ = 4 + 4 * (supplement_date_arr_[2] - 2024);
      }
      if (elimination_value_ != 0.0 && elim) {
        elimination_date_ = elimination_date_arr_[1];
        if (elimination_date_ >= 1 && elimination_date_ <= 3)
          elimination_date_ = 1 + 4 * (elimination_date_arr_[2] - 2024);
        else if (elimination_date_ >= 4 && elimination_date_ <= 6)
          elimination_date_ = 2 + 4 * (elimination_date_arr_[2] - 2024);
        else if (elimination_date_ >= 7 && elimination_date_ <= 9)
          elimination_date_ = 3 + 4 * (elimination_date_arr_[2] - 2024);
        else if (elimination_date_ >= 10 && elimination_date_ <= 12)
          elimination_date_ = 4 + 4 * (elimination_date_arr_[2] - 2024);
      }
    } else if (timeframe_type_ == 3) {
      if (supplement_value_ > 0.0 && supp) {
        supplement_date_ = supplement_date_arr_[2] - 2024;
      }
      if (elimination_value_ > 0.0 && elim) {
        elimination_date_ = elimination_date_arr_[2] - 2024;
      }
    }
  };

  void addSupp(double *balance) noexcept {
    for (int i = 0; i <= timeframe_; i++) {
      if (supplement_date_ - 1 == i) {
        balance[i] += supplement_value_;
        if (capitalisation_) total_profit_ -= supplement_value_;
      }
    }
  };

  void addElim(double *balance) noexcept {
    for (int i = 0; i <= timeframe_; i++) {
      if (elimination_date_ - 1 == i) {
        balance[i] -= elimination_value_;
        if (capitalisation_) total_profit_ += elimination_value_;
      }
    }
  };

  void Tax() noexcept {
    if (total_profit_ > 1000000 * 0.075) {
      total_tax_ = (total_profit_ - 1000000 * 0.075) * tax_rate_ / 100;
      total_profit_ = total_profit_ - total_tax_;
      total_sum_ = amount_ + total_profit_;
    } else {
      total_tax_ = 0.0;
    }
  };

  void round_2(double &value) const noexcept {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    stream >> value;
  }
};

}  // namespace s21

#endif  // DEPOSIT_MODEL_H
