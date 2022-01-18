#ifndef INCLUDED_DP_1937_MAXIMUM_NUMBER_OF_POINTS_WITH_COST
#define INCLUDED_DP_1937_MAXIMUM_NUMBER_OF_POINTS_WITH_COST

#include <vector>

// similar question with 42 trapping rain water
// two passes, one from let to right, one from right to left
// abs function is a clue to think k <= j and k > j

namespace leetcode {

class Solution {
public:
  /**
   * @brief Maximum number of points with cost
   * @example
   *  1   2  (3)
   *  1  (5)  1
   * (3)  1   1
   *  3 + 5 - (2-1) + 3 - (1-0) = 9
   **/
  long long maxPoints(std::vector<std::vector<int>>& points) {

    // dp[i][j] = max{dp[i-1][k] - abs(j-k)} + points[i][j]
    // where 0 <= k < n
    //  max{dp[i-1][k] - abs(j-k) } + points[i][j] = max (
    //     max{dp[j-1][k1]} + k1 + points[i][j] - j,  where k1 <= j
    //     max{dp[j-1][k2]} - k2 + points[i][j] + j,  where k2 > j
    // )

    // that means, we need max rolling, of both left to right and right to left

    int m = points.size();
    int n = points[0].size();

    std::vector<long long> dp;
    dp.reserve(n);

    for (auto &point: points[0])
      dp.push_back(point);

    std::vector<long long> curr(dp.size(), 0);

    for (auto i = 1; i != m; ++i)
    {
      long long max = std::numeric_limits<long long>::min();

      for (auto j = 0; j != n; ++j)
      {
        max = std::max(max, dp[j] + j);
        curr[j] = max + points[i][j] - j;
      }

      max = std::numeric_limits<long long>::min();

      for (int j = n-1; j >= 0; --j)
      {
        max = std::max(max, dp[j] - j);
        curr[j] = std::max(max + points[i][j] + j, curr[j]);
      }

      std::swap(dp, curr);
    }

    long long max_dist = std::numeric_limits<long long>::min();

    for (auto &x: dp)
      max_dist = std::max(x, max_dist);


    return max_dist;
  }
};

} // end namespace leetcode

#endif