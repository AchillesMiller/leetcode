#include <gtest/gtest.h>

#include <array/longest_increasing_sequence/300.longest_increasing_subsequence.h>

using namespace leetcode;

TEST(longest_increasing_subsequence_300, I)
{
  std::vector<int> arr {1, 2, 4, 3, 5};
  ASSERT_EQ(Solution().lengthOfLIS(arr), 4);
}


TEST(longest_increasing_subsequence_300, II)
{
  std::vector<int> arr {5, 4, 3, 2, 1};
  ASSERT_EQ(Solution().lengthOfLIS(arr), 1);
}