#include <gtest/gtest.h>

#include <bfs/matrix/371.shortest_distance_from_all_buildings.h>

using namespace leetcode;

TEST(NO_371_shortest_distance_from_all_buildings, I)
{
  std::vector<std::vector<int>> grid {
    {1,0,2,0,1},
    {0,0,0,0,0},
    {0,0,1,0,0}
  };

  ASSERT_EQ(Solution().shortestDistance(grid), 7);
}
