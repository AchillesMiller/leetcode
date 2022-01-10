#include "gtest/gtest.h"

#include <intervals/56.merge_intervals.h>

TEST(NO_56_merge_intervals, I)
{
  leetcode::interval_merger merger;

  // input:  [[1,3],[2,6],[8,10],[15,18]]
  // output: [[1,6],[8,10],[15,18]]

  std::vector<std::vector<int>> intervals {
    {1, 3}, {2, 6}, {8, 10}, {15, 18}
  };

  std::vector<std::vector<int>> merged {
    {1, 6}, {8, 10}, {15, 18}
  };

  ASSERT_EQ(merger.merge(intervals), merged);
}