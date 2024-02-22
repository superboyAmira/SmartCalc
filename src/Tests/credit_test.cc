#include <gtest/gtest.h>

#include "test.h"

TEST(Credit, LightEquation1) {
  s21::CreditModel model;
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetMonths(24);
  model.SetType(s21::credit_t::ANN);
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(4707.35, model.GetMonthPay(), 2));
  EXPECT_TRUE(AreEqual(12976.40, model.GetOverpayment(), 2));
  EXPECT_TRUE(AreEqual(112976.40, model.GetTotal(), 2));
}

TEST(Credit, LightEquation2) {
  s21::CreditModel model;
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetMonths(24);
  model.SetType(s21::credit_t::DIFF);
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(5166.67, model.GetMonthPay(), 2));
  EXPECT_TRUE(AreEqual(4208.33, model.GetMinDiffMonthPay(), 2));
  EXPECT_TRUE(AreEqual(12500.00 , model.GetOverpayment(), 2));
  EXPECT_TRUE(AreEqual(112500.00 , model.GetTotal(), 2));
}
