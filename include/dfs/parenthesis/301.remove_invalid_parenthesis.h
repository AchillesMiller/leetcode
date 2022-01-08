#ifndef INCLUDED_DFS_PARENTHESIS_301_REMOVE_INVALID_PARENTHESIS
#define INCLUDED_DFS_PARENTHESIS_301_REMOVE_INVALID_PARENTHESIS

#include <vector>
#include <string>

namespace leetcode {

class Solution {
public:
  /**
   * @brief remove invalid parenthesis
   *        Given a string s that contains parentheses and letters,
   *        remove the minimum number of invalid parentheses
   *        to make the input string valid.
   **/
  std::vector<std::string> removeInvalidParentheses(std::string s) {
    // firstly, we need get the minimum invalid parenthesis number
    // with that number, we can use dfs to get valid string

    int invalid = minimum_to_remove(s);

    std::string valid;
    valid.reserve(s.size()-invalid);

    std::vector<std::string> valids;

    int left = 0;

    dfs(s, 0, left, s.size()-invalid, valid, valids);

    return valids;
  }

 private:

  int minimum_to_remove(std::string &s)
  {
    int l = 0, r = 0;

    for (auto &c: s)
    {
      switch(c)
      {
        case '(': l ++; break;
        case ')': -- l; break;
      }

      if (l < 0)
      {
        r ++;
        l = 0;
      }
    }

    return l+r;

  }

  void dfs(std::string &s, int start, int left, int max_len,
           std::string &valid,
           std::vector<std::string> &valids)
  {
    // those scenarios are invalid
    if (left < 0 || valid.size() > max_len)
      return;

    if (start == s.size())
    {
      if (left == 0 && valid.size() == max_len)
        valids.push_back(valid);
      return;
    }

    auto &c = s[start];

    // for the `c`, we want to remove it, add it

    if (c != '(' && c != ')')
    {
      valid.append(1, c);
      dfs(s, start+1, left, max_len, valid, valids);
      valid.pop_back();
      return;
    }

    // ((((
    // if first ( is added, others should be added
    // by this way, we can get ((((, (((, ((, (

    valid.append(1, c);
    dfs(s, start+1, (c == '(')? left+1: left-1, max_len, valid, valids);
    valid.pop_back();

    if (valid.empty() || valid.back() != c) // we skip it
      dfs(s, start+1, left, max_len, valid, valids);
  }
};

} // end namespace leetcode

#endif
