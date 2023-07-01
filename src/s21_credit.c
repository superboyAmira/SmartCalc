#include "s21_calc.h"


void MainCredit(credit_data *info) {
    if (info->type == ANN) {
        info->month_pay_ann = info->credit_sum * (info->rate / (100 * 12)) / (1 - pow(1 + (info->rate / (100 * 12)), -1 * info->timeframe));
        info->month_pay_ann = (int)(info->month_pay_ann * 100 + 0.5) / 100.0;
        info->overpayment = (info->month_pay_ann * info->timeframe) - info->credit_sum;
        info->total_payment = info->overpayment + info->credit_sum;
    } else {
        double pay_main_credit = (info->credit_sum / info->timeframe);
        info->month_pay_diff_max = pay_main_credit + ((info->credit_sum * (info->rate / 100) * 30.416666667) / 365);
        info->month_pay_diff_max = (int)(info->month_pay_diff_max * 100 + 0.5) / 100.0;
        info->total_payment += info->month_pay_diff_max;

        size_t pos = info->timeframe - 1;
        for (double max_sum = info->credit_sum - pay_main_credit; pos > 0; max_sum -= pay_main_credit, pos--) {
            info->month_pay_diff_min = pay_main_credit + ((max_sum * (info->rate / 100) * 30.416666667) / 365);
            info->month_pay_diff_min = (int)(info->month_pay_diff_min * 100 + 0.5) / 100.0;
            info->total_payment += info->month_pay_diff_min;
        }
        info->overpayment = info->total_payment - info->credit_sum;
    }
}
