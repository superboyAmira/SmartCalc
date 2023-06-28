#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#define NMAX 1000
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// stack functions
typedef struct char_stack_t {
    char data;
    struct char_stack_t * next;
} char_stack_t;

char_stack_t * s_push(char_stack_t * head, char a);
char s_pop(char_stack_t ** head);

typedef struct calc_stack_t {
    double num;
    struct calc_stack_t * next;
} calc_stack_t;

calc_stack_t * cs_push(double num, calc_stack_t *head);
double cs_pop(calc_stack_t ** head);

/*
main
*/
double Calc(char *equation, double x, bool *status);
/*
-----
*/

double GetResult(char *equation, bool *status);
void GetReversePN(char * text);
int GetPriority(char a);

bool CheckEquation(char *equation);
bool isOper(char c);
bool isNum(char c);

double FuncCalculation(char *function, double res_in, bool *status);
double ExecutableInstructions(char op, double first, double second, bool *status);

void FormatX(char *equation, double x);
void FormatFunc(char *equation, bool *status);

void SetStringMiddle(char *dest, char *src, size_t r_border, size_t l_border);

/*
Credit and Deposit
*/

#define DIFF 1
#define ANN 2

typedef struct credit_data {
    double credit_sum;
    int timeframe;
    double rate;
    int type;

    double month_pay_ann;
    double month_pay_diff_min;
    double month_pay_diff_max;
    double overpayment;
    double total_payment;
} credit_data;

void MainCredit(credit_data *info);

typedef struct deposit_data {
    /*сумма вклада, срок размещения,
     процентная ставка, налоговая ставка, периодичность выплат, 
    капитализация процентов, список пополнений, список частичных снятий*/
    double sum;
    int timeframe_type;
    int timeframe;
    double interest_rate;
    double tax_rate;
    int frequency;
    bool capitalisation;


    int supplement_date;
    double supplement_value;


    int elimination_date;
    double elimination_value;
    /*Выход: начисленные проценты, сумма налога, сумма на вкладе к концу срока*/
    double total_rate;
    double total_tax;
    double total_sum;
    double total_profit;
} deposit_data;

void MainDeposit(deposit_data *info);
void Tax(deposit_data *info);

void round_2(double *num);

/*
-----
*/

#endif  // SRC_S21_CALC_H_

