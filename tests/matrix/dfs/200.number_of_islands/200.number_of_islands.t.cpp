#include <gtest/gtest.h>

#include <matrix/dfs/200.number_of_islands.h>

using namespace leetcode;

TEST(number_of_islands_200, I)
{
  std::vector<std::vector<char>> grid {
    {'1', '0', '0'},
    {'0', '1', '1'}
  };

  ASSERT_EQ(Solution().numIslands(grid), 2);
}
