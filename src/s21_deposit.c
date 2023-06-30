#include "s21_calc.h"

const double month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30.9976};
const double kvartal_day[4] = {90, 91, 92, 91.9976};

void round_2(double *num) {
    *num = (int)(*num * 100 + 0.5) / 100.0;
}

void parserDate(deposit_data *info) {
    // if ((info->supplement_date_arr[0] == 1 && info->supplement_date_arr[1] == 1 && info->supplement_date_arr[2] == 2023 )) {
    //     if (info->supplement_type == 0) {
    //         info->supplement_value = 0;
    //     } else if (info->supplement_type == 1) {
    //         info->supplement_date_arr[1]++;
    //     } else if (info->supplement_type == 2) {
    //         info->supplement_date_arr[1] += 3;
    //     } else if (info->supplement_type == 3) {
    //         info->supplement_date_arr[2]++;
    //     }
    // } else if (info->elimination_date_arr[0] == 1 && info->elimination_date_arr[1] == 1 && info->elimination_date_arr[2] == 2023 ) {
    //      if (info->elimination_type == 0) {
    //         info->elimination_value = 0;
    //     } else if (info->elimination_type == 1) {
    //         info->elimination_date_arr[1]++;
    //     } else if (info->elimination_type == 2) {
    //         info->elimination_date_arr[1] += 3;
    //     } else if (info->elimination_type == 3) {
    //         info->elimination_date_arr[2]++;
    //     }
    // }

    if (info->timeframe_type == 0) {
        if (info->supplement_value != 0.0) {
            for (int i = 0; i < (info->supplement_date_arr[1] + (12 * (info->supplement_date_arr[2] - 2023)) - 1); i++) {
                info->supplement_date += round(month_day[i % 12]);
            }
            info->supplement_date += info->supplement_date_arr[0];
        }
        if (info->elimination_value != 0.0) {
            for (int i = 0; i < (info->elimination_date_arr[1] + (12 * (info->elimination_date_arr[2] - 2023)) - 1); i++) {
                info->elimination_date += round(month_day[i % 12]);
            }
            info->elimination_date += info->elimination_date_arr[0];
        }   
    } else if (info->timeframe_type == 1) {
        if (info->supplement_value != 0.0) {
            info->supplement_date = info->supplement_date_arr[1] + 12 * (info->supplement_date_arr[2] - 2023);
        }
        if (info->elimination_value != 0.0) {
            info->elimination_date = info->elimination_date_arr[1] + 12 * (info->elimination_date_arr[2] - 2023);
        }  
    } else if (info->timeframe_type == 2) {
        if (info->supplement_value != 0.0) {
            info->supplement_date = info->supplement_date_arr[1];
            if (info->supplement_date >= 1 && info->supplement_date <= 3) info->supplement_date = 1 + 4 * (info->supplement_date_arr[2] - 2023);
            else if (info->supplement_date >= 4 && info->supplement_date <= 6) info->supplement_date = 2 + 4 * (info->supplement_date_arr[2] - 2023);
            else if (info->supplement_date >= 7 && info->supplement_date <= 9) info->supplement_date = 3 + 4 * (info->supplement_date_arr[2] - 2023);
            else if (info->supplement_date >= 10 && info->supplement_date <= 12) info->supplement_date = 4 + 4 * (info->supplement_date_arr[2] - 2023);
        }
        if (info->elimination_value != 0.0) {
            info->elimination_date = (info->elimination_date_arr[1] + 12 * (info->elimination_date_arr[2] - 2023)) / 3;
            if (info->elimination_date >= 1 && info->elimination_date <= 3) info->elimination_date = 1 + 4 * (info->elimination_date_arr[2] - 2023);
            else if (info->elimination_date >= 4 && info->elimination_date <= 6) info->elimination_date = 2 + 4 * (info->elimination_date_arr[2] - 2023);
            else if (info->elimination_date >= 7 && info->elimination_date <= 9) info->elimination_date = 3 + 4 * (info->elimination_date_arr[2] - 2023);
            else if (info->elimination_date >= 10 && info->elimination_date <= 12) info->elimination_date = 4 + 4 * (info->elimination_date_arr[2] - 2023);        
        }
    } else if (info->timeframe_type == 3) {
        if (info->supplement_value > 0.0) {
            info->supplement_date = info->supplement_date_arr[2] - 2023;
        }
        if (info->elimination_value > 0.0) {
            info->elimination_date = info->elimination_date_arr[2] - 2023;
        }
    }
}

void addSupp(double *balance, deposit_data *info) {
    for (int i = 0; i < info->timeframe; i++) {
        if (info->supplement_date - 1 == i) {
            balance[i] += info->supplement_value;
            if (info->capitalisation) 
                info->total_profit -= info->supplement_value;
        }
    }
}

void addElim(double *balance, deposit_data *info) {
    for (int i = 0; i < info->timeframe; i++) {
        if (info->elimination_date - 1 == i) {
            balance[i] -= info->elimination_value;
            if (info->capitalisation)
                info->total_profit += info->elimination_value;
        }
    }
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
    if (!info->capitalisation) info->timeframe_type = 0;
    parserDate(info);

    double balance[1000] = {0};
    balance[0] = info->sum;

    for (int i = 0; i <= info->timeframe; i++) {
        if (info->supplement_type == 0 && info->supplement_value > 0 ){ // разовое
            addSupp(balance, info);
            break;
        } else if (info->supplement_type == 1) { // month
            parserDate(info);
            addSupp(balance, info);
            
            info->supplement_date_arr[1]++;
            if (info->supplement_date_arr[1] > 12) {
                info->supplement_date_arr[2]++;
            }
        } else if (info->supplement_type == 2) { // quater
            parserDate(info);
            addSupp(balance, info);
            info->supplement_date_arr[1] += 3;
            if (info->supplement_date_arr[1] > 12) {
                info->supplement_date_arr[2]++;
            }
        } else if (info->supplement_type == 3) { // year
            parserDate(info);
            addSupp(balance, info);
            info->supplement_date_arr[2]++;
        }
        if (info->elimination_type == 0 && info->elimination_value > 0 ){ // разовое
            addElim(balance, info);
            break;
        } else if (info->elimination_type == 1) { // month
            parserDate(info);
            addElim(balance, info);
            
            info->elimination_date_arr[1]++;
            if (info->elimination_date_arr[1] > 12) {
                info->elimination_date_arr[2]++;
            }
        } else if (info->elimination_type == 2) { // quater
            parserDate(info);
            addElim(balance, info);
            info->elimination_date_arr[1] += 3;
            if (info->elimination_date_arr[1] > 12) {
                info->elimination_date_arr[2]++;
            }
        } else if (info->elimination_type == 3) { // year
            parserDate(info);
            addElim(balance, info);
            info->elimination_date_arr[2]++;
        }
    }

    if (!info->capitalisation) { // добавить пополнения и снятия и итоговая сумма с их учетом
        for (int i = 1; i <= info->timeframe; i++) {
            info->total_profit += balance[i - 1] * ((info->interest_rate / 100.0) / 365);
            balance[i] += balance[i - 1];
        }
        round_2(&info->total_profit);
        info->total_sum = balance[info->timeframe];
        info->total_rate = info->total_profit / info->sum * 100.0;
        round_2(&info->total_rate);
    } else {
        if (info->timeframe_type == 0) { // days
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] += balance[i - 1] + balance[i-1] * (((info->interest_rate / 100.0) / 365));
            }
        } else if (info->timeframe_type == 1) { // moth
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] += balance[i - 1] + balance[i-1] * (((info->interest_rate / 100.0) / 365) * month_day[(i - 1) % 12]);
            }
        } else if (info->timeframe_type == 2) { // quater
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] += balance[i - 1] + balance[i-1] * (((info->interest_rate / 100.0) / 365) * kvartal_day[(i- 1) % 4]);
            }
        } else { // year
            for (int i = 1; i <= info->timeframe; i++) {
                balance[i] = balance[i - 1] + balance[i-1] * (((info->interest_rate / 100.0) / 365) * 365);
            }
        }
        info->total_sum = balance[info->timeframe];
        info->total_profit += info->total_sum - info->sum;
        info->total_rate = info->total_profit / info->sum * 100.0;
        round_2(&info->total_sum);
        round_2(&info->total_profit);
        round_2(&info->total_rate);
    }
    
    

    Tax(info);
}

// int main() {
//     deposit_data info = {0};
//     info.interest_rate = 12;
//     info.timeframe = 12;
//     info.timeframe_type = 1;
//     info.capitalisation = true;
//     info.sum = 100000;
//     info.tax_rate = 13.0;

//     info.supplement_date_arr[0] = 1;
//     info.supplement_date_arr[1] = 1;
//     info.supplement_date_arr[2] = 2023;
    
//     info.supplement_type = 2;
//     info.supplement_date = 0;
//     info.supplement_value = 1000; 

//     // info.elimination_date_arr[0] = 2;
//     // info.elimination_date_arr[1] = 1;
//     // info.elimination_date_arr[2] = 2023;

//     // info.elimination_type = 1;
//     // info.elimination_date = 0;
//     // info.elimination_value = 1000; 
//     MainDeposit(&info);


//     return 0;

// }