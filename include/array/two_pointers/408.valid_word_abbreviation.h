#ifndef INCLUDED_ARRAY_TWO_POINTERS_408_VALID_WORD_ABBREVIATION
#define INCLUDED_ARRAY_TWO_POINTERS_408_VALID_WORD_ABBREVIATION

#include <string>

namespace leetcode {

class Solution {
public:
  bool validWordAbbreviation(std::string word, std::string abbr) {

    // s2t == sort

    int i = 0, j = 0;

    while(i < word.size() && j < abbr.size())
    {
      if (!std::isdigit(abbr[j]))
      {
        if (word[i] == abbr[j])
        {
          ++i;
          ++j;
          continue;
        }
        return false;
      }

      if (abbr[j] == '0') // leading 0
        return false;

      int s = j;

      // increment j
      while (j < abbr.size() && std::isdigit(abbr[j]))
        ++j;

      int n = stoi(abbr.substr(s, j-s));

      // increment i
      i+= n;
    }

    return i == word.size() & j == abbr.size();
  }
};

} // end namespace leetcode

#endif