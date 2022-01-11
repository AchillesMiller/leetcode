#ifndef INCLUDED_BINARY_SEARCH_1011_CAPACITY_TO_SHIP_PACKAGES_WITHIN_D_DAYS
#define INCLUDED_BINARY_SEARCH_1011_CAPACITY_TO_SHIP_PACKAGES_WITHIN_D_DAYS

namespace leetcode {

class Solution {
public:
  int shipWithinDays(std::vector<int>& weights, int days)
  {
    // find the minimum capacity that can ship the weights in order within
    // `days` days

    // this one can be solved by dynamic programming
    // dp[i][j]: the capacity to ship weights[0, i] in j days
    // dp[i][j] = std::min( std::max(dp[0][j-1], sum[1, i]),
    //                      std::max(dp[1][j-1], sum[2, i]),
    //                      std::max(dp[k][j-1], sum[k+1, i]),
    //                      std::max(dp[i-1][j-1], sum[i, i]))

    // time complexity is O(n * n * days)

    // the other solution is to use binary search,
    // similar to 1891 cutting ribbons

    int l = 0, r = 0;

    for (auto &weight: weights)
    {
      l = std::max(weight, l);
      r += weight;
    }

    while (l <= r)
    {
      int capacity = l + (r-l)/2;

      auto d = ship_days(weights, capacity);

      if (d <= days) // good, decrease the r to find another solution
        r = capacity-1;
      else
        l = capacity+1;
    }

    // if good, r will reduce
    // if not good, l will increase
    // since it is guaranteed to have solution, l is the answer

    return l;
  }

private:
  int ship_days(std::vector<int> &weights, int capacity)
  {
    int days = 0;
    int sum = 0;

    for (auto &weight: weights)
    {
      if (sum + weight > capacity)
      {
        ++days;
        sum = weight; // reset sum to be weight
      }
      else
        sum += weight;
    }

    ++days;

    return days;
  }
};

} // end namespace leetcode

#endif