#ifndef INCLUDED_DP_96_UNIQUE_BINARY_SEARCH_TREES
#define INCLUDED_DP_96_UNIQUE_BINARY_SEARCH_TREES

namespace leetcode {

/** Given an integer n, return the number of structurally unique BST's
 *  (binary search trees)
 * which has exactly n nodes of unique values from 1 to n.
 **/

class Solution {
public:
  int numTrees(int n)
  {
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (auto i = 1; i <= n; ++i)
    {
      for (auto j = 0; j < i; ++j)
      {
        // number of left tree : j
        // number of right tree: i -j -1

        dp[i] += dp[j] * dp[i-j-1];
      }
    }

    return dp.back();
  }
};

} // end namespace leetcode

#endif