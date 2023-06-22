#include "s21_calc.h"

/*
main
*/
double Calc(char *equation, double x, bool *status) {
    char _t[NMAX] = {'\0'};
    double result = 0.0;

    strcpy(_t, equation); 

    FormatX(_t, x);
    if (!CheckEquation(_t)) {
        *status = false;
    } else {
        FormatFunc(_t);
        GetReversePN(_t);
        result = GetResult(_t);
    }
    return result;
}
/*
-------------------------------------
*/

/*
stack
*/
char_stack_t * s_push(char_stack_t * head, char a) {
    char_stack_t * ptr;
    if ((ptr = (char_stack_t*)malloc(sizeof(char_stack_t))) == NULL){
        exit(-1);
    }
    ptr->data = a;
    ptr->next = head;
    return ptr;
}

char s_pop(char_stack_t ** head) {
    char_stack_t * ptr;
    char a = '\0';
    if (head == NULL) return '\0';
    ptr = *head;
    a = ptr->data;
    *head = ptr -> next;
    free(ptr);
    return a;
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

double cs_pop(calc_stack_t ** head) {
    calc_stack_t * ptr;
    double num = 0.0;
    if (head == NULL) return 0.0;
    ptr = *head;
    num = ptr->num;
    *head = ptr->next;
    free(ptr);
    return num;
}
/*
-------------------------------------
*/


/*
check and parse
*/
bool isNum(char c) {
    bool status = false;
    if ((c >= 48 && c <= 57) || c == '.' || c == 'e' || c == 'E') status = true;
    return status;
}

bool isOper(char c) {
    bool status = false;
    if (c == '%' || c == '+'|| c =='-'|| c =='*'|| c =='/'|| c =='^' || c == '~') status = true;
    return status;
}

bool CheckEquation(char *equation) {
    bool status = true;

    int bracket = 0;
    int dot = 0;
    size_t pos = 0;
    size_t pos_nums = 0;
    char current_oper = '\0';
    char nums[NMAX] = {'\0'};

    while (equation[pos] != '\0' && status) {
        if (isOper(equation[pos])) {
            current_oper = equation[pos];
        }
        if (isNum(equation[pos])) {
            while (!isOper(equation[pos]) && equation[pos] != '('
                    && equation[pos] != ')' && equation[pos] != '\0' 
                    && equation[pos] != ' ') {
                nums[pos_nums++] = equation[pos++];
            }
            pos_nums = 0;
            while (nums[pos_nums] != '\0') {
                if (nums[pos_nums] == '.') {
                    dot++;
                }
                if (!isNum(nums[pos_nums]) || dot > 1) {
                    status = false;
                }
                pos_nums++;
            }
            if (atof(nums) == 0.0 && current_oper == '/') {
                status = false;
            }
            
            memset(nums, '\0', sizeof(nums));
            pos_nums = 0;
        }
        if (equation[pos] == ')' || equation[pos] == '(') {
            if (equation[pos] == '(') {
                bracket++;
            }
            if (equation[pos] == ')' && bracket <= 0) {
                status = false;
            } else if (equation[pos] == ')' && bracket != 0) {
                bracket--;
            }
        }
        pos++;
    }
    return status;
}

void FormatX(char *equation, double x) {
    size_t pos = 0;
    char x_string[NMAX] = {'\0'};

    while (equation[pos] != '\0') {
        if (equation[pos] == 'x') {
            sprintf(x_string, "%lf", x);
            SetStringMiddle(equation, x_string, pos, pos + 1);
        }
        pos++;
    }
} 

void FormatFunc(char *equation) {
    int bracket = 0;
    size_t border_cpy_right = 0;
    size_t border_cpy_left = 0;
    size_t pos = 0;
    size_t pos_func = 0;
    size_t pos_eq_in = 0;
    char function[NMAX] = {'\0'};
    char equation_in[NMAX] = {'\0'};
    double res_in = 0.0;

    while (equation[pos] != '\0') {
        if (equation[pos] == '-' && (equation[pos - 1] == '(' || pos == 0)) { // ~
            equation[pos] = '~';
        }
        if (isalpha(equation[pos]) && equation[pos] != ' ' && equation[pos] != '.') {
            border_cpy_right = pos;
            if (equation[pos] == 'm') { // mod
                strncpy(function, equation + pos, 3);
                if (strncmp(function, "mod", 3) == 0) {
                    char insert[2] = {'%', '\0'};
                    SetStringMiddle(equation, insert, pos, pos + 3);
                }
                memset(function, '\0', sizeof(function));
                continue;
            }
            while (equation[pos] != '(') { // other func
                function[pos_func++] = equation[pos++];
            }
            pos++;
            while (true) { // ()
                if (equation[pos] == '(') {
                    bracket++;
                }
                if (equation[pos] == ')' && bracket == 0) {
                    break;
                } else if (equation[pos] == ')' && bracket != 0) {
                    bracket--;
                }
                equation_in[pos_eq_in++] = equation[pos++];
                border_cpy_left = pos + 1;
            }
            // reverse format eq_in
            if (strlen(equation_in) > 0) FormatFunc(equation_in);
            // calculation in F()
            GetReversePN(equation_in);
            res_in = GetResult(equation_in);
            // functions
            res_in = FuncCalculation(function, res_in);
            // zamena func na result func
            memset(equation_in, '\0', sizeof(equation_in));
            sprintf(equation_in, "%lf", res_in);
            SetStringMiddle(equation, equation_in, border_cpy_right, border_cpy_left);
            if (res_in < 0) equation[border_cpy_right] = '~';
            pos = border_cpy_left;
            // ->NULL
            border_cpy_right = 0;
            border_cpy_left = 0;
            pos_func = 0;
            pos_eq_in = 0;
            memset(function, '\0', sizeof(function));
            memset(equation_in, '\0', sizeof(equation_in));
            res_in = 0.0;
        }
        pos++;
    }
}
/*
-------------------------------------
*/

/*
calculation
*/
int GetPriority(char ch) {
    int priority = 0;
    switch(ch) {
        case '~' :
            priority = 5;
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
        case '%':
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
        case '^':
            result = pow(first, second);
            break;
        case '%':
            result = fmod(first, second);
            break;
    }
    return result;
}

double FuncCalculation(char *function, double res_in) {
    double result = 0.0;
    if (strncmp(function, "cos", 3) == 0) {
        result = cos(res_in);
    } else if (strncmp(function, "sin", 3) == 0) {
        result = sin(res_in);
    } else if (strncmp(function, "sqrt", 4) == 0) {
        result = sqrt(res_in);
    } else if (strncmp(function, "tan", 3) == 0) {
        result = tan(res_in);
    } else if (strncmp(function, "acos", 4) == 0) {
        result = acos(res_in);
    } else if (strncmp(function, "asin", 4) == 0) {
        result = asin(res_in);
    } else if (strncmp(function, "atan", 4) == 0) {
        result = atan(res_in);
    } else if (strncmp(function, "ln", 2) == 0) {
        result = log(res_in);
    } else if (strncmp(function, "log", 3) == 0) {
        result = log10(res_in);
    }

    return result;
}

void GetReversePN(char * equation) {
    char_stack_t * operation = NULL;
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
            pos--;
            output[output_pos++] = ' ';
        }
        if (isOper(equation[pos])) {
            if (operation == NULL) {
                operation = s_push(operation, equation[pos]);
            } else {
                if (GetPriority(operation->data) < GetPriority(equation[pos])){
                    operation = s_push(operation, equation[pos]);
                } else {
                    while ((operation != NULL) && (GetPriority(operation->data) >= GetPriority(equation[pos]))) {
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
        if (!isdigit(equation[pos])) { // fucntions

        }
        pos++;
        
    }
    while (operation) {
        output[output_pos++] = s_pop(&operation);
        output[output_pos++] = ' ';
    }
    output[output_pos] = '\0';
    memset(equation, '\0', strlen(equation));
    strcpy(equation, output);
    free(output);
}

double GetResult(char *equation) {
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
                first_tmp_num = cs_pop(&buffer);
                first_tmp_num *= -1.0;
                buffer = cs_push(first_tmp_num, buffer);
            } else {
                second_tmp_num = cs_pop(&buffer);
                first_tmp_num = cs_pop(&buffer);
                sprintf(tmp_char, "%lf", ExecutableInstructions(equation[pos], first_tmp_num, second_tmp_num));
                buffer = cs_push(atof(tmp_char), buffer);
                memset(tmp_char, '\0', sizeof(tmp_char));
            }
        }
        pos++;
    }
    return cs_pop(&buffer);
}
/*
-------------------------------------
*/

/*
help
*/
void SetStringMiddle(char *dest, char *src, size_t r_border, size_t l_border) {
    char tmp_string[NMAX] = {'\0'};
    strncpy(tmp_string, dest, r_border); // begin
    strcat(tmp_string, src); // middle
    strcat(tmp_string, dest + l_border); // end

    memset(dest, '\0', strlen(dest));
    strcpy(dest, tmp_string);
}

// void ERR() {
//     printf("INCORRECT INPUT\n");
//     exit(-1);
// }
/*
-------------------------------------
*/
// int main() {
    
//     char primer[255] = "55+33...4";
//     // scanf("%s", primer);
//     double res = 0.0;
//     res = Calc(primer, 0.0);
//     printf("%lf %s", res, primer);
//     return 0;
// }
