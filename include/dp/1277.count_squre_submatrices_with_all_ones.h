#ifndef INCLUDED_DP_1277_COUNT_SQUARE_SUB_MATRICES_WITH_ALL_ONES
#define INCLUDED_DP_1277_COUNT_SQUARE_SUB_MATRICES_WITH_ALL_ONES

#include <vector>

namespace leetcode {

/** @brief: Given a m * n matrix of ones and zeros,
 *  return how many square submatrices have all ones.
 **/

class Solution {
public:
  int countSquares(std::vector<std::vector<int>>& matrix) {
    // Given a m * n matrix of ones and zeros,
    // return how many square sub-matrices have all ones.
    return count_squares_2(matrix);
  }

private:
  int count_squares_1(std::vector<std::vector<int>> &matrix)
  {
    // dp[i][j]: how many squares ended in (i, j)
    // which can be interpreted as the max side of square ended in (i, j)

    // dp[i][j] = min{dp[i-1][j], dp[i][j-1], dp[i-1][j-1]} + 1
    //            if matrix[i][j] == 1 else 0

    int m = matrix.size();
    int n = matrix.front().size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    dp[0] = matrix[0];

    int count = std::accumulate(dp[0].begin(), dp[0].end(), 0);

    for (auto i = 1; i != m; ++i)
    {
      dp[i][0] = matrix[i][0];

      count += dp[i][0];

      for (auto j = 1; j != n; ++j)
      {
        if (matrix[i][j] == 1)
          dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;

        count += dp[i][j];
      }
    }

    return count;
  }

  int count_squares_2(std::vector<std::vector<int>> &matrix)
  {
    // dp[i][j] = min{dp[i-1][j], dp[i][j-1], dp[i-1][j-1]} + 1
    //                ----------  ----------  ------------
    //                  top          left        topleft

    // rolling vector to compress the memory complexity

    int m = matrix.size();
    int n = matrix[0].size();

    std::vector<int> dp = matrix[0];

    int count = std::accumulate(dp.begin(), dp.end(), 0);

    for (auto i = 1; i != m; ++i)
    {
      // set first
      int topleft = dp[0];
      dp[0] = matrix[i][0];
      count += dp[0];

      for (auto j = 1; j != n; ++j)
      {
        int top = dp[j];
        int left = dp[j-1];

        if (matrix[i][j] == 1)
          dp[j] = std::min({top, left, topleft}) + 1;
        else // clean j-th dp
          dp[j] = 0;

        topleft = top;

        count += dp[j];
      }
    }

    return count;
  }

};

} // end namespace leetcode

#endif