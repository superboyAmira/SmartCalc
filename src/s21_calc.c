#include "s21_calc.h"

stack_t * s_push(stack_t * head, char a) {
    stack_t * ptr;
    if ((ptr = (stack_t*)malloc(sizeof(stack_t))) == NULL){
        exit(-1);
    }
    ptr->data = a;
    ptr->next = head;
    return ptr;
}

char s_pop(stack_t ** head) {
    stack_t * ptr;
    char a = '\0';
    if (*head == NULL) return '\0';
    ptr = * head;
    a = ptr->data;
    *head = ptr -> next;
    free(ptr);
    return a;
}

void s_print(stack_t *top) {		
	stack_t *q = top;
	while (q) {
		printf("%c", q->data);
		q = q->next;
	}
}

void getReversePN(char * equation) {
    stack_t * operation = NULL;
    char *output = (char*)calloc(strlen(equation),sizeof(char));
    size_t pos = 0, output_pos = 0;
    while (equation[pos] != '\0') {
        /*
        Принцип работы алгоритма Дейкстра:
        Проходим исходную строку;
        При нахождении числа, заносим его в выходную строку;
        При нахождении оператора, заносим его в стек;
        Выталкиваем в выходную строку из стека все операторы,
        имеющие приоритет выше рассматриваемого;
        При нахождении открывающейся скобки, заносим её в стек;
        При нахождении закрывающей скобки,
        выталкиваем из стека все операторы до открывающейся скобки,
        а открывающуюся скобку удаляем из стека.
        */
        if (isNum(equation[pos])){
            while ((equation[pos]>='0' && equation[pos]<='9') || equation[pos]=='.') {
                output[output_pos++] = equation[pos++];
            }
            pos--;
            output[output_pos++] = ' ';
        }
        if (isOper(equation[pos])) {
            if (operation == NULL) operation = s_push(operation, equation[pos]);
            else {
                if (getPriority(operation->data) < getPriority(equation[pos])){
                    operation = s_push(operation, equation[pos]);
                } else {
                    while ((operation!= NULL)&& (getPriority(operation->data)>=getPriority(equation[pos]))) {
                        output[output_pos++] = s_pop(&operation);
                        output[output_pos++] = ' ';
                    }
                    operation = s_push(operation, equation[pos]);
                }
            }
        }
        if (equation[pos] == '(') {
            operation = s_push(operation, '(');    
        }
        if (equation[pos]==')'){
            if ((operation->data)!='('){
                while(operation!=NULL && (operation->data)!='('){
                    output[output_pos++] = s_pop(&operation);
                    printf("%c\n",output[output_pos]);
                    output[output_pos++] = ' ';
                }
            }
            if ((operation!=NULL)&&(operation->data=='('))
                s_pop(&operation);
        }
        pos++;
    }
    while (operation) {
        output[output_pos++] = s_pop(&operation);
        output[output_pos++] = ' ';
    }
    output[output_pos] = '\0';
    equation[0]='\0';
    strcpy(equation, output);
    free(output);
}

int getPriority(char ch) {
    int priority = 0;
    switch(ch) {
    case '~' :
        priority = 4;
        break;
    case '^':
        priority = 3;
        break;
    case '*':
        priority = 2;
        break;
    case '/':
        priority = 2;
        break;
    case 'm':
        priority = 2;
        break;
    case '-':
        priority = 1;
        break;
    case '+':
        priority = 1;
        break;
    }
    return priority;
}

bool isOper(char c) {
    bool status = false;
    if (c == '+'|| c =='-'|| c =='*'|| c =='/'|| c =='^' || c == '~' || c == 'm') status = true;
    return status;
}

bool isNum(char c) {
    bool status = false;
    if ((c >='0' && c <= '9') || c == '.') status = true;
    return status;
}

bool isCorrectEquation(char *equation) {
    /*
    mod
    
    cos(x)
    
    sin(x)
    sqrt(x)
    
    tan(x)
    
    acos(x)
    asin(x)
    atan(x)

    ln(x)
    log(x)
    */
   bool status = false;
    size_t pos = 0;
    bool flag_num = false, flag_oper = false, flag_big_oper = false;

    while (equation[pos] != '\0') {
        if (!isNum(equation[pos]) && !isOper(equation[pos])) {
            if (pos != 'm' && pos != 'c' && pos != 's' && pos != 't' && pos != 'a' && pos != 'l') {

            } else {
                switch (equation[pos++]) {
                    case 'm' :
                        if (equation[pos++] == 'o') {
                            if (equation[pos++] == 'd') {
                                status = true;
                            }
                        }
                        break;
                    case 'c' :
                        if (equation[pos++] == 'o') {
                            if (equation[pos++] == 's') {
                                status = true;
                            }
                        }
                        break;
                    case 's' :
                        if (equation[pos] == 'i') {
                            pos++;
                            if (equation[pos++] == 'n') {
                                status = true;
                            }
                        } else if (equation[pos] == 'q') {
                            pos++;
                            if (equation[pos++] == 'r') {
                                if (equation[pos++] == 't') {
                                    status = true;
                                }
                            }
                        }
                        pos++;
                        break;
                }
            }
        }
    }
}

int main() {
    char primer[255] = "255.3 + 2";
    getReversePN(primer);
    printf("%s", primer);
    return 0;
}