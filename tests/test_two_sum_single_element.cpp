#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "two_sum.hpp"

/************** Single Element Test *************/

TEST(TwoSumTest, TwoSumTest_Single_Element_Test) {

/************** Input declaration *******/

  std::vector<std::pair<int,int>> couples;
  std::vector<std::pair<int,int>> expected = {};
  const std::vector<int> input = {1};
  int T = 12;

/************** Verification ***********/ 

  EXPECT_THROW(two_sum(input,T), std::invalid_argument);

}