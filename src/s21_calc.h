#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#define NMAX 255
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum type_t {
    NUM,
    PLUS,
    FUNC,
    X,
} type_t;

typedef struct StackNum {
    double data;
    int priority;
    type_t type;
    struct StackNum *top;
    size_t cnt;
}StackNum;

StackNum* add_num(double num, StackNum *head);
StackNum *add_oper(char oper, StackNum *head);


#endif  // SRC_S21_CALC_H_

