#ifndef INCLUDED_ARRAY_TWO_POINTERS_76_MINIMUM_WINDOW_SUBSTRING
#define INCLUDED_ARRAY_TWO_POINTERS_76_MINIMUM_WINDOW_SUBSTRING

#include <vector>
#include <string>

namespace leetcode {

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {

    // two pointers, l, and r,
    // if s[l, r] contains the whole t
    //   shrink the l till cannot contains the whole t
    // move the r again to find another satisfied window

    std::unordered_map<char, int> counts;

    for (auto &c: t)
    {
      auto it = counts.insert({c, 0});
      it.first->second ++;
    }

    int contained = 0;

    int pos = -1;
    int min_len = INT_MAX;

    for (auto l = 0, r = 0; r != s.size(); ++r)
    {
      auto found = counts.find(s[r]);
      if (found == counts.end())
        continue;

      if (--found->second == 0)
        contained ++;

      while (contained == counts.size())
      {
        // l shouldn't be larger r,
        // since a empty window cannot contains the whole t

        assert (l <= r);
        if (min_len > r-l+1)
        {
          min_len = r-l+1;
          pos = l;
        }

        auto it = counts.find(s[l]);

        if (it != counts.end() && ++it->second > 0)
          contained --;

        ++l;
      }
    }

    return (min_len == INT_MAX)? "": s.substr(pos, min_len);
  }
};

} // end namespace leetcode

#endif