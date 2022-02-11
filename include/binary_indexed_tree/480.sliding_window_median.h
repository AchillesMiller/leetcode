#ifndef INCLUDED_BINARY_INDEXED_TREE_480_SLIDING_WINDOW_MEDIAN
#define INCLUDED_BINARY_INDEXED_TREE_480_SLIDING_WINDOW_MEDIAN

namespace leetcode {

/** @brief: Sliding Window Median
 *  The median is the middle value in an ordered integer list.
 *  If the size of the list is even, there is no middle value.
 *  So the median is the mean of the two middle values.
 **/

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {

    std::multiset<int> lows;     // 0 1
    std::multiset<int> highs;    // 2 3

    // for window [1, 2, 3]
    // lows: [1, 2]
    // highs: [3]

    // for window [1, 2]
    // lows: [1]
    // highs [2]

    for (auto i = 0; i != nums.size(); ++i)
    {
      // if current is smaller than lows.rbegin(), insert into lows
      // otherwise                                 insert into highs

      if ()

      // erase the nums[i-k]
      // if i-k is smaller than lows.rbegin(), erase happens in lows
      // otherwise                             erase happens in highs

      // balance lows and highs

      // calculate median
    }


  }
};

} // end namespace leetcode

#endif