#ifndef INCLUDED_STACK_772_BASIC_CALCULATOR_III
#define INCLUDED_STACK_772_BASIC_CALCULATOR_III

namespace leetcode {

/** @brief: basic calculator III
 *  Implement a basic calculator to evaluate a simple expression string.
 *  The expression contains +, -, *, / and ( and )
 **/

class Solution {
public:
  int calculate(std::string s)
  {
    // let's evaluate string without parenthesis
    // so, 1 * ( 2 + 3), we want to

    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    std::stack<std::string> stk;

    std::string curr;
    curr.reserve(s.size());

    curr = "+";

    for (auto i = 0; i != s.size(); ++i)
    {
      auto &c = s[i];

      switch(c)
      {
        case '(':
          stk.push(curr);
          curr.clear();
          curr = "+";
          break;
        case ')':
          curr = stk.top() + std::to_string(eval(curr));
          stk.pop();
          break;
        default:
          curr.append(1, c);
          break;
      }
    }

    return eval(curr);
  }

  int64_t eval(const std::string &s)
  {
    // 1 + 2 * 3
    // prev   0  1  2
    // value  1  3  3 - 2 + 2 * 3
    int64_t prev = 0;
    int64_t value = 0;

    auto s2i = [](const std::string &s, int &i) -> int64_t
    {
      int sign = (s[i] == '-')? -1: 1;
      if (sign == -1)
        ++i;

      int64_t val = 0;

      while (i < s.size() && std::isdigit(s[i]))
        val = 10 *val + sign * (s[i++] - '0');

      return val;
    };

    int i = 0;

    while (i < s.size())
    {
      char op = s[i++];

      int64_t curr = s2i(s, i);

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

// 1. we want to convert expression with parenthesis with plain expression
// 2. we want to calculate that expression
// 3. 1 - (2 - 3) will become to be 1 -- 1, so, it should be 1 - -1


} // end namespace leetcode

#endif