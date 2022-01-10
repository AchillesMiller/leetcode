#include <gtest/gtest.h>

#include <array/two_pointers/42.trapping_rain_water.h>

using namespace leetcode;

TEST(NO_42_trapping_rain_water, two_pointers)
{
  std::vector<int> height{4,2,0,3,2,5};
  ASSERT_EQ(Solution().trap(height), 9);
}

TEST(NO_42_trapping_rain_water, monotonic_stack)
{
  std::vector<int> height{4,2,0,3,2,5};
  ASSERT_EQ(Solution().trap2(height), 9);
}
