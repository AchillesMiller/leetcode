#ifndef INCLUDED_MONOTONIC_QUEUE_862_SHORTEST_SUBARRAY_WITH_SUM_AT_LEAST_K
#define INCLUDED_MONOTONIC_QUEUE_862_SHORTEST_SUBARRAY_WITH_SUM_AT_LEAST_K

namespace leetcode {

/** @brief: shortest subarray with sum at least k
  * Given an integer array nums and an integer k,
  * return the length of the shortest non-empty subarray of nums with a sum
  * of at least k. If there is no such subarray, return -1.
  **/

class Solution {
public:
  int shortestSubarray(std::vector<int>& nums, int k)
  {
    // shortest subarray can be 1, 2, 3

    // [1, 2, 3, 3] k = 5
    // [1, 3, 9, 12]
    // supposed the left pointer pointing to x0,
    // and right pointer pointing to x1
    // if x1 - x0 >= k,
    // 1. any value on the right is not necessary to be compared with x0
    // 2. and, any value on the left of x0

    // else if x1 - x0 < k
    // the next value shouldn't compare with any value that is larger than x1
    // on the left

    // so, we don't want to keep any value on the left that is larger than x1
    // the queue maintained should be in ascending order

    int n = nums.size();

    std::vector<long> pre_sums(n+1, 0);

    for (auto i = 1; i != pre_sums.size(); ++i)
      pre_sums[i] = pre_sums[i-1] + nums[i-1];

    std::deque<int> q; // keep the index

    int min_len = INT_MAX;

    for (auto i = 0; i != pre_sums.size(); ++i)
    {
      while (!q.empty() && pre_sums[q.back()] >= pre_sums[i])
        q.pop_back();

      // find the last value that can satisfy k
      while (!q.empty() && pre_sums[i] - pre_sums[q.front()] >= k)
      {
        min_len = std::min(min_len, i-q.front());
        q.pop_front();
      }

      q.push_back(i);
    }

    return (min_len == INT_MAX)? -1: min_len;
  }
};

} // end namespace leetcode

#endif