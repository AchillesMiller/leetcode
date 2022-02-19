#ifndef INCLUDED_GREEDY_ALGORITHM_PARENTHESIS_1249_MINIMUM_REMOVE
#define INCLUDED_GREEDY_ALGORITHM_PARENTHESIS_1249_MINIMUM_REMOVE

#include <string>
#include <vector>

namespace leetcode {

class Solution {
public:
  std::string minRemoveToMakeValid(std::string s)
  {
    std::vector<int> lefts;
    lefts.reserve(s.size());

    for (auto i = 0; i != s.size(); ++i)
    {
      if (s[i] == '(') // left parenthesis
        lefts.push_back(i);
      else if (s[i] == ')')
      {
        if (lefts.empty()) // right unbalanced
          s[i] = ' ';
        else
          lefts.pop_back();
      }
    }

    // all unbalanced left/right parenthesis are changed to be ' '

    for (auto &l: lefts)
      s[l] = ' ';

    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    return s;
  }
};

} // end namespace leetcode

#endif
