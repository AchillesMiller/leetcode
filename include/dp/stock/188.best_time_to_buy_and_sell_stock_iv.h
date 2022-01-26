#ifndef INCLUDED_DP_STOCK_188_BEST_TIME_TO_BUY_AND_SELL_STOCK_IV
#define INCLUDED_DP_STOCK_188_BEST_TIME_TO_BUY_AND_SELL_STOCK_IV

namespace leetcode {

/** @brief: best time to buy and sell stock at most k transactions
 * You are given an integer array prices where prices[i]
 * is the price of a given stock on the ith day, and an integer k.
 *
 * Find the maximum profit you can achieve.
 * You may complete at most k transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously
 * (i.e., you must sell the stock before you buy again).
 **/

class Solution {
public:
  int maxProfit(int k, std::vector<int>& prices)
  {
    return max_profit_dp(k, prices);
  }

private:
  int max_profit_dp(int k, std::vector<int> &prices)
  {
    // at day i, we can hold stock k times, and sold stock k times
    std::vector<int> sold(k+1, 0);
    std::vector<int> hold(k+1, INT_MIN);

    // hold[k] = max(sold[k-1] - prices[i], hold[k])
    // sold[k] = max(hold[k] + prices[i], sold[k])

    sold[0] = 0;
    hold[0] = INT_MIN;

    for (auto i = 0; i != prices.size(); ++i)
    {
      for (auto j = 1; j <= k; ++j)
      {
        hold[j] = std::max(sold[j-1] - prices[i], hold[j]);
        sold[j] = std::max(hold[j] + prices[i], sold[j]);
      }
    }

    return sold.back();
  }

};

} // end namespace leetcode

#endif