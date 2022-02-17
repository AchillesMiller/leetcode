#ifndef INCLUDED_STACK_227_BASIC_CALCULATOR_II
#define INCLUDED_STACK_227_BASIC_CALCULATOR_II

namespace leetcode {

/** @brief: basic calculator II
 *  Given a string s which represents an expression,
 *  evaluate this expression and return its value.
 **/

class Solution {
public:
  int calculate(std::string s) {

    // 1 + 2 * 3
    // prev   0  1  2
    // value  1  3  3 - 2 + 2 * 3

    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    int64_t prev = 0;
    int64_t value = 0;

    int i = 0;

    s.insert(s.begin(), '+');

    while (i < s.size())
    {
      char &op = s[i++];

      int64_t curr = 0;

      while (i < s.size() && std::isdigit(s[i]))
      {
        curr = 10 * curr + s[i] - '0';
        ++i;
      }

      switch(op)
      {
        case '+':
          value += curr;
          prev = curr ;
          break;
        case '-':
          value -= curr;
          prev = -curr;
          break;
        case '*':
          value = value - prev + prev * curr;
          prev = prev *curr;
          break;
        case '/':
          value = value - prev + prev / curr;
          prev = prev/curr;
          break;
      }
    }

    return value;
  }
};

// have a status: prev for stack

} // end namespace leetcode


#endif