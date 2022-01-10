#include <gtest/gtest.h>

#include <array/longest_increasing_sequence/300.longest_increasing_subsequence.h>

using namespace leetcode;

TEST(NO_300_longest_increasing_subsequence, I)
{
  std::vector<int> arr {1, 2, 4, 3, 5};
  ASSERT_EQ(Solution().lengthOfLIS(arr), 4);
}


TEST(NO_300_longest_increasing_subsequence, II)
{
  std::vector<int> arr {5, 4, 3, 2, 1};
  ASSERT_EQ(Solution().lengthOfLIS(arr), 1);
}