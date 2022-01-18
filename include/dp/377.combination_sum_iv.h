#ifndef INCLUDED_DP_377_COMBINATION_SUM_IV
#define INCLUDED_DP_377_COMBINATION_SUM_IV

#include <vector>

namespace leetcode {

class Solution {
public:
  int combinationSum4(std::vector<int>& nums, int target) {
    // 1. one num can be used unlimited time

    std::vector<uint32_t> dp(target+1, 0);

    dp[0] = 1; // sum{} == 0

    for (auto i=1; i <= target; ++i)
      for (auto &num: nums)
        if (i-num >= 0)
          dp[i] += dp[i-num];

    return dp.back();
  }
};

} // end namespace leetcode

#endif