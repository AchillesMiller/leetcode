#ifndef INCLUDED_DFS_ARRAY_39_COMBINATION_SUM
#define INCLUDED_DFS_ARRAY_39_COMBINATION_SUM

#include <vector>

namespace leetcode {

class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target)
  {
    // 1. can select candidate any times
    // 2. any candidate is distinct

    // dfs solution
    // a. we can skip this candidate
    // b. we can select this candidate any time

    combination_t c;
    c.reserve(candidates.size());

    combinations_t cs;

    dfs(candidates, 0, target, c, cs);
    return cs;
  }

private:
  using combination_t = std::vector<int>;
  using combinations_t = std::vector<combination_t>;

  void dfs(std::vector<int> &nums, int i, int target,
           combination_t &c, combinations_t &cs)
  {
    // base statement
    if (target == 0)
    {
      cs.push_back(c);
      return;
    }

    // prune
    if (target < 0 || i == nums.size())
      return;

    // choosing i
    c.push_back(nums[i]);
    dfs(nums, i, target-nums[i], c, cs);
    c.pop_back();

    // skip i
    dfs(nums, i+1, target, c, cs);
  }
};

} // end namespace leetcode


#endif