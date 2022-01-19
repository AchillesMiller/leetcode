#ifndef INCLUDED_DP_727_MINIMUM_WINDOW_SUBSEQUENCE
#define INCLUDED_DP_727_MINIMUM_WINDOW_SUBSEQUENCE

#include <string>

namespace leetcode {

class Solution {
public:
  std::string minWindow(std::string s1, std::string s2) {
    // Give s1 and s2, find the minimum window in s1 that contains s2 in order

    int m = s1.size();
    int n = s2.size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));

    // dp[0][0]
    dp[0][0] = (s1[0] == s2[0])? 0: INT_MAX;

    // dp[x][0]
    for (auto i = 1; i != m; ++i)
    {
      dp[i][0] = dp[i-1][0];
      if (s1[i] == s2[0])
        dp[i][0] = i;
    }

    // dp[0][x]
    for (auto i = 1; i != m; ++i)
    {
      for (auto j = 1; j != n; ++j)
        if (s1[i] == s2[j])
          dp[i][j] = dp[i-1][j-1];
        else
          dp[i][j] = dp[i-1][j];
    }


    int min_len = INT_MAX;
    int pos = -1;

    for (auto i = 0; i != m; ++i)
    {
      if (dp[i].back() != INT_MAX)
      {
        int len = i-dp[i].back()+1;
        if (min_len > len)
        {
          min_len = len;
          pos = dp[i].back();
        }
      }
    }

    if (pos == -1)
      return "";

    return s1.substr(pos, min_len);
  }
};

// dp[i][j] = k, the last index that make s1[k, i] contains s2[0, j]

// dp[i][j] = dp[i-1][j-1]                if s1[i] == s2[j]
//          = dp[i-1][j]                  otherwise

// base statement
// dp[0][0] = 0 if s1[0] == s2[0]
// dp[0][x] = INT_MAX if x >= 1
// dp[x][0] = last s2[0] in s1[0: x]


} // end namespace leetcode

#endif