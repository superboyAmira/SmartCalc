#include "s21_calc.h"

void init_stack(StackNum *stack) {
    stack->top = NULL;
}

// typedef struct StackNum {
//     char data;
//     int priority;
//     type_t type;
//     StackNum *next;
//     size_cnt;
// }  StackNum;

// StackNum* push_num(struct st_num* head, double a) {
//     StackNum* next_st_elem;
//     if ((next_st_elem = (StackNum*)malloc(sizeof(StackNum)))==NULL) {
//         printf("MEMORY ERROR : push_num()");
//         exit(-1);
//     }
//     next_st_elem->data = a;
//     next_st_elem->top = head;
//     return next_st_elem;
// }

StackNum* push (StackNum* head, char a){
    StackNum* ptr;
    if ((ptr = (StackNum*)malloc(sizeof(StackNum))) == NULL){
        exit(-1);
    }
    ptr->data = a;
    ptr->top = head;
    return ptr;
}

char del(StackNum** head){
    StackNum * ptr;
    char a = '\0';
    if (*head == NULL) {
        return '\0';
    }
    ptr = * head;
    a = ptr->data;
    *head = ptr -> top;
    free(ptr);
    return a;
}
// double del_num(StackNum ** head){
//     StackNum * tmp;
//     double tmp_dbl = 0;
//     tmp = * head;
//     tmp_dbl = tmp->data;
//     *head = tmp->top;
//     free(tmp);
//     return tmp_dbl;
// }