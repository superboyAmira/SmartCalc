#include "s21_calc.h"

void check_parse(int argc, char equation[255], StackNum *stack) {
    size_t pos = 0;
    double num = 0;
    char print = '0';
    while (equation[pos] != '\0') {
        print = equation[pos];
        if (equation[pos] == '+' || equation[pos] == '-' || equation[pos] == '*') {
            stack = add_oper(equation[pos++], stack);
        } else if (equation[pos] == 'x') {
            // add_x();
            pos++;
        } else if (equation[pos] == ' ') {
            pos++;
            continue;
        } else {
            size_t tmp_pos = pos;
            char tmp_equation[NMAX] = {'\0'};
            while (equation[pos] != ' ' && equation[pos] != '\0' && equation[pos] != '\n')
                pos++;
            strncpy(tmp_equation, equation + tmp_pos, pos);
            num = atof(tmp_equation);
            stack = add_num(num, stack);
        }
    }
}

bool is_oper(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? 1 : 0;
}

char *inversePolish(char *equation) {
    
}

struct StackNum* add_num(double num, StackNum *head) {
    StackNum* ptr;
    if ((ptr = (StackNum*)malloc(sizeof(StackNum))) == NULL){
        exit(-1);
    }
    ptr->data = num;
    ptr->priority = 0;
    ptr->type = NUM;
    ptr->top = head;
    ptr->cnt++;
    return ptr;
}

StackNum *add_oper(char oper, StackNum *head) {
    StackNum* ptr;

    if ((ptr = (StackNum *)malloc(sizeof(StackNum))) == NULL) {
        exit(-1);
    }
    ptr->data = 0;
    if (oper == '+') {
        ptr->type = PLUS;
    }
    ptr->priority = 1;
    ptr->top = head;

    return ptr;
}

void init_stack(StackNum *stack) {
    stack->top = NULL;
}

StackNum* push (StackNum* head, char a){
    StackNum* ptr;
    if ((ptr = (StackNum*)malloc(sizeof(StackNum))) == NULL){
        exit(-1);
    }
    ptr->data = a;
    ptr->top = head;
    return ptr;
}

double pop(StackNum** head){
    StackNum * ptr;
    double a = 0;
    if (*head == NULL) {
        return '\0';
    }
    ptr = * head;
    a = ptr->data;
    *head = ptr -> top;
    free(ptr);
    return a;
}

void add_x() {
    
}

int main(/*int argc, char *argv[]*/) {
    StackNum stack;
    stack.cnt = 0;
    init_stack(&stack);
    char primer[255] = "255.3 + 2";
    check_parse(10, primer, &stack);
    return 0;
}