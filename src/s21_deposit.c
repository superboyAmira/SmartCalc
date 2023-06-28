#include "s21_calc.h"

void round_2(double *num) {
    *num = (int)(*num * 100 + 0.5) / 100.0;
}

void Tax(deposit_data *info) {
    if (info->total_profit > 1000000 * 0.075) {
        info->total_tax = (info->total_profit - 1000000 * 0.075) * info->tax_rate / 100;
        info->total_profit = info->total_profit - info->total_tax;
        info->total_sum = info->sum + info->total_profit;
    } else {
        info->total_tax = 0.0;
    }
}

void MainDeposit(deposit_data *info) {
    const double month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30.9976};
    const double kvartal_day[4] = {90, 91, 92, 91.9976};
    
    if (!info->capitalisation) {
        for (int i = 0; i < info->timeframe; i++) {
            info->total_profit += info->sum * ((info->interest_rate / 100.0) / 365 /** month_day[i % 12]*/);
        }
        round_2(&info->total_profit);
        info->total_sum = info->sum;
    } else {
        double balance[1000] = {0};
        balance[0] = info->sum;

        for (int i = 0; i <= info->timeframe; i++) {
            if (info->supplement_date - 1 == i) {
                balance[i] += info->supplement_value;
            } else if (info->elimination_date - 1 == i) {
                balance[i] -= info->elimination_value;
            }
        }

        if (info->timeframe_type == 0) { // days
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] += balance[i - 1] + balance[i - 1] * (((info->interest_rate / 100.0) / 365));
            }
        } else if (info->timeframe_type == 1) { // moth
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] += balance[i - 1] + balance[i - 1] * (((info->interest_rate / 100.0) / 365) * month_day[(i - 1) % 12]);
            }
        } else if (info->timeframe_type == 2) { // quater
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] += balance[i - 1] + balance[i - 1] * (((info->interest_rate / 100.0) / 365) * kvartal_day[(i- 1) % 4]);
            }
        } else { // year
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] = balance[i - 1] + balance[i - 1] * (((info->interest_rate / 100.0) / 365) * 365);
            }
        }
        info->total_sum = balance[info->timeframe];
        info->total_profit = info->total_sum - info->sum;
        info->total_rate = info->total_profit / info->sum * 100.0;
        round_2(&info->total_sum);
        round_2(&info->total_profit);
        round_2(&info->total_rate);
    }
    
    

    Tax(info);
}

int main() {
    deposit_data info = {0};
    info.interest_rate = 12;
    info.timeframe = 12;
    info.timeframe_type = 1;
    info.capitalisation = true;
    info.sum = 100000;
    info.tax_rate = 13.0;

    // info.supplement_date = 1;
    // info.supplement_value = 1000; 
    MainDeposit(&info);


    return 0;

}