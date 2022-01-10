#include <gtest/gtest.h>
#include <binary_search/162.find_peak_element.h>

using namespace leetcode;

TEST(NO_162_find_peak_element, I)
{
  std::vector<int> nums {1, 2, 3, 1};

  ASSERT_EQ(Solution().findPeakElement(nums), 2);

}