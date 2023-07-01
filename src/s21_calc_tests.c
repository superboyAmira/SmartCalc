#include <check.h>

#include "s21_calc.h"

START_TEST(test_plus) {
  char str[256] = "1.25+3.45";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(4.700000, res, 1e-7);
}
END_TEST

START_TEST(test_minus) {
  char str[256] = "1.25-3.45";
   bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(-2.200000, res, 1e-7);
}
END_TEST

START_TEST(test_mult) {
  char str[256] = "1.25*3.45";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(4.312500, res, 1e-7);
}
END_TEST

START_TEST(test_mult2) {
  char str[256] = "3*(4+7)";
  bool status = true;

  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(33.00, res, 1e-7);
}
END_TEST

START_TEST(test_div) {
  char str[256] = "1.25/3.45";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(0.362319, res, 1e-7);
}
END_TEST

START_TEST(test_mod) {
  char str[256] = "1.25mod3.45";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(1.25, res, 1e-7);
}
END_TEST

START_TEST(test_pow) {
  char str[256] = "1.25^3.45";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(2.159432, res, 1e-7);
}
END_TEST

START_TEST(test_brackets) {
  char str[256] = "(5.23+1.25)*(0.25+0.001)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(1.626480, res, 1e-7);
}
END_TEST

START_TEST(test_sin) {
  char str[256] = "sin((5.23+1.25)*(0.25+0.001))";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(0.998450, res, 1e-7);
}
END_TEST

START_TEST(test_cos) {
  char str[256] = "cos((5.23+1.25)*(0.25+0.001))";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(-0.055655, res, 1e-7);
}
END_TEST

START_TEST(test_tan) {
  char str[256] = "tan((5.23+1.25)*(0.25+0.001))";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(-17.940020, res, 1e-7);
}
END_TEST

START_TEST(test_asin) {
  char str[256] = "asin(7/7.7)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(1.141097, res, 1e-7);

}
END_TEST

START_TEST(test_acos) {
  char str[256] = "acos(1/1)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(0.0, res, 1e-7);
}
END_TEST

START_TEST(test_atan) {
  char str[256] = "atan(7/7.7)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(0.737815, res, 1e-7);
}
END_TEST

START_TEST(test_sqrt) {
  char str[256] = "sqrt(1357-245)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(33.346664, res, 1e-7);
}
END_TEST

START_TEST(test_ln) {
  char str[256] = "ln(1357-245)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(7.013915, res, 1e-7);
}
END_TEST

START_TEST(test_log) {
  char str[256] = "log(1357-245)";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(3.046105, res, 1e-7);
}
END_TEST

START_TEST(test_combo) {
  char str[256] = "((sqrt(32+1)*7)/11)*432";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(1579.2325920, res, 1e-7);
}
END_TEST

START_TEST(test_combo_func) {
  char str[256] = "cos(sin(tan(-0.005)))";
  bool status = true;
  double res = Calc(str,0.0,&status);
  ck_assert_double_eq_tol(0.999988, res, 1e-7);
}
END_TEST

START_TEST(test_brackets_err) {
  char str[256] = "cos(sin(tan(-0.005))";
  bool status = true;
  Calc(str,0.0,&status);
  ck_assert_int_eq(false, status);
}
END_TEST

START_TEST(test_del_0) {
  char str[256] = "10.124/0.0";
  bool status = true;
  Calc(str,0.0,&status);
  ck_assert_int_eq(false, status);
}
END_TEST

START_TEST(test_credit_diff) {
  credit_data info2 = {0};
  info2.credit_sum = 130000;
  info2.rate = 15;
  info2.timeframe = 12;
  info2.type = DIFF;
  MainCredit(&info2);
  ck_assert_double_eq_tol(10968.75, info2.month_pay_diff_min, 1e-1);
  ck_assert_double_eq_tol(12458.33, info2.month_pay_diff_max, 1e-1);

  ck_assert_double_eq_tol(10562.50, info2.overpayment, 1e-1);
  ck_assert_double_eq_tol(140562.50, info2.total_payment, 1e-1);
}
END_TEST

START_TEST(test_credit_ann) {
  credit_data info2 = {0};
  info2.credit_sum = 130000;
  info2.rate = 15;
  info2.timeframe = 12;
  info2.type = ANN;
  MainCredit(&info2);
  ck_assert_double_eq_tol(11733.58, info2.month_pay_ann, 1e-1);

  ck_assert_double_eq_tol(10802.96, info2.overpayment, 1e-1);
  ck_assert_double_eq_tol(140802.96, info2.total_payment, 1e-1);
}
END_TEST

START_TEST(test_deposit_1) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 12;
  info.timeframe_type = 1;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;
  MainDeposit(&info);
  ck_assert_double_eq_tol(12682.36, info.total_profit, 1e-2);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(112682.36, info.total_sum, 1e-2);
}
END_TEST

START_TEST(test_deposit_2) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 12;
  info.timeframe_type = 1;
  info.capitalisation = true;
  info.sum = 1000000;
  info.tax_rate = 13.0;
  MainDeposit(&info);
  ck_assert_double_eq_tol(120086.55, info.total_profit, 1e-2);

  ck_assert_double_eq_tol(6737.07, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(1120086.55, info.total_sum, 1e-2);
}
END_TEST

START_TEST(test_deposit_3) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = false;
  info.sum = 100000;
  info.tax_rate = 13.0;
  MainDeposit(&info);
  ck_assert_double_eq_tol(12000.00, info.total_profit, 1e-2);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(100000.00, info.total_sum, 1e-2);
}
END_TEST

START_TEST(test_deposit_4) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 4;
  info.timeframe_type = 2;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;
  MainDeposit(&info);
  ck_assert_double_eq_tol(12550.8, info.total_profit, 1e-1);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-1);
  ck_assert_double_eq_tol(112550.8, info.total_sum, 1e-1);
}
END_TEST

START_TEST(test_deposit_5) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.supplement_date_arr[0] = 15;
  info.supplement_date_arr[1] = 3;
  info.supplement_date_arr[2] = 2023;
  
  info.supplement_type = 0;
  info.supplement_date = 0;
  info.supplement_value = 1000; 

  MainDeposit(&info);
  ck_assert_double_eq_tol(12848.08, info.total_profit, 1e-0);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(113848.08, info.total_sum, 1e-0);
}
END_TEST


START_TEST(test_deposit_6) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.elimination_date_arr[0] = 2;
  info.elimination_date_arr[1] = 7;
  info.elimination_date_arr[2] = 2023;

  info.elimination_type = 1;
  info.elimination_date = 0;
  info.elimination_value = 1000;  

  MainDeposit(&info);
  ck_assert_double_eq_tol(12533.46, info.total_profit, 1e-2);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(106533.46, info.total_sum, 1e-2);
}
END_TEST

START_TEST(test_deposit_7) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.supplement_date_arr[0] = 2;
  info.supplement_date_arr[1] = 7;
  info.supplement_date_arr[2] = 2023;

  info.supplement_type = 1;
  info.elimination_date = 0;
  info.supplement_value = 1000;  

  MainDeposit(&info);
  ck_assert_double_eq_tol(12961.5 , info.total_profit, 1e-1);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(118961.5, info.total_sum, 1e-1);
}
END_TEST

START_TEST(test_deposit_8) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.supplement_date_arr[0] = 2;
  info.supplement_date_arr[1] = 7;
  info.supplement_date_arr[2] = 2023;

  info.supplement_type = 2;
  info.elimination_date = 0;
  info.supplement_value = 1000;  

  MainDeposit(&info);
  ck_assert_double_eq_tol(12839.8  , info.total_profit, 1e-1);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(114839.8 , info.total_sum, 1e-1);
}
END_TEST

START_TEST(test_deposit_9) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.supplement_date_arr[0] = 2;
  info.supplement_date_arr[1] = 7;
  info.supplement_date_arr[2] = 2023;

  info.supplement_type = 3;
  info.elimination_date = 0;
  info.supplement_value = 1000;  

  MainDeposit(&info);
  ck_assert_double_eq_tol(12809.5  , info.total_profit, 1e-1);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(113809, info.total_sum, 1e-0);
}
END_TEST

START_TEST(test_deposit_10) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.elimination_date_arr[0] = 2;
  info.elimination_date_arr[1] = 7;
  info.elimination_date_arr[2] = 2023;

  info.elimination_type = 2;
  info.elimination_date = 0;
  info.elimination_value = 1000; 

  MainDeposit(&info);
  ck_assert_double_eq_tol(12655.1, info.total_profit, 1e-1);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(110655.1, info.total_sum, 1e-1);
}
END_TEST

START_TEST(test_deposit_11) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 365;
  info.timeframe_type = 0;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.supplement_date_arr[0] = 1;
  info.supplement_date_arr[1] = 3;
  info.supplement_date_arr[2] = 2023;

  info.supplement_type = 1;
  info.elimination_date = 0;
  info.supplement_value = 11000;  

  info.elimination_date_arr[0] = 2;
  info.elimination_date_arr[1] = 7;
  info.elimination_date_arr[2] = 2023;

  info.elimination_type = 2;
  info.elimination_date = 0;
  info.elimination_value = 1000; 

  MainDeposit(&info);
  ck_assert_double_eq_tol(18960.49, info.total_profit, 1e-2);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(237960.49, info.total_sum, 1e-1);
}
END_TEST

START_TEST(test_deposit_12) {
  deposit_data info = {0};
  info.interest_rate = 12;
  info.timeframe = 4;
  info.timeframe_type = 2;
  info.capitalisation = true;
  info.sum = 100000;
  info.tax_rate = 13.0;

  info.supplement_date_arr[0] = 1;
  info.supplement_date_arr[1] = 3;
  info.supplement_date_arr[2] = 2023;

  info.supplement_type = 0;
  info.elimination_date = 0;
  info.supplement_value = 11000;  

  info.elimination_date_arr[0] = 2;
  info.elimination_date_arr[1] = 7;
  info.elimination_date_arr[2] = 2023;

  info.elimination_type = 0;
  info.elimination_date = 0;
  info.elimination_value = 1000;

  MainDeposit(&info);
  ck_assert_double_eq_tol(13931.4, info.total_profit, 1e-1);

  ck_assert_double_eq_tol(0.0, info.total_tax, 1e-2);
  ck_assert_double_eq_tol(124931.4, info.total_sum, 1e-1);
}
END_TEST


int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_plus);
  tcase_add_test(tc1_1, test_minus);
  tcase_add_test(tc1_1, test_mult);
  tcase_add_test(tc1_1, test_mult2);
  tcase_add_test(tc1_1, test_div);
  tcase_add_test(tc1_1, test_mod);
  tcase_add_test(tc1_1, test_pow);
  tcase_add_test(tc1_1, test_brackets);
  tcase_add_test(tc1_1, test_sin);
  tcase_add_test(tc1_1, test_cos);
  tcase_add_test(tc1_1, test_tan);
  tcase_add_test(tc1_1, test_asin);
  tcase_add_test(tc1_1, test_acos);
  tcase_add_test(tc1_1, test_atan);
  tcase_add_test(tc1_1, test_sqrt);
  tcase_add_test(tc1_1, test_ln);
  tcase_add_test(tc1_1, test_log);
  tcase_add_test(tc1_1, test_combo);
  tcase_add_test(tc1_1, test_combo_func);
  tcase_add_test(tc1_1, test_brackets_err);
  tcase_add_test(tc1_1, test_del_0);
  tcase_add_test(tc1_1, test_credit_diff);
  tcase_add_test(tc1_1, test_credit_ann);
  tcase_add_test(tc1_1, test_deposit_1);
  tcase_add_test(tc1_1, test_deposit_2);
  tcase_add_test(tc1_1, test_deposit_3);
  tcase_add_test(tc1_1, test_deposit_4);
  tcase_add_test(tc1_1, test_deposit_5);
  tcase_add_test(tc1_1, test_deposit_6);
  tcase_add_test(tc1_1, test_deposit_7);
  tcase_add_test(tc1_1, test_deposit_8);
  tcase_add_test(tc1_1, test_deposit_9);
  tcase_add_test(tc1_1, test_deposit_10);
  tcase_add_test(tc1_1, test_deposit_11);
   tcase_add_test(tc1_1, test_deposit_12);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);
  srunner_free(sr);

  return 0;
}
