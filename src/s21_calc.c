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

char s_pop(stack_t * head) {
    stack_t * ptr;
    char a = '\0';
    if (head == NULL) return '\0';
    ptr = head;
    a = ptr->data;
    head = ptr -> next;
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
        if (isdigit(equation[pos])) {
            while (isNum(equation[pos])) {
                output[output_pos++] = equation[pos++];
            }
            pos--; // если не будет пробела
            output[output_pos++] = ' ';

            if (!isCorrectNum(output)) { // проверка на валид
                printf("INCORRECT INPUT\n"); // подумать как выводить ошибки в qt
                exit(-1);
            }
        }
        if (isOper(equation[pos])) {
            if (operation == NULL) operation = s_push(operation, equation[pos]);
            else {
                if (getPriority(operation->data) < getPriority(equation[pos])){
                    operation = s_push(operation, equation[pos]);
                } else {
                    while ((operation!= NULL)&& (getPriority(operation->data)>=getPriority(equation[pos]))) {
                        output[output_pos++] = s_pop(operation);
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
                    output[output_pos++] = s_pop(operation);
                    printf("%c\n",output[output_pos]);
                    output[output_pos++] = ' ';
                }
            }
            if ((operation!=NULL)&&(operation->data=='('))
                s_pop(operation);
        }
        pos++;
        
    }
    printf("%s\n", output);
    while (operation) {
        output[output_pos++] = s_pop(operation);
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

bool isNum(char c) {
    bool status = false;
    if ((c >= 48 && c <= 57) || c == '.' || c == 'e' || c == 'E') status = true;
    return status;
}

bool isOper(char c) {
    bool status = false;
    if (c == '+'|| c =='-'|| c =='*'|| c =='/'|| c =='^' || c == '~' || c == 'm') status = true;
    return status;
}

bool isCorrectNum(char *array_of_nums) { // скорее всего не нужна, так как не вали не проходит
    bool status = true;
    size_t pos = 0, pos_buf = 0;
    char buffer_separtate_num[NMAX] = {'\0'};
    while (array_of_nums[pos] != '\0') {
        while (array_of_nums[pos] != ' ') { // берем отдельное число из общей строки и пороверяем
            buffer_separtate_num[pos_buf++] = array_of_nums[pos++];
        }

        if (atof(buffer_separtate_num) == 0.0 && buffer_separtate_num[0] != '0') {
            status = false;
        }
        pos_buf = 0;
        memset(&buffer_separtate_num, '\0', sizeof(buffer_separtate_num));
        pos++;
    }
    return status;
}

double ExecutableInstructions(char op, double first, double second) {
    double result = 0.0;
    switch (op) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            result = first / second;
            break;
        case 'm' :
            result = fmod(first, second);
            break;
    }
    return result;
}



calc_stack_t * cs_push(double num, calc_stack_t *head) {
    calc_stack_t * ptr;
    if ((ptr = (calc_stack_t*)malloc(sizeof(calc_stack_t))) == NULL){
        exit(-1);
    }
    ptr->num = num;
    ptr->next = head;
    return ptr;
}

double cs_pop(calc_stack_t *head) {
    calc_stack_t * ptr;
    double num = 0.0;
    if (head == NULL) return 0.0;
    ptr = head;
    num = ptr->num;
    head = ptr->next;
    free(ptr);
    return num;
}

double Calculation(char *equation) {
    /*
    Проходим постфиксную запись;
    При нахождении числа, парсим его и заносим в стек;
    При нахождении бинарного оператора, берём два последних значения из стека в обратном порядке;
    При нахождении унарного оператора, в данном случае - унарного минуса, берём последнее значение из стека и вычитаем его из нуля,
    так как унарный минус является правосторонним оператором;
    Последнее значение, после отработки алгоритма, является решением выражения.
    */
    double first_tmp_num = 0.0;
    double second_tmp_num = 0.0;
    char tmp_char[NMAX] = {'\0'};
    calc_stack_t * buffer = NULL;
    size_t pos = 0;
    size_t tmp_pos = 0;

    while (equation[pos] != '\0') {
        if (isNum(equation[pos])) {
            while (isNum(equation[pos])) {
                tmp_char[tmp_pos++] = equation[pos++];
            }
            buffer = cs_push(atof(tmp_char), buffer);
            memset(tmp_char, '\0', sizeof(tmp_char));
            tmp_pos = 0;
        }
        if (isOper(equation[pos])) {
            if (equation[pos] == '~') {
                first_tmp_num = cs_pop(buffer);
                first_tmp_num *= -1.0;
                buffer = cs_push(first_tmp_num, buffer);
            } else {
                second_tmp_num = cs_pop(buffer);
                first_tmp_num = cs_pop(buffer);
                sprintf(tmp_char, "%lf", ExecutableInstructions(equation[pos], first_tmp_num, second_tmp_num));
                buffer = cs_push(atof(tmp_char), buffer);
            }
        }
    }
    return cs_pop(buffer);
}

bool isCorrectFunction(char *equation) {
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
        if (/*!isNum(equation[pos])&& */!isOper(equation[pos])) {
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
    return true;
}

int main() {
    char primer[255] = "255.3 + 0 * (25*4)";
    getReversePN(primer);
    printf("%s", primer);
    return 0;
}