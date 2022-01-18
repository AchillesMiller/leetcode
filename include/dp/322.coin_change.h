#ifndef INCLUDED_DP_322_COIN_CHANGE
#define INCLUDED_DP_322_COIN_CHANGE

#include <vector>

namespace leetcode {

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    // give coins and amount,
    // return the fewest coins you can use

    // dp[i]: minimum coins of which the sum == i
    // dp[i] = min{dp[i-nums[j]} + 1

    std::vector<int> dp(amount+1, INT_MAX);

    dp[0] = 0; // using 0 coins to form value 0

    for (auto i = 1; i <= amount; ++i)
      for (auto &coin: coins)
        if (i-coin >= 0 && dp[i-coin] != INT_MAX)
          dp[i] = std::min(dp[i-coin]+1, dp[i]);

    return (dp.back() == INT_MAX)? -1: dp.back();
  }
};

} // end namespace leetcode

#endif
