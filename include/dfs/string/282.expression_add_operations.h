#ifndef INCLUDED_DFS_STRING_282_EXPRESSION_ADD_OPERATION
#define INCLUDED_DFS_STRING_282_EXPRESSION_ADD_OPERATION

#include <string>
#include <vector>

class Solution {
public:
  /**
   * @brief expression add operations
   *        Add any operations to meet this requirement
   **/
  std::vector<std::string> addOperators(std::string num, int target) {

    // when noticing the result is a container a string
    // it is obvious to use dfs solution
    // each time, + means the current operand will be added to value
    // while      - means the current operand will be erased from value
    //=================================================================
    // and, if + and -, the current operand is cached since it is potential
    // to be used in the next *

    // leading 0 makes no sense

    std::vector<std::string> exprs;

    std::string expr;
    expr.reserve(num.size() * 2);

    dfs(num, target, 0, 0, 0, expr, exprs);
    return exprs;
  }

 private:
  void dfs(const std::string &num, int target, int i,
           long value,
           long last,
           std::string &expr,
           std::vector<std::string> &exprs)
  {
    if (i == num.size())
    {
      if (target == value)
        exprs.push_back(expr.substr(1));
      return;
    }

    std::string sub;
    sub.reserve(num.size()-i);

    int size = expr.size();

    for (auto j = i; j < num.size(); ++j)
    {
      if (sub == "0") // sub == "0", should give up all following dfs
        break;
      // append the j
      sub.append(1, num[j]);

      long curr = stol(sub);

      // add expression
      expr.append(1, '+').append(sub);
      dfs(num, target, j+1, value+curr, curr, expr, exprs);
      expr.erase(size);   // back tracing

      if (i == 0) continue; // only allow + for 0 index

      // minus expression
      expr.append(1, '-').append(sub);
      dfs(num, target, j+1, value-curr, -curr, expr, exprs);
      expr.erase(size);

      // multiply expression
      expr.append(1, '*').append(sub);
      dfs(num, target, j+1, value-last+last*curr,    last*curr, expr, exprs);
      //                    -----------------------   ---------
      //                    erase last and last*curr  modify last
      expr.erase(size);
    }
  }
};

#endif
