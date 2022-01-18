#ifndef INCLUDED_DFS_ARRAY_39_COMBINATION_SUM
#define INCLUDED_DFS_ARRAY_39_COMBINATION_SUM

#include <vector>

namespace leetcode {

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // 1. candidate is not distinct
    // 2. candidate can only use once
    // 3. combination should be unique

    // the idea is like building a tree
    // for one node i, we can append candidates[i+1, end) as child
    // but if we append candidates[j] as child of candidates[i]
    // trying to append candidates[k] which is equal to candidates[j]
    // is not necessary, this is how to produce unique combinations

    std::sort(candidates.begin(), candidates.end());

    combination_t c;
    c.reserve(candidates.size());

    combinations_t cs;

    dfs(candidates, 0, target, c, cs);
    return cs;
  }

private:
  using combination_t = std::vector<int>;
  using combinations_t = std::vector<combination_t>;

  void dfs(std::vector<int> & nums, int i, int target,
           combination_t &c, combinations_t &cs)
  {
    if (target == 0)
    {
      cs.push_back(c);
      return cs;
    }

    if (target < 0)
      return;

    // processing one layer
    for (auto j = i; j < nums.size(); ++j)
    {
      if (j-1 >= i && nums[j-1] == nums[j])
        continue;
      // selected i and continue dfs
      c.push_back(nums[j]);
      dfs(nums, j+1, target-nums[j], c, cs);
      c.pop_back();
    }
  }
};

} // end namespace leetcode

#endif