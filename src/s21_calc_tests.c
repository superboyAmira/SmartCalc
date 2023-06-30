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

  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);
  srunner_free(sr);

  return 0;
}