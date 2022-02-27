#ifndef INCLUDED_DP_139_WORD_BREAK
#define INCLUDED_DP_139_WORD_BREAK

namespace leetcode {

/** @brief: Word Break
 *  Given a string s and a dictionary of strings wordDict,
 *  return true if s can be segmented into
 *  a space-separated sequence of one or more dictionary words.
 *
 *  Note that the same word in the dictionary
 *  may be reused multiple times in the segmentation.
 **/

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict)
  {
    int n = s.size();
    std::vector<bool> dp(n, false);

    std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());

    for (auto i = 0; i != n; ++i)
      if (words.find(s.substr(0, i+1)) != words.end())
        dp[i] = true;

    if (dp.back())
      return true;

    for (auto i = 0; i != n; ++i)
    {
      if (!dp[i])
        continue;

      for (auto j = i+1; j != n; ++j)
        if (words.find(s.substr(i+1, j-(i+1)+1)) != words.end())
          dp[j] = true;

      if (dp.back())
        return true;
    }

    return dp.back();
  }
};

} // end namespace leetcode

#endif