#ifndef INCLUDED_DP_140_WORD_BREAK_II
#define INCLUDED_DP_140_WORD_BREAK_II

namespace leetcode {

/** @brief: word break II
 *  Given a string s and a dictionary of strings wordDict,
 *  add spaces in s to construct a sentence where each word
 *  is a valid dictionary word. Return all such possible sentences in any order.
 *
 *  Note that the same word in the dictionary
 *  may be reused multiple times in the segmentation.
 **/

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {

    // find all breaks
    // [a, b, c, bc]
    // abc -> "a b c" and "a bc"

    std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());

    int n = s.size();
    std::vector<std::vector<std::string>> dp(n);
    // dp[i] is word breaks for s[0: i]

    for (auto i = 0; i != n; ++i)
    {
      auto sub = s.substr(0, i+1);

      if (words.find(sub) != words.end())
        dp[i].push_back(sub);
    }

    // for each index i, if there exists breaks for [0, i], dp[i] is not empty
    // check [i+1, n) to update dp[j]

    for (auto i = 0; i != n; ++i)
    {
      if (dp[i].empty())
        continue;

      for (auto j = i+1; j != n; ++j)
      {
        auto sub = s.substr(i+1, j - (i+1) + 1);

        if (words.find(sub) != words.end())
        {
          dp[j].reserve(dp[j].size() + dp[i].size());

          for (auto &x: dp[i])
            dp[j].push_back(x + " " + sub);
        }
      }
    }

    return dp.back();
  }
};

} // end namespace leetcode

#endif