#ifndef INCLUDED_DP_64_MINIMUM_PATH_SUM
#define INCLUDED_DP_64_MINIMUM_PATH_SUM

namespace leetcode {

/** @brief: minimum path sum
 *  Given a m x n grid filled with non-negative numbers,
 *  find a path from top left to bottom right,
 *  which minimizes the sum of all numbers along its path.
 *
 *  Note: You can only move either down or right at any point in time.
 **/

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    std::vector<int> mins(n, INT_MAX);

    mins[0] = grid[0][0];

    for (auto i = 1; i != n; ++i)
      mins[i] = mins[i-1] + grid[0][i];

    for (auto i = 1; i != m; ++i)
    {
      mins[0] += grid[i][0];

      for (auto j = 1; j != n; ++j)
        mins[j] = std::min(mins[j], mins[j-1]) + grid[i][j];
    }

    return mins.back();
  }
};

} // end namespace leetcode

#endif