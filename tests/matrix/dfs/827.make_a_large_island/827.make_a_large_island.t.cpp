#include <gtest/gtest.h>

#include <matrix/dfs/827.make_a_large_island.h>

using namespace leetcode;

TEST(make_a_large_island_827, I)
{
  std::vector<std::vector<int>> grid {
    {1, 0},
    {0, 1}
  };

  ASSERT_EQ(Solution().largestIsland(grid), 3);
}

TEST(make_a_large_island_827, II)
{
  std::vector<std::vector<int>> grid {
    {1, 1},
    {1, 0}
  };

  ASSERT_EQ(Solution().largestIsland(grid), 4);
}

TEST(make_a_large_island_827, III)
{
  std::vector<std::vector<int>> grid {
    {1, 1},
    {1, 1}
  };

  ASSERT_EQ(Solution().largestIsland(grid), 4);
}
