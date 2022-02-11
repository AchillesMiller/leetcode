#ifndef INCLUDED_MONOTONIC_QUEUE_239_SLIDING_WINDOW_MAXIMUM
#define INCLUDED_MONOTONIC_QUEUE_239_SLIDING_WINDOW_MAXIMUM

namespace leetcode {

/** @brief: sliding window maximum
 *  You are given an array of integers nums,
 *  there is a sliding window of size k which is moving
 *  from the very left of the array to the very right.
 *  You can only see the k numbers in the window.
 *  Each time the sliding window moves right by one position.
 *
 *  Return the max sliding window.
 **/

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 2 10 1
    // 2 is not necessary to keep in queue when we saw 10
    // so, the queue we maintain should be a non-ascending double linked queue

    std::deque<int> q;

    std::vector<int> maximums;
    maximums.reserve(nums.size()-(k-1));

    for (auto i = 0; i != k; ++i)
    {
      while(!q.empty() && nums[q.back()] < nums[i])
        q.pop_back();
      q.push_back(i);
    }

    maximums.push_back(nums[q.front()]);

    for (auto i = k; i != nums.size(); ++i)
    {
      if (i-k == q.front())
        q.pop_front();

      while(!q.empty() && nums[q.back()] < nums[i])
        q.pop_back();
      q.push_back(i);

      maximums.push_back(nums[q.front()]);
    }

    return maximums;
  }
};

} // end namespace leetcode

#endif