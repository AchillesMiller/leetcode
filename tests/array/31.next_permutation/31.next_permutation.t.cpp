#include <gtest/gtest.h>

#include <array/31.next_permutation.h>

using namespace leetcode;

TEST(NO_31_next_permutation, I)
{
  std::vector<int> nums {1, 2, 3};

  std::vector<int> expected {1, 3, 2};
  Solution().nextPermutation(nums);

  ASSERT_EQ(nums, expected);

  Solution().nextPermutation(nums);
  expected = std::vector<int>{2, 1, 3};

  ASSERT_EQ(nums, expected);
}