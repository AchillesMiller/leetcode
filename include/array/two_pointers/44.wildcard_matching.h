#ifndef INCLUDED_ARRAY_TWO_POINTERS_44_WILDCARD_MATCHING
#define INCLUDED_ARRAY_TWO_POINTERS_44_WILDCARD_MATCHING

#include <vector>

namespace leetcode {

class Solution {
public:
  bool isMatch(std::string s, std::string p)
  {
    // two pointers i and j
    // if s[i] == p[j] || p[j] == '?', ++i, ++j
    // if p[j] == '*', skip it(++j)
    // if fails, go back to the previous star, and move i

    // it is a dfs solution with pruning

    int last_star = -1;
    int move_i = 0;

    int i = 0;
    int j = 0;

    while (i < s.size())
    {
      if (j < p.size() && (p[j] == s[i] || p[j] == '?'))
      {
        ++i;
        ++j;
      }
      else if (j < p.size() && p[j] == '*')
      {
        last_star = j;
        move_i = i;

        ++j; // skip star, matches 0
      }
      else if (last_star != -1)
      {
        i = ++move_i; // move_i go one more right, star matches several star
        j = last_star + 1;
      }
      else
        return false;
    }

    while (j < p.size() && p[j] == '*')
      ++j;

    return j == p.size();
  }
};

} // end namespace leetcode

#endif