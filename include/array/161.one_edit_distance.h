#ifndef INCLUDED_ARRAY_161_ONE_EDIT_DISTANCE
#define INCLUDED_ARRAY_161_ONE_EDIT_DISTANCE

namespace leetcode {

/** @brief: One Edit Distance
 *  Given two strings s and t, return true
 *  if they are both one edit distance apart, otherwise return false.
 **/

class Solution {
public:
  bool isOneEditDistance(string s, string t) {

    if (s.size() < t.size())
      std::swap(s, t);

    if (s.size() - t.size() > 1)
      return false;

    auto sp = s.c_str();
    auto tp = t.c_str();

    for (auto i = 0; i != t.size(); ++i)
    {
      if (s[i] == t[i])
        continue;

      if (s.size() == t.size())
        return std::strcmp(sp+1+i, tp+i+1) == 0;
      else
        return std::strcmp(sp+1+i, tp+i) == 0;
    }

    return s.size() == t.size()+1;
  }
};

} // end namespace leetcode

#endif

