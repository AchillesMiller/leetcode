#ifndef INCLUDED_DP_63_UNIQUE_PATHS_II
#define INCLUDED_DP_63_UNIQUE_PATHS_II

namespace leetcode {

/** @brief: unique paths with obstacle
 *  how many unique paths would there be from top left to bottom right
 **/

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    std::vector<int> dp(n, 0);

    for (auto j = 0; j != n; ++j)
      if (obstacleGrid[0][j] == 0)
        dp[j] = 1;
      else
        break;

    for (auto i = 1; i != m; ++i)
    {
      dp[0] = (obstacleGrid[i][0] == 0)? dp[0] : 0;

      for (auto j = 1; j != n; ++j)
      {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else
          dp[j] += dp[j-1];
      }
    }

    return dp.back();
  }
};

} // end namespace leetcode

#endif