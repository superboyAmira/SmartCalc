#include "s21_calc.h"

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
} deposit_data;

void MainDeposit() {
    
}

int main() {
    deposit_data info = {0};
    info.tax_rate = 13;


    return 0;

}