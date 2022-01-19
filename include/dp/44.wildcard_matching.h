#ifndef INCLUDED_DP_44_WILDCARD_MATCHING
#define INCLUDED_DP_44_WILDCARD_MATCHING

#include <string>

namespace leetcode {

class Solution {

public:
  bool isMatch(std::string s, std::string p) {
    return is_match_dp(s, p);
  }
private:
  bool is_match_dp(const std::string & s, const std::string &p)
  {
    // string(s) matches pattern(p)

    if (s.empty()) // s is empty
      return p.find_first_not_of('*') == std::string::npos;

    if (p.empty()) // p is empty
      return s.empty();

    int m = s.size();
    int n = p.size();

    std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));

    // dp[i][j]: s[0, i) matches p[0, j)
    // dp[i][j] = dp[i-1][j-1] if s[i-1] == p[j-1]
    //          = dp[i][j-1]   if p[j-1] == '?'
    //          = | dp[k][j-1] if p[j] == '*' where 0<=k<=i

    // base statement:
    // dp[0][x]:    s: ''
    //              p: * * * * * ?
    //                 1 1 1 1 1 0

    // dp[x][0] = 0

    // dp[0][x]  * * *
    for (auto i = 0; i != n; ++i)
    {
      if (p[i] != '*')
        break;
      dp[0][i+1] = true;
    }

    dp[0][0] = true;

    for (auto i = 1; i <= m; ++i)
      for (auto j = 1; j <= n; ++j)
      {
        if (s[i-1] == p[j-1] || p[j-1] == '?')
          dp[i][j] = dp[i-1][j-1];

        if (p[j-1] == '*')
        {
          /**
          for (auto k = 0; k <= i; ++k)
            if (dp[k][j-1])
            {
              dp[i][j] = true;
              break;
            }
          **/

          // x x x    ==    x x
          // *              *

          dp[i][j] = dp[i-1][j] | dp[i][j-1];
        }
      }

    return dp.back().back();
  }
};

// s: abc
// p: ab*

} // end namespace leetcode

#endif