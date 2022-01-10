#include <gtest/gtest.h>

#include <array/longest_increasing_sequence/2111.minimum_operations_to_make_the_array_k_increasing.h>

using namespace leetcode;

TEST(NO_2111_minimum_operations_to_make_the_array_k_increasing, I)
{
  std::vector<int> arr{5,4,3,2,1};
  int k = 1;

  ASSERT_EQ(Solution().kIncreasing(arr, k), 4);
}

TEST(NO_2111_minimum_operations_to_make_the_array_k_increasing, II)
{
  std::vector<int> arr{4,1,5,2,6,2};
  int k = 2;

  ASSERT_EQ(Solution().kIncreasing(arr, k), 0);
}
