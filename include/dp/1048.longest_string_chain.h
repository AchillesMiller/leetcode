#ifndef INCLUDED_DP_1048_LONGEST_STRING_CHAIN
#define INCLUDED_DP_1048_LONGEST_STRING_CHAIN

#include <vector>
#include <string>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
  int longestStrChain(std::vector<std::string>& words) {
    // iterate the words from small size to large size

    std::size_t max_word = 0;

    for (auto &word: words)
      max_word = std::max(word.size(), max_word);

    std::vector<std::vector<int>> buckets(max_word+1);

    for (auto i = 0; i != words.size(); ++i)
      buckets[words[i].size()].push_back(i);

    std::unordered_map<std::string, int> lens;

    int max_len = 0;

    for (auto &bucket: buckets)
      for (auto &idx: bucket)
      {
        auto &word = words[idx];

        lens[word] = 1;

        // abc -> bc -> ac -> ab
        auto wor = word.substr(1);

        for (auto i = 0; i != word.size(); ++i)
        {
          // delete the char at index i
          auto found = lens.find(wor);
          // after finding, replace the i with word[i],
          // bc -> ac for i = 0
          // ac -> ab for i = 1
          if (i + 1 < word.size())
            wor[i] = word[i];

          if (found == lens.end()) // cannot find it
            continue;

          lens[word] = std::max(found->second+1, lens[word]);
        }

        max_len = std::max(max_len, lens[word]);
      }

    return max_len;
  }
};

// 1. dp[word] = std:max(dp[ord], dp[wrd], dp[wod], dp[wor]) + 1
// 2. using bucket sort to sort the words by the length of word


} // end namespace leetcode


#endif