#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#define NMAX 255
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// typedef enum type_t {
//     NUM,
//     PLUS,
//     MINUS,
//     MUL,
//     DIV,
//     MOD,
//     SIN,
//     COS,
//     OPEN_BRACKET,
//     CLOSE_BRACKET,
//     FUNC,
//     X,
// } type_t;

// stack functions
typedef struct char_stack_t {
    char data;
    struct char_stack_t * next;
} char_stack_t;
char_stack_t * s_push(char_stack_t * head, char a);
char s_pop(char_stack_t ** head);
// void s_print(char_stack_t *top);

typedef struct calc_stack_t {
    double num;
    struct calc_stack_t * next;
} calc_stack_t;
calc_stack_t * cs_push(double num, calc_stack_t *head);
double cs_pop(calc_stack_t ** head);
double Calculation(char *equation);

// string format
void getReversePN(char * text);
int getPriority(char a);
bool isOper(char c);
bool isNum(char c);
bool isCorrectNum(char *array_of_nums);
// bool isCorrectFunction(char *equation);

double Calculation(char *equation);
double ExecutableInstructions(char op, double first, double second);
void formatFunc(char *equation);




#endif  // SRC_S21_CALC_H_

