#ifndef INCLUDED_DP_KNAPSACK_416_PARTITION_EQUAL_SUBSET_SUM
#define INCLUDED_DP_KNAPSACK_416_PARTITION_EQUAL_SUBSET_SUM

namespace leetcode {

/** @brief: partition equal subset sum
 *  Given a non-empty array nums containing only positive integers,
 *  find if the array can be partitioned into two subsets
 *  such that the sum of elements in both subsets is equal.
 **/

class Solution {
public:
  bool canPartition(std::vector<int>& nums) {
    return can_partition_2(nums);
  }

private:
  bool can_partition_1(std::vector<int> &nums)
  {
     // sum must be even
    // target = sum/2

    // dp[i][j]: for range [0, i], is it able to sum up random elements to be j
    // dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]]
    //            ----------   ------------------
    //            exclude j       include j

    int sum = std::accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 == 1)
      return false;

    sum /= 2;
    int n = nums.size();

    std::vector<std::vector<bool>> dp(n, std::vector<bool>(sum+1, false));

    dp[0][0] = true;
    if (nums[0] < sum+1)
      dp[0][nums[0]] = true;

    for (auto i = 1; i != n; ++i)
    {
      for (auto j = 1; j != sum+1; ++j)
      {
        dp[i][j] = dp[i-1][j];
        if (nums[i] <= j)
          dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]]; // can be compressed
      }
    }

    return dp.back().back();
  }

  bool can_partition_2(std::vector<int> &nums)
  {
    // compress the memory usage
    int sum = std::accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 == 1)
      return false;

    sum /= 2;

    std::vector<bool> dp(sum+1, false);

    dp[0] = true;

    for (auto i = 0; i != nums.size(); ++i)
      for (auto j = sum; j >= nums[i]; --j)
        dp[j] = dp[j] | dp[j-nums[i]];

    return dp.back();
  }

};

} // end namespace leetcode

#endif