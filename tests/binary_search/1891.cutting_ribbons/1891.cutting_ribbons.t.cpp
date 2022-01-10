#include <gtest/gtest.h>
#include <binary_search/1891.cutting_ribbons.h>

using namespace leetcode;

TEST(NO_1891_cutting_ribbons, I)
{
  std::vector<int> ribbons {9, 7, 5};
  int k = 3;

  ASSERT_EQ(Solution().maxLength(ribbons, 3), 5);
  ASSERT_EQ(Solution().maxLength(ribbons, 4), 4);
}
