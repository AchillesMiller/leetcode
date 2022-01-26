#ifndef INCLUDED_DP_STOCK_309_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN
#define INCLUDED_DP_STOCK_309_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN

namespace leetcode {

/** @brief: best time to buy and sell stock with cooldown
 * You are given an array prices where prices[i]
 * is the price of a given stock on the ith day.
 *
 * Find the maximum profit you can achieve.
 * You may complete as many transactions as you like
 * (i.e., buy one and sell one share of the stock multiple times)
 * with the following restrictions:
 *
 * After you sell your stock, you cannot buy stock on the next day
 * (i.e., cooldown one day).
 * Note: You may not engage in multiple transactions simultaneously
 * (i.e., you must sell the stock before you buy again).
 **/

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    return max_profit_compressed(prices);
  }

private:

  int max_profit_dp(std::vector<int> &prices)
  {
    // if sell, cannot buy next day
    // for day i,
    // buy[i] = maximum benefits for previous i days and last operation is buy
    // sell[i] = maximum benefit for previous i days and last operation is sell

    // buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
    // sell[i] = max(buy[i] + prices[i], sell[i-1]);

    int n = prices.size();

    if (n <= 1)
      return 0;

    std::vector<int> buy(n, 0);
    std::vector<int> sell(n, 0);

    buy[0] = -prices[0];
    buy[1] = std::max(-prices[0], -prices[1]);

    sell[0] = 0;
    sell[1] = std::max(0, prices[1]-prices[0]);

    for (auto i = 2; i != prices.size(); ++i)
    {
      buy[i] = std::max(buy[i-1], sell[i-2] - prices[i]);
      sell[i] = std::max(buy[i] + prices[i], sell[i-1]);
    }

    return sell.back();
  }

  int max_profit_compressed(std::vector<int> &prices)
  {
    // buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
    // sell[i] = max(buy[i] + prices[i], sell[i-1]);

    // sells[i] = max{buy[i-1] + prices[i], sell[i-2], sell[i-1]}

    if (prices.size() <= 1)
      return 0;

    int buy_minus_1 = 0;
    int sell_minus_1 = 0;
    int sell_minus_2 = 0;

    buy_minus_1 = std::max(-prices[0], -prices[1]); // i = 2; i -1 = 1;
    sell_minus_2 = 0; // i = 2; i-2 = 0
    sell_minus_1 = std::max(0, prices[1]-prices[0]); // i = 2; i -1 = 1;

    for (auto i = 2; i != prices.size(); ++i)
    {
      int buy = std::max(sell_minus_2 - prices[i], buy_minus_1);
      int sell = std::max(buy + prices[i], sell_minus_1);

      buy_minus_1 = buy;
      sell_minus_2 = sell_minus_1;
      sell_minus_1 = sell;
    }

    return sell_minus_1;
  }

};

} // end namespace leetcode

#endif