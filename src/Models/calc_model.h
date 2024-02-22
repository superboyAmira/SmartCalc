#ifndef CALC_MODEL_H
#define CALC_MODEL_H

#include <string>
#include <stack>
#include <math.h>
#include <sstream>
#include <iomanip>


class CalcModel {
public:
    using calc_value = double;

    CalcModel() {
        equation_ = new std::string();
        result_ = 0.0;
        status_ = true;
        x_mode_ = false;
    };

    ~CalcModel() {
        delete equation_;
    };

    void EnableX() { x_mode_ = true; };

    void SetEquation(std::string equation) noexcept {
        for (size_t i = 0; i < equation.length(); ++i) {
            equation_->push_back(equation.at(i));
        }
    };

    void SetStatus(bool status) noexcept { status_ = status; };

    bool GetStatus() { return status_; };

    std::string& GetEquation() { return *equation_; };

    calc_value GetResult() const noexcept { return result_; };

    /*
     * Main calculation function
     */
    void UpdateModel(calc_value x = 0.0) {
        if (x_mode_) {
            ReplaceX(x);
        }
        if (IsCorrect()) {
            ReplaceFunctions();
            PreparatePN();
            CalculationPN();
            equation_->clear();
        }
    };

private:
    std::stack<calc_value> nums_;
    std::stack<char> opers_;

    std::string* equation_;
    calc_value result_;
    bool status_;
    bool x_mode_;

    /*
     * Check the input expression for the correctness of the input
     */
    bool IsCorrect() noexcept {
        std::string* nums = new std::string();
        int bracket = 0;
        int dot = 0;
        size_t eq_pos = 0;
        size_t nums_pos = 0;

        while (eq_pos < equation_->length() && status_) {
            if (isNum(equation_->at(eq_pos))) {
                while (!isOper(equation_->at(eq_pos)) && equation_->at(eq_pos) != '(' &&
                       equation_->at(eq_pos) != ')' && equation_->at(eq_pos) != '\0' &&
                       equation_->at(eq_pos) != ' ' /*&& !isdigit(equation_->at(eq_pos))*/) {
                    nums->push_back(equation_->at(eq_pos++));
                    if (eq_pos >= equation_->length()) {
                        break;
                    }
                }
                nums_pos = 0;
                while (nums_pos < nums->length()) {
                    if (nums->at(nums_pos) == '.') {
                        dot++;
                    }
                    if (!isNum(nums->at(nums_pos)) || dot > 1) {
                        status_ = false;
                    }
                    nums_pos++;
                }
                dot = 0;

                nums->clear();
                nums_pos = 0;
            }
            if (eq_pos < equation_->length()) {
                if (equation_->at(eq_pos) == ')' || equation_->at(eq_pos) == '(') {
                    if (equation_->at(eq_pos) == '(') {
                        bracket++;
                    }
                    if (equation_->at(eq_pos) == ')' && bracket <= 0) {
                        status_ = false;
                    } else if (equation_->at(eq_pos) == ')' && bracket != 0) {
                        bracket--;
                    }
                }
                eq_pos++;
            }
        }
        if (bracket > 0) {
            status_ = false;
        }
        if (eq_pos < equation_->length()) {
            if (isOper(equation_->at(eq_pos))) {
                status_ = false;
            }
        }
        delete nums;
        return status_;
    };

    /*
     * Recursively replaces a function in a string automatically with its value
     */
    void ReplaceFunctions() {
        if (!status_) {
            return;
        }
        size_t eq_pos = 0;
        while (eq_pos < equation_->length()) {
            if (!std::isalpha(equation_->at(eq_pos))) {
                ++eq_pos;
                continue;
            }
            std::string* f_name = new std::string();
            std::string* f_equation_in = new std::string();
            size_t f_begin = 0, f_end = 0;
            int f_bracket = 1;

            f_begin = eq_pos;
            while (equation_->at(eq_pos) != '(') {
                f_name->push_back(equation_->at(eq_pos++));
            }
            ++eq_pos; // skip (
            while (f_bracket != 0) {
                if (equation_->at(eq_pos) == '(') {
                    ++f_bracket;
                }
                if (equation_->at(eq_pos) == ')') {
                    --f_bracket;
                }
                if (f_bracket != 0) {
                    f_equation_in->push_back(equation_->at(eq_pos++));
                }
            }
            if (f_equation_in->empty()) {
                status_ = false;
                delete f_name;
                delete f_equation_in;
                break;
            }
            f_end = eq_pos + 1;

            CalcModel* f_model = new CalcModel();
            f_model->SetEquation(*f_equation_in);
            f_model->UpdateModel();
            calc_value f_res = CalculationFunc(*f_name, f_model->GetResult());
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(10) << f_res;
            std::string _tmp = oss.str();
            if (f_res < 0) {
                _tmp.front() = '~';
            }
            *equation_ = equation_->substr(0, f_begin) + _tmp + equation_->substr(f_end, equation_->length());
            delete f_model;
            delete f_name;
            delete f_equation_in;
            --eq_pos;
        }
    };

    /*
     * Replace x to value in equation
     */
    void ReplaceX(calc_value x) noexcept {
        if (!status_) {
            return;
        }
        size_t pos = 0;
        std::string _tmp = std::to_string(x);
        if (_tmp.front() == '-') {
            _tmp.front() = '~';
        }

        while (pos < equation_->length()) {
            if (equation_->at(pos) == 'x') {
                *equation_ = equation_->substr(0, pos) + /*_tmp.toStdString()*/_tmp + equation_->substr(pos + 1, equation_->length());
            }
            pos++;
        }
    };

    /*
     * Preparate a equation to reverse polish notation
     */
    void PreparatePN() {
        if (!status_) {
            return;
        }
        std::string* polish_buf = new std::string();
        polish_buf->resize(equation_->size() * 3);
        size_t eq_pos = 0;
        size_t polish_pos = 0;

        while (eq_pos < equation_->length()) {
            if (isOper(equation_->at(eq_pos))) {
                if (opers_.empty() || (PriorityPN(opers_.top()) < PriorityPN(equation_->at(eq_pos)))
                    || (PriorityPN(opers_.top()) == 3 && PriorityPN(equation_->at(eq_pos)) == 3)) {
                    opers_.push(equation_->at(eq_pos));
                } else {
                    while ((!opers_.empty()) && (PriorityPN(opers_.top()) >=
                                                 PriorityPN(equation_->at(eq_pos)))) {
                        polish_buf->at(polish_pos++) = opers_.top();
                        opers_.pop();
                        polish_buf->at(polish_pos++) = ' ';
                    }
                    opers_.push(equation_->at(eq_pos));
                }
            }
            if (isNum(equation_->at(eq_pos))) {
                while (isNum(equation_->at(eq_pos))) {
                    polish_buf->at(polish_pos++) = equation_->at(eq_pos++);
                    if (eq_pos >= equation_->length()) {
                        break;
                    }
                }
                eq_pos--;
                polish_buf->at(polish_pos++) = ' ';
            }
            if (equation_->at(eq_pos) == '(') {
                opers_.push('(');
            }
            if (equation_->at(eq_pos) == ')') {
                if (opers_.top() != '(') {
                    while (!opers_.empty() && opers_.top() != '(') {
                        polish_buf->at(polish_pos++) = opers_.top();
                        opers_.pop();
                        polish_buf->at(polish_pos++) = ' ';
                    }
                }
                if (opers_.top() == '(' && !opers_.empty()) {
                    opers_.pop();
                }
            }
            ++eq_pos;
        }
        while (!opers_.empty()) {
            polish_buf->at(polish_pos++) = opers_.top();
            opers_.pop();
            polish_buf->at(polish_pos++) = ' ';
        }
        polish_buf->at(polish_pos) = '\0';
        equation_->clear();
        equation_ = std::move(polish_buf);
    };

    /*
     * Get priority to operatoion for PreparatePN
     */
    double PriorityPN(char operation) const noexcept {
        int priority = 0;
        switch (operation) {
        case '~':
            priority = 5;
            break;
        case '^':
            priority = 3;
            break;
        case '*':
        case '/':
        case '%':
        case 'm':
            priority = 2;
            break;
        case '-':
        case '+':
            priority = 1;
            break;
        }
        return priority;
    };

    void CalculationPN() {
        if (!status_) {
            return;
        }
        calc_value first_tmp_num = 0.0;
        calc_value second_tmp_num = 0.0;
        std::string* num = new std::string();
        size_t eq_pos = 0;

        while (eq_pos < equation_->length()) {
            if (isOper(equation_->at(eq_pos))) {
                if (equation_->at(eq_pos) == '~') {
                    nums_.top() *= -1.0;
                } else {
                    second_tmp_num = nums_.top();
                    nums_.pop();
                    first_tmp_num = nums_.top();
                    nums_.pop();
                    nums_.push(ExecutableInstructions(equation_->at(eq_pos), first_tmp_num, second_tmp_num));
                    if (!status_) {
                        break;
                    }
                    num->clear();
                }
            } else if (isNum(equation_->at(eq_pos))) {
                while (isNum(equation_->at(eq_pos))) {
                    num->push_back(equation_->at(eq_pos++));
                }
                nums_.push(std::stold(*num));
                num->clear();
            }
            ++eq_pos;
        }
        delete num;
        result_ = nums_.top();
        nums_.pop();
    };
    /*
     * Calculate the binary operation with 2 nums
     */
    calc_value ExecutableInstructions(char op, calc_value first, calc_value second) {
        calc_value result = 0.0;
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
            if (second != 0.0) {
                result = first / second;
            } else {
                result = 0.0;
                status_ = false;
            }
            break;
        case '^':
            result = powl(first, second);
            break;
        case '%':
            if (second < 0.0) {
                result = 0.0 - fmodl(first, second);
            } else {
                result = fmodl(first, second);
            }
            break;
        }
        return result;
    };

    /*
     * Calculate the func result wich equation in brackets
     */
    calc_value CalculationFunc(std::string& function, calc_value res_in) {
        calc_value result = 0.0;
        if (function.compare(0, 3, "cos") == 0) {
            result = cos(res_in);
        } else if (function.compare(0, 3, "sin") == 0) {
            result = sin(res_in);
        } else if (function.compare(0, 4, "sqrt") == 0) {
            if (res_in < 0.0) {
                status_ = false;
                result = 0.0;
            } else {
                result = sqrt(res_in);
            }
        } else if (function.compare(0, 3, "tan") == 0) {
            if (cos(res_in) == 0.0) {
                status_ = false;
                result = 0.0;
            } else {
                result = tan(res_in);
            }

        } else if (function.compare(0, 4, "acos") == 0) {
            if (res_in > 1.0 || res_in < -1.0) {
                status_ = false;
                result = 0.0;
            } else {
                result = acos(res_in);
            }
        } else if (function.compare(0, 4, "asin") == 0) {
            if (res_in > 1.0 || res_in < -1.0) {
                status_ = false;
                result = 0.0;
            } else {
                result = asin(res_in);
            }
        } else if (function.compare(0, 4, "atan") == 0) {
            result = atan(res_in);
        } else if (function.compare(0, 2, "ln") == 0) {
            if (res_in < 0.0) {
                status_ = false;
                result = 0.0;

            } else if (res_in == 0.0) {
                result = -100000;
            } else {
                result = log(res_in);
            }
        } else if (function.compare(0, 3, "log") == 0) {
            if (res_in < 0.0) {
                status_ = false;
                result = 0.0;
            } else if (res_in == 0.0) {
                result = -100000;
            } else {
                result = log10(res_in);
            }
        } else {
            status_ = false;
        }
        return result;
    };

    bool isNum(char c) const noexcept {
        bool status = false;
        if ((c >= 48 && c <= 57) || c == '.' || c == 'e' || c == 'E')
            status = true;
        return status;
    };

    bool isOper(char c) const noexcept {
        bool status = false;
        if (c == '%' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
            c == '~')
            status = true;
        return status;
    };
};

#endif // CALC_MODEL_H
