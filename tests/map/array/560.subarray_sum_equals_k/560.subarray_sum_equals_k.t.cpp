#include <gtest/gtest.h>
#include <map/array/560.subarray_sum_equals_k.h>

using namespace leetcode;

TEST(subarray_sum_equals_k_560, I)
{
  std::vector<int> nums {1, 1, 1};


  ASSERT_EQ(Solution().subarraySum(nums, 1), 3);
  ASSERT_EQ(Solution().subarraySum(nums, 2), 2);
  ASSERT_EQ(Solution().subarraySum(nums, 3), 1);
  ASSERT_EQ(Solution().subarraySum(nums, 4), 0);
}
