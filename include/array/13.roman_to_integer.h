#ifndef INCLUDED_ARRAY_13_ROMAN_TO_INTEGER
#define INCLUDED_ARRAY_13_ROMAN_TO_INTEGER

namespace leetcode {

/** @brief: roman to integer
 *  Roman numerals are represented by seven different symbols:
 *  I, V, X, L, C, D and M.
 **/

class Solution {
public:
  int romanToInt(string s) {

    static std::unordered_map<char, int> romans = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
    };

    int val = 0;
    int prev = 0;

    for (auto i = 0; i != s.size(); ++i)
    {
      auto curr = romans[s[i]];

      // revert the add in previous step
      // and, add curr-prev to the final val
      if (curr == prev * 5 || curr == prev * 10)
        val = val - 2 * prev;

      val += curr;
      prev = curr;
    }

    return val;
  }
};

} // end namespace leetcode

#endif