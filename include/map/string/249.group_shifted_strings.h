#ifndef INCLUDED_MAP_STRING_249_GROUP_SHIFTED_STRING
#define INCLUDED_MAP_STRING_249_GROUP_SHIFTED_STRING

#include <vector>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
  /**
   * @brief group shifted strings
   *        For example, "abc" can be shifted to be "bcd".
   */
  std::vector<std::vector<std::string>>
    groupStrings(std::vector<std::string>& strings)
  {
    std::unordered_map<std::string, int> m;
    //                 -----------  ---
    //                gradient str  group index

    // gradient str: abd -> 12 and zac -> 12
    //   how can zac to be 12, 'a' + 26 - 'z' = '1'
    // group index:  which group it should be in

    std::vector<std::vector<std::string>> groups;
    groups.reserve(strings.size());

    for (auto &s: strings)
    {
      std::string tmp;
      tmp.reserve(s.size());

      if (s.empty())          tmp = s;
      else if (s.size() == 1) tmp = "a";

      for (auto i = 1; i != s.size(); ++i)
        tmp.append(1, s[i] > s[i-1] ? s[i]-s[i-1]: s[i]+26-s[i-1]);

      auto it = m.insert({tmp, groups.size()});

      if (it.second)
        groups.push_back(std::vector<std::string>());

      groups[it.first->second].push_back(s);
    }

    return groups;
  }
};

} // end namespace leetcode

#endif
