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
typedef struct stack_t {
    char data;
    struct stack_t * next;
} stack_t;
stack_t * s_push(stack_t * head, char a);
char s_pop(stack_t * head);
void s_print(stack_t *top);

typedef struct calc_stack_t {
    double num;
    struct calc_stack_t * next;
} calc_stack_t;
calc_stack_t * cs_push(double num, calc_stack_t *head);
double cs_pop(calc_stack_t *head);
double Calculation(char *equation);

// string format
void getReversePN(char * text);
int getPriority(char a);
bool isOper(char c);
bool isNum(char c);
bool isCorrectNum(char *array_of_nums);
bool isCorrectFunction(char *equation);

double ExecutableInstructions(char op, double first, double second);





#endif  // SRC_S21_CALC_H_

