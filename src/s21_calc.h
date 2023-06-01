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
char s_pop(stack_t ** head);
void s_print(stack_t *top);

// string format
void getReversePN(char * text);
int getPriority(char a);
bool isOper(char c);
bool isCorrectNum(char *array_of_nums);




#endif  // SRC_S21_CALC_H_

