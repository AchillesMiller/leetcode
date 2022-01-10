#include <gtest/gtest.h>

#include <dfs/matrix/200.number_of_islands.h>

using namespace leetcode;

TEST(NO_200_number_of_islands, I)
{
  std::vector<std::vector<char>> grid {
    {'1', '0', '0'},
    {'0', '1', '1'}
  };

  ASSERT_EQ(Solution().numIslands(grid), 2);
}
