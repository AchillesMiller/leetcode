#ifndef INCLUDED_DFS_339_NESTED_LIST_WEIGHT_SUM
#define INCLUDED_DFS_339_NESTED_LIST_WEIGHT_SUM

namespace leetcode {

/** @brief: nested list weight sum
 *  You are given a nested list of integers nestedList.
 *  Each element is either an integer or a list whose elements
 *  may also be integers or other lists.
 *
 *  Return the sum of each integer in nestedList multiplied by its depth.
 **/

class Solution {
public:
  int depthSum(vector<NestedInteger>& nestedList) {

    // [ [1, 1], 2, [1, 1]]

    // 1 x 2 + 1 x 2 + 2 + 1 x 2 + 1 x 2

    int sum = 0;

    for (auto &x: nestedList)
      sum += dfs(x, 1);

    return sum;
  }

private:
  int dfs(NestedInteger &x, int depth)
  {
    if (x.isInteger())
      return depth * x.getInteger();

    int sum = 0;

    for (auto &next: x.getList())
      sum += dfs(next, depth+1);

    return sum;
  }

};

} // end namespace leetcode

#endif