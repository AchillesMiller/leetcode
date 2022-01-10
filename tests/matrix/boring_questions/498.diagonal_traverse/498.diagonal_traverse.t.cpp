#include <gtest/gtest.h>
#include <matrix/boring_questions/498.diagonal_traverse.h>

using namespace leetcode;

TEST(NO_498_diagonal_traverse, I)
{
  std::vector<std::vector<int>> mat {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  std::vector<int> expected {1, 2, 4, 7, 5, 3, 6, 8, 9};

  ASSERT_EQ(Solution().findDiagonalOrder(mat), expected);
}
