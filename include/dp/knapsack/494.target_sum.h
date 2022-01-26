#ifndef INCLUDED_DP_KNAPSACK_494_TARGET_SUM
#define INCLUDED_DP_KNAPSACK_494_TARGET_SUM

namespace leetcode {

/**
 * You are given an integer array nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of
 * the symbols '+' and '-' before each integer in nums
 * and then concatenate all the integers.
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-'
 * before 1 and concatenate them to build the expression "+2-1".
 * Return the number of different expressions that you can build,
 * which evaluates to target.
 **/

class Solution {
public:
  int findTargetSumWays(std::vector<int>& nums, int target)
  {
    // dp[i][t] = dp[i-1][t-nums[i]] + dp[i-1][t+nums[i]]
    //            ------------------   ------------------
    //            include i with a +   include i with a -

    std::unordered_map<int, int> counts;

    auto it = counts.insert({nums[0], 0});
    ++it.first->second;

    it = counts.insert({-nums[0], 0});
    ++it.first->second;

    for (auto i = 1; i != nums.size(); ++i)
    {
      std::unordered_map<int, int> next;
      next.reserve(2*counts.size());

      for (auto &x: counts)
      {
        next[x.first+nums[i]] += x.second;
        next[x.first-nums[i]] += x.second;
      }

      std::swap(counts, next);
    }

    return counts[target];
  }
};

} // end namespace leetcode

#endif