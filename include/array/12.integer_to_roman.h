#ifndef INCLUDED_ARRAY_12_INTEGER_TO_ROMAN
#define INCLUDED_ARRAY_12_INTEGER_TO_ROMAN

namespace leetcode {

/** @brief: integer to roman
 *  Roman numerals are represented by seven different symbols:
 *  I, V, X, L, C, D and M.
 **/

class Solution {
public:
  string intToRoman(int num) {

    static const std::vector<std::pair<char, int>> ones = {
      {'I', 1},
      {'X', 10},
      {'C', 100},
      {'M', 1000}
    };

    static const std::vector<std::pair<char, int>> fives = {
      {'V', 5},
      {'L', 50},
      {'D', 500}
    };

    std::string roman;

    while (num > 0)
    {
      int i = ones.size()-1;
      while (num < ones[i].second)
        --i;

      int digit = num / ones[i].second;

      switch (digit)
      {
        case 1:
        case 2:
        case 3:
          roman.append(digit, ones[i].first);
          break;
        case 4:
          roman.append(1, ones[i].first);
          roman.append(1, fives[i].first);
          break;
        case 5:
          roman.append(1, fives[i].first);
          break;
        case 6:
        case 7:
        case 8:
          roman.append(1, fives[i].first);
          roman.append(digit-5, ones[i].first);
          break;
        case 9:
          roman.append(1, ones[i].first);
          roman.append(1, ones[i+1].first);
          break;
      }

      num %= ones[i].second;
    }

    return roman;
  }
};

// 1 -> I, 5 -> X, 10 -> V

// 1: I
// 2: II
// 3: III    ---->  [1, 3] I x 3
// 4: IV     ---->  [4, 4] I V
// 5: V
// 6: VI
// 7: VII
// 8: VIII   -----> [6, 8] V I x (n-5)
// 9: IX

} // end namespace leetcode

#endif