#include <gtest/gtest.h>

#include <matrix/bfs/371.shortest_distance_from_all_buildings.h>

using namespace leetcode;

TEST(shortest_distance_from_all_buildings_371, I)
{
  std::vector<std::vector<int>> grid {
    {1,0,2,0,1},
    {0,0,0,0,0},
    {0,0,1,0,0}
  };

  ASSERT_EQ(Solution().shortestDistance(grid), 7);
}
