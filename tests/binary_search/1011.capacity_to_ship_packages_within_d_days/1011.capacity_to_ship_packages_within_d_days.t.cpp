#include <gtest/gtest.h>

#include <binary_search/1011.capacity_to_ship_packages_within_d_days.h>

using namespace leetcode;


TEST(NO_1011_capacity_to_ship_packages_within_d_days, I)
{
  std::vector<int> weights {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;

  ASSERT_EQ(Solution().shipWithinDays(weights, days), 15);
}
