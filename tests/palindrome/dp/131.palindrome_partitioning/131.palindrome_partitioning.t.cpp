#include <gtest/gtest.h>

#include <palindrome/dp/131.palindrome_partitioning.h>

using namespace leetcode;

TEST(palindrome_partitioning_131, I)
{
  std::string s = "aab";
  std::vector<std::vector<std::string>> expected {
    {"a", "a", "b"},
    {"aa", "b"}
  };

  ASSERT_EQ(Solution().partition(s), expected);
}
