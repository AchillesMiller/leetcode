#include "gtest/gtest.h"

#include <56/merge_intervals.56.h>

TEST(merge_intervals, A)
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