#include "s21_calc.h"

void round_2(double *num) {
    *num = (int)(*num * 100 + 0.5) / 100.0;
}

typedef struct deposit_data {
    /*сумма вклада, срок размещения,
     процентная ставка, налоговая ставка, периодичность выплат, 
    капитализация процентов, список пополнений, список частичных снятий*/
    double sum;
    int timeframe;
    double interest_rate;
    double tax_rate;
    int frequency;
    bool capitalisation;

    double supplement[2];
    double eliminations[2];
    /*Выход: начисленные проценты, сумма налога, сумма на вкладе к концу срока*/
    double total_rate;
    double total_tax;
    double total_sum;
    double total_profit;
} deposit_data;

void Tax(deposit_data *info) {
    if (info->total_profit > 42500) {
        info->total_tax = (info->total_profit - 42500.0) * info->tax_rate / 100;
        info->total_profit = info->total_profit - info->total_tax;
        info->total_sum = info->sum + info->total_profit;
    } else {
        info->total_tax = 0.0;
    }
}

void MainDeposit(deposit_data *info) {
    double balance[1000] = {0};
    double month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30.9976};
    balance[0] = info->sum;

    if (info->capitalisation) {
        for (int i = 1; i <= info->timeframe; i++) {
            balance[i] = balance[i-1] + balance[i - 1] * (((info->interest_rate / 100.0) / 365) * month_day[(i - 1) % 12]);
            round_2(&balance[i]);
        }
        info->total_sum = balance[info->timeframe];
        info->total_profit = info->total_sum - info->sum;
        info->total_rate = (balance[info->timeframe] - info->sum) / info->sum * 100.0;
        round_2(&info->total_rate);
    } else {
        double tmp = 0;
        while (info->timeframe > 0) {
            info->timeframe--;
            tmp += 30.4167;
            if ((int)tmp == 365) {
                tmp == 365;
            }
        }
        info->timeframe = (int)tmp;

        for (int i = 0; i < info->timeframe; i++) {
            // balance[i] = info->sum;
            info->total_profit += info->sum * ((info->interest_rate / 100.0) / 365);
            
        }
        round_2(&info->total_profit);
        info->total_sum = info->sum + info->total_profit;
    }
    
    

    Tax(info);
}

int main() {
    deposit_data info = {0};
    info.interest_rate = 12;
    info.timeframe = 12;
    info.capitalisation = false;
    info.sum = 1000000;
    info.tax_rate = 13.0;
    MainDeposit(&info);


    return 0;

}