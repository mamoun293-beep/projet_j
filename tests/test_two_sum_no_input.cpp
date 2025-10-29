#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "two_sum.hpp"

/************** No input Test *************/

TEST(TwoSumTest, TwoSumTest_No_Input_Test) {

/************** Input declaration *******/

  std::vector<std::pair<int,int>> couples;
  std::vector<std::pair<int,int>> expected = {{0,5},{2,3}};
  const std::vector<int> input = {};
  int T = 12;

/************** Verification ***********/ 

  EXPECT_THROW(two_sum(input,T), std::invalid_argument);
  
}