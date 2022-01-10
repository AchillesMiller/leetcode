#ifndef INCLUDED_DP_PALINDROME_1216_VALID_PALINDROME_III
#define INCLUDED_DP_PALINDROME_1216_VALID_PALINDROME_III

#include <vector>
#include <string>

namespace leetcode {

class Solution {
public:
  /**
   * @brief is k-palindrome
   *         A string is k-palindrome if it can be transformed into
   *         a palindrome by removing at most k characters from it.
   **/
  bool isValidPalindrome(std::string s, int k) {
    // two pointer algorithm is firstly came into my mind,
    //   keep shrinking the left and right with k
    //   since it is recursive algorithm, the performance is O(nk)

    // dynamic programming
    //   k-palindrome question is equal to find largest palindrome sequence(L)
    //   checking k + L >= s.size()
    //   time performance is O(1+2+....n) = O(n * (n-1)/2)

    int lps = longest_palindrome_subsequence_II(s);

    return lps + k >= s.size();
  }

private:

  int longest_palindrome_subsequence(std::string &s)
  {
    int n = s.size();

    // lps[j][i]: longest palindrome subsequence in range [j, i]
    std::vector<std::vector<int>> lps(n, std::vector<int>(n, 0));

    // x 0 0      x 0 0     x x 0     x x  x''
    // 0 0 0  ->  0 x 0 ->  0 x 0  -> 0 x1 x'
    // 0 0 0      0 0 0     0 0 0     0 0  x2

    // x' = 0 +2 or std::max(x1, x2)

    // to compress the memory
    // it will use 1d array,  lps[j] = std::max(lps[j+1], lps[j])
    // and lps[j] will be cached each time before assigned

    // compressed solution is shown in longest_palindrome_subsequence_II

    for (auto i = 0; i != n; ++i)
    {
      lps[i][i] = 1;
      for (int j = i-1; j >= 0; --j)
      {
        if (s[i] == s[j])
          // if j+1 == j, dp[j+1][i-1] = 0
          lps[j][i] = lps[j+1][i-1] + 2;
        else
          lps[j][i] = std::max(lps[j+1][i], lps[j][i-1]);
      }
    }

    return lps[0].back();
  }

  int longest_palindrome_subsequence_II(std::string &s)
  {
    int n = s.size();

    std::vector<int> dp(n, 0);

    for (auto i = 0; i != n; ++i)
    {
      int cache = dp[i];
      dp[i] = 1;

      for (int j = i-1; j >= 0; --j)
      {
        int temp = dp[j];

        if (s[i] == s[j])
          dp[j] = cache + 2;
        else
          dp[j] = std::max(dp[j+1], dp[j]);

        cache = temp;
      }
    }
    return dp[0];
  }
};

} // end namespace leetcode


#endif