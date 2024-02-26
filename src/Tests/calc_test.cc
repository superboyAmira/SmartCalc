#include <gtest/gtest.h>

#include "test.h"

bool AreEqual(long double num1, long double num2, int precision) {
  long double epsilon = 1.0 / std::pow(10, precision);
  return std::abs(num1 - num2) < epsilon;
}

TEST(ModelCalc, LightEquation1) {
  s21::CalcModel model;
  std::string eq = "1+5";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(6.0, model.GetResult());
}

TEST(ModelCalc, LightEquation2) {
  s21::CalcModel model;
  std::string eq = "1+55";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(56.0, model.GetResult());
}

TEST(ModelCalc, LightEquation3) {
  s21::CalcModel model;
  std::string eq = "123+54";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(177.0, model.GetResult());
}

TEST(ModelCalc, LightEquation4) {
  s21::CalcModel model;
  std::string eq = "5*6";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(30.0, model.GetResult());
}

TEST(ModelCalc, LightEquation5) {
  s21::CalcModel model;
  std::string eq = "50*6";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(300.0, model.GetResult());
}

TEST(ModelCalc, LightEquation6) {
  s21::CalcModel model;
  std::string eq = "5*6+5";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(35.0, model.GetResult());
}

TEST(ModelCalc, LightEquation7) {
  s21::CalcModel model;
  std::string eq = "5*6*7";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(210.0, model.GetResult());
}

TEST(ModelCalc, LightEquation8) {
  s21::CalcModel model;
  std::string eq = "5+6*10";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(65.0, model.GetResult());
}

TEST(ModelCalc, LightEquation9) {
  s21::CalcModel model;
  std::string eq = "5*6/6";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(5.0, model.GetResult());
}

TEST(ModelCalc, Brackets12) {
  s21::CalcModel model;
  std::string eq = "(6+6)/6";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(2.0, model.GetResult());
}

TEST(ModelCalc, Brackets2) {
  s21::CalcModel model;
  std::string eq = "((6+6)/6)+9";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_EQ(11.0, model.GetResult());
}

TEST(ModelCalc, minus) {
  s21::CalcModel model;
  std::string eq = "10-20";
  model.SetEquation(eq);
  model.UpdateModel();
  ASSERT_DOUBLE_EQ(-10, model.GetResult());
}

TEST(ModelCalc, cos) {
  s21::CalcModel model;
  std::string eq = "cos(10)";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult();
  EXPECT_TRUE(AreEqual(-0.8390715, model.GetResult(), 7));
}

TEST(ModelCalc, grade) {
  s21::CalcModel model;
  std::string eq = "2^3^2";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult();
  EXPECT_TRUE(AreEqual(512, model.GetResult(), 7));
}

TEST(ModelCalc, full) {
  s21::CalcModel model;
  std::string eq =
      "(ln(50)+100)%(2+2.5)+sin(0.5)+tan(10)+sqrt(acos(0.24+0.1222))";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult() << std::endl;
  EXPECT_TRUE(AreEqual(2.6353317363, model.GetResult(), 7));
}

TEST(ModelCalc, full2) {
  s21::CalcModel model;
  std::string eq = "acos(~0.5)+asin(~0.5)+atan(0.1)*cos(30)*sin(20)*tan(45)";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult() << std::endl;
  EXPECT_TRUE(AreEqual(1.593531, model.GetResult(), 7));
}

TEST(ModelCalc, full3) {
  s21::CalcModel model;
  std::string eq = "acos(x)+asin(x)+atan(0.1)";
  long double x = -0.4;
  model.SetEquation(eq);
  model.EnableX();
  model.UpdateModel(x);
  // std::cout << std::setprecision(10) << model.GetResult() << std::endl;
  EXPECT_TRUE(AreEqual(1.67046498, model.GetResult(), 7));
}

TEST(ModelCalc, full3_x) {
  s21::CalcModel model;
  std::string eq = "log(0.3)";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult() << std::endl;
  EXPECT_TRUE(AreEqual(-0.52287874528, model.GetResult(), 7));
}

TEST(ModelCalc, Exception1) {
  s21::CalcModel model;
  std::string eq = "5/0";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult();
  EXPECT_TRUE(AreEqual(0, model.GetResult(), 7));
  EXPECT_FALSE(model.GetStatus());
}

TEST(ModelCalc, Exception2) {
  s21::CalcModel model;
  std::string eq = "5/0))))";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult();
  EXPECT_TRUE(AreEqual(0, model.GetResult(), 7));
  EXPECT_FALSE(model.GetStatus());
}

TEST(ModelCalc, Exception3) {
  s21::CalcModel model;
  std::string eq = "ln(~100)";
  model.SetEquation(eq);
  model.UpdateModel();
  // std::cout << std::setprecision(10) << model.GetResult();
  EXPECT_TRUE(AreEqual(0, model.GetResult(), 7));
  EXPECT_FALSE(model.GetStatus());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
