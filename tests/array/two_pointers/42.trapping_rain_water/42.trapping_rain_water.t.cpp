#include <gtest/gtest.h>

#include <array/two_pointers/42.trapping_rain_water.h>

using namespace leetcode;

TEST(trapping_rain_water_42, two_pointers)
{
  std::vector<int> height{4,2,0,3,2,5};
  ASSERT_EQ(Solution().trap(height), 9);
}

TEST(trapping_rain_water_42, monotonic_stack)
{
  std::vector<int> height{4,2,0,3,2,5};
  ASSERT_EQ(Solution().trap2(height), 9);
}
