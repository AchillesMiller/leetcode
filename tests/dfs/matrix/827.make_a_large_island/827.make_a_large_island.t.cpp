#include <gtest/gtest.h>

#include <dfs/matrix/827.make_a_large_island.h>

using namespace leetcode;

TEST(NO_827_make_a_large_island, I)
{
  std::vector<std::vector<int>> grid {
    {1, 0},
    {0, 1}
  };

  ASSERT_EQ(Solution().largestIsland(grid), 3);
}

TEST(NO_827_make_a_large_island, II)
{
  std::vector<std::vector<int>> grid {
    {1, 1},
    {1, 0}
  };

  ASSERT_EQ(Solution().largestIsland(grid), 4);
}

TEST(NO_827_make_a_large_island, III)
{
  std::vector<std::vector<int>> grid {
    {1, 1},
    {1, 1}
  };

  ASSERT_EQ(Solution().largestIsland(grid), 4);
}
