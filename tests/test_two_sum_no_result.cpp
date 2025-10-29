#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "two_sum.hpp"

/************** No Result Test *************/

TEST(TwoSumTest, TwoSumTest_No_Result_Test) {

/************** Input declaration *******/

  std::vector<std::pair<int,int>> couples;
  std::vector<std::pair<int,int>> expected = {};
  const std::vector<int> input = {2,2,2,2,2,2};
  int T = 12;

/************** Verification ***********/ 
  couples = two_sum(input,T);

  std::sort(couples.begin(), couples.end());

  EXPECT_EQ(0,couples.size());
  EXPECT_EQ(expected,couples);

}