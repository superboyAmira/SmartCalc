#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#define NMAX 255
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

// string format
void GetReversePN(char * text);
int GetPriority(char a);
bool isOper(char c);
bool isNum(char c);
bool isCorrectNum(char *array_of_nums);
// bool isCorrectFunction(char *equation);

double MainCalculation(char *equation);
double ExecutableInstructions(char op, double first, double second);
void FormatFunc(char *equation);
void SetStringMiddle(char *dest, char *src, size_t r_border, size_t l_border);
double FuncCalculation(char *function, double res_in);
size_t GetEquationInBrackets(char *eq, char *result);

#endif  // SRC_S21_CALC_H_

