#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "two_sum.hpp"

/************** Nominal Test *************/

TEST(TwoSumTest, TwoSumTest_Nominal_Test) {

/************** Input declaration *******/

  std::vector<std::pair<int,int>> couples;
  std::vector<std::pair<int,int>> expected = {{0,5},{2,3}};
  const std::vector<int> input = {1,3,4,8,10,11};
  int T = 12;

/************** Verification ***********/ 
  couples = two_sum(input,T);

  std::sort(couples.begin(), couples.end());

  EXPECT_EQ(2,couples.size());
  EXPECT_EQ(expected,couples);

}