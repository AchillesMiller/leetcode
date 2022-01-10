#include <gtest/gtest.h>

#include <array/bucket_sort/791.custom_sort_string.h>

using namespace leetcode;

TEST(NO_791_custom_sort_string, I)
{
  std::string s = "abcd";
  std::string order = "cba";

  ASSERT_EQ(Solution().customSortString(order, s), "dcba");
}