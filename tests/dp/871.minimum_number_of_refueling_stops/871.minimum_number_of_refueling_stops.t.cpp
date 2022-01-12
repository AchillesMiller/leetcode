#include <gtest/gtest.h>
#include <dp/871.minimum_number_of_refueling_stops.h>

using namespace leetcode;

TEST(NO_871_minimum_number_of_refueling_stops, I)
{
  int target = 100;
  int startFuel = 10;
  std::vector<std::vector<int>> stations {
    {10,60}, {20,30}, {30,30}, {60,40}
  };

  ASSERT_EQ(Solution().minRefuelStops(target, startFuel, stations), 2);
}

