#include <gtest/gtest.h>
#include <binary_search/410.split_array_largest_sum.h>

using namespace leetcode;

TEST(NO_410_split_array_largest_sum, I)
{
  std::vector<int> nums {7,2,5,10,8};
  int m = 2;

  ASSERT_EQ(Solution().splitArray(nums, m), 18);
}
