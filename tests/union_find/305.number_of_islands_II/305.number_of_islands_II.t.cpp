#include <gtest/gtest.h>
#include <union_find/305.number_of_islands_II.h>

using namespace leetcode;


TEST(NO_305_number_of_islands_II, I)
{
  std::vector<std::vector<int>> positions {
    {0, 0}, {0, 1}, {1, 2}, {2, 1}
  };

  int m = 3;
  int n = 3;

  std::vector<int> expected {1, 1, 2, 3};
  ASSERT_EQ(Solution().numIslands2(m, n, positions), expected);
}
