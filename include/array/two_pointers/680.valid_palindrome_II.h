#ifndef INCLUDED_ARRAY_TWO_POINTERS_680_VALID_PALINDROME_II
#define INCLUDED_ARRAY_TWO_POINTERS_680_VALID_PALINDROME_II

#include <string>

namespace leetcode {

class Solution {
public:
  bool validPalindrome(std::string s)
  {
    return valid(s, 0, s.size()-1);
  }

private:
  bool valid(const std::string &s, int l, int r, bool deleted=false)
  {
    // checking if range [l, r] is valid palindrome
    // two pointers algorithm

    while (l < r)
    {
      if (s[l] == s[r])
      {
        ++l;
        --r;
        continue;
      }

      if (deleted)
        return false;

      return valid(s, l+1, r, true) || valid(s, l, r-1, true);
    }

    return true;
  }

};

} // end namespace leetcode

#endif
