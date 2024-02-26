#include <gtest/gtest.h>

#include "test.h"

using namespace s21;

TEST(Deposit, Deposit1) {
  DepositModel model;
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TMONTH);
  model.SetTimeframe(12);
  model.SetTaxRate(12);
  model.SetCapitalisation();
  model.UpdateModel();
  //   std::cout << std::setprecision(10) << model.GetTotalProfit() <<
  //   std::endl; std::cout << std::setprecision(10) << model.GetTotalRate() <<
  //   std::endl; std::cout << std::setprecision(10) << model.GetTotalTax() <<
  //   std::endl;
  EXPECT_TRUE(AreEqual(12682.36, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(12.68, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0.00, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit2) {
  DepositModel model;
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TQUATER);
  model.SetTimeframe(12);
  model.SetTaxRate(12);
  model.SetCapitalisation();
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(42575.7, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(42.58, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0.00, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit3) {
  DepositModel model;
  model.SetAmount(1000000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TDAY);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetSupplementionData(s21::elim_supp_t::MONTH, 10000,
                             std::vector<int>{1, 2, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(7920.32, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(0.79, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0.00, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit4) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(1000000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TMONTH);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetSupplementionData(s21::elim_supp_t::MONTH, 10000,
                             std::vector<int>{1, 2, 2024});
  model.SetSupplementionData(s21::elim_supp_t::YEAR, 1210000,
                             std::vector<int>{1, 2, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(668682.2928, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(72.03, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(51624.5472, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit5) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TMONTH);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetEliminationData(s21::elim_supp_t::MONTH, 1000,
                           std::vector<int>{1, 2, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(23992.7, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(23.99, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit6) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TMONTH);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(789.04, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(0.79, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit7) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TMONTH);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetEliminationData(s21::elim_supp_t::ONETIME, 1000,
                           std::vector<int>{1, 2, 2024});
  model.SetSupplementionData(s21::elim_supp_t::ONETIME, 10000,
                             std::vector<int>{1, 4, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(29302.05, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(29.3, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit8) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TDAY);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetEliminationData(s21::elim_supp_t::QUATER, 1000,
                           std::vector<int>{1, 2, 2024});
  model.SetSupplementionData(s21::elim_supp_t::QUATER, 10000,
                             std::vector<int>{1, 4, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(792.03, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(0.79, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit9) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TYEAR);
  model.SetTimeframe(24);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetEliminationData(s21::elim_supp_t::YEAR, 1000,
                           std::vector<int>{1, 2, 2024});
  model.SetSupplementionData(s21::elim_supp_t::YEAR, 10000,
                             std::vector<int>{1, 4, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(1237392.906, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(1338.47, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(101077.644, model.GetTotalTax(), 2));
}

TEST(Deposit, Deposit10) {
  DepositModel model;
  model.ClearModel();
  model.SetAmount(100000);
  model.SetRate(12);
  model.SetTimeframeType(s21::timeframe_t::TQUATER);
  model.SetTimeframe(12);
  model.SetTaxRate(8);
  model.SetCapitalisation();
  model.SetEliminationData(s21::elim_supp_t::YEAR, 1000,
                           std::vector<int>{1, 2, 2024});
  model.SetSupplementionData(s21::elim_supp_t::YEAR, 50,
                             std::vector<int>{1, 4, 2024});
  model.UpdateModel();
  EXPECT_TRUE(AreEqual(41793.08, model.GetTotalProfit(), 2));
  EXPECT_TRUE(AreEqual(41.79, model.GetTotalRate(), 2));
  EXPECT_TRUE(AreEqual(0, model.GetTotalTax(), 2));
}