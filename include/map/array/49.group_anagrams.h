#ifndef INCLUDED_MAP_ARRAY_49_GROUP_ANAGRAMS
#define INCLUDED_MAP_ARRAY_49_GROUP_ANAGRAMS

namespace leetcode {

/** @brief: group anagrams
 *  Given an array of strings strs, group the anagrams together.
 *  You can return the answer in any order.
 *
 *  An Anagram is a word or phrase formed by rearranging the letters
 *  of a different word or phrase, typically
 *  using all the original letters exactly once.
 **/

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {

    std::unordered_map<std::string, std::vector<std::string>> m;
    m.reserve(strs.size());

    auto get_key = [](const std::string &s) -> std::string
    {
      int counts[26];

      for (auto i = 0; i != 26; ++i)
        counts[i] = 0;

      for (auto &c: s)
        counts[c-'a'] ++;

      std::string key;

      for (auto i = 0; i != 26; ++i)
      {
        if (counts[i] != 0)
          key.append(std::to_string(counts[i]));
        key.append(1, '#');
      }

      return key;
    };

    for (auto i = 0; i != strs.size(); ++i)
    {
      auto &s = strs[i];
      auto it =
        m.insert(std::make_pair(get_key(s), std::vector<std::string>{}));

      it.first->second.push_back(std::move(s));
    }

    std::vector<std::vector<std::string>> anagrams;
    anagrams.reserve(m.size());

    for (auto &x: m)
      anagrams.push_back(std::move(x.second));

    return anagrams;
  }
};

} // end namespace leetcode

#endif