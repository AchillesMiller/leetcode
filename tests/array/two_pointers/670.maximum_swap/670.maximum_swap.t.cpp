#include <gtest/gtest.h>

#include <array/two_pointers/670.maximum_swap.h>

using namespace leetcode;

TEST(maximum_swap_670, I)
{
  int num = 7236;
  ASSERT_EQ(Solution().maximumSwap(num), 7632);
}

TEST(maximum_swap_670, II)
{
  int num = 9991239;
  ASSERT_EQ(Solution().maximumSwap(num), 9999231);
}
