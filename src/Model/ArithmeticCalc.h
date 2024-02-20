#ifndef ARITHMETICCALC_H
#define ARITHMETICCALC_H

#include "Observable.h"

#include <string>
#include <stack>
#include <math.h>
#include <cctype>

class ArithMeticCalc : Observable {
public:
    ArithMeticCalc() {
        equation_ = new std::string();
        result_ = 0.0;
    };

    ~ArithMeticCalc() {
        delete equation_;
    };

    double GetResult() const noexcept { return result_; };
    void SetEquation(std::string equation) noexcept { equation_ = &equation; };
    /*
     * Main calculation function
     */
    double MainCalc(double x) {
        ReplaceX(x);
        if (IsCorrect()) {
            PreparatePN();
            CalculationPN();
        }
        return result_;
    };

    /*
     * Check the input expression for the correctness of the input
     */
    bool IsCorrect() noexcept {
        std::string* nums = new std::string();
        int bracket = 0;
        int dot = 0;
        size_t eq_pos = 0;
        size_t nums_pos = 0;

        while (equation_->at(eq_pos) != '\0' && status_) {
            if (isNum(equation_->at(eq_pos))) {
                while (!isOper(equation_->at(eq_pos)) && equation_->at(eq_pos) != '(' &&
                       equation_->at(eq_pos) != ')' && equation_->at(eq_pos) != '\0' &&
                       equation_->at(eq_pos) != ' ' && !isdigit(equation_->at(eq_pos))) {
                    nums->at(nums_pos) = equation_->at(eq_pos);
                }
                nums_pos = 0;
                while (!nums->empty()) {
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
        if (bracket > 0) {
            status_ = false;
        }
        if (isOper(equation_->at(eq_pos))) {
            status_ = false;
        }
        return status_;
    };

    /*
     * Recursively replaces a function in a string automatically with its value
     */
    void ReplaceFunctions() {
        if (!status_) {
            return;
        }
    };

    /*
     * Replace x to value in equation
     */
    void ReplaceX(double x) noexcept {
        if (!status_) {
            return;
        }
        size_t pos = 0;

        while (!equation_->empty()) {
            if (equation_->at(pos) == 'x') {
                equation_->replace(pos, 1, std::to_string(x));
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
        size_t eq_pos = 0;
        size_t polish_pos = 0;

        while (eq_pos < equation_->size()) {
            if (isdigit(equation_->at(eq_pos))) {
                while (equation_->at(eq_pos)) {
                    polish_buf[polish_pos++] = equation_->at(eq_pos++);
                }
                eq_pos--;
                polish_buf[polish_pos++] = ' ';
            }
            if (isOper(equation_->at(eq_pos))) {
                if (opers_.empty() || (PriorityPN(opers_.top()) < PriorityPN(equation_->at(eq_pos)))
                    || (PriorityPN(opers_.top()) == 3 && PriorityPN(equation_->at(eq_pos)) == 3)) {
                    opers_.push(equation_->at(eq_pos));
                    continue;
                }
                while ((!opers_.empty()) && (PriorityPN(opers_.top()) >=
                                               PriorityPN(equation_->at(eq_pos)))) {
                    polish_buf[polish_pos++] = opers_.top();
                    opers_.pop();
                    polish_buf[polish_pos++] = ' ';
                }

            }
            if (equation_->at(eq_pos) == '(') {
                opers_.push('(');
            }
            if (equation_->at(eq_pos) == ')') {
                if (opers_.top() != '(') {
                    while (!opers_.empty() && opers_.top() != '(') {
                        polish_buf[polish_pos++] = opers_.top();
                        opers_.pop();
                        polish_buf[polish_pos++] = ' ';
                    }
                } else if (opers_.top() == '(' && !opers_.empty()) {
                    opers_.pop();
                }
            }
            ++eq_pos;
        }
        while (!opers_.empty()) {
            polish_buf[polish_pos++] = opers_.top();
            opers_.pop();
            polish_buf[polish_pos++] = ' ';
        }
        polish_buf[polish_pos] = '\0';
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

    double CalculationPN() {
        if (!status_) {
            return 0.0;
        }
        double first_tmp_num = 0.0;
        double second_tmp_num = 0.0;
        std::string* num = new std::string();
        size_t eq_pos = 0;
        size_t num_pos = 0;

        while (eq_pos < equation_->size()) {
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
            } else {
                while (isNum(equation_->at(eq_pos))) {
                    num[num_pos++] = equation_->at(eq_pos++);
                }
                nums_.push(atof(num->c_str()));
                num->clear();
                num_pos = 0;
            }
            ++eq_pos;
        }
        return nums_.top();
    };
    /*
     * Calculate the binary operation with 2 nums
     */
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
            if (second != 0.0) {
                result = first / second;
            } else {
                result = 0.0;
                status_ = false;
            }
            break;
        case '^':
            result = pow(first, second);
            break;
        case '%':
            if (second < 0.0) {
                result = 0.0 - fmod(first, second);
            } else {
                result = fmod(first, second);
            }
            break;
        }
        return result;
    };

    /*
     * Calculate the func result wich equation in brackets
     */
    double CalculationFunc(std::string& function, double res_in) {
        double result = 0.0;
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

private:
    std::stack<double> nums_;
    std::stack<char> opers_;

    std::string* equation_;
    double result_;
    bool status_;
};

#endif // ARITHMETICCALC_H
