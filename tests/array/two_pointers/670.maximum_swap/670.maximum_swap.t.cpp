#include <gtest/gtest.h>

#include <array/two_pointers/670.maximum_swap.h>

using namespace leetcode;

TEST(NO_670_maximum_swap, I)
{
  int num = 7236;
  ASSERT_EQ(Solution().maximumSwap(num), 7632);
}

TEST(NO_670_maximum_swap, II)
{
  int num = 9991239;
  ASSERT_EQ(Solution().maximumSwap(num), 9999231);
}
