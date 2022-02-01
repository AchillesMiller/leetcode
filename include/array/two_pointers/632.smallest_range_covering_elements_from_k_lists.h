#ifndef INCLUDED_TWO_POINTERS_632_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS
#define INCLUDED_TWO_POINTERS_632_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS

#include <vector>

namespace leetcode {

/** @brief: smallest range covering elements from k lists
 *  You have k lists of sorted integers in non-decreasing order.
 *  Find the smallest range that includes
 *  at least one number from each of the k lists.
 **/

class Solution {
public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums)
  {
    // greedy algorithm, the start and end of a minimum range should belongs to
    // two different vector
    // each time, we check the l and r of the range, we want to erase the l
    // and pop l's next to the double-linked queue to re-calculate the min range

    using node_t = std::vector<int>;//  int    int,   int;
    //                                 ---    ----    -----
    //                                 value groupid, index

    std::set<node_t> Q;

    for (auto i = 0; i != nums.size(); ++i)
      Q.insert(node_t{nums[i][0], i, 0});

    std::vector<int> range{-1, -1};
    int min_range = INT_MAX;

    while (Q.size() == nums.size())
    {
      auto &l = *Q.begin();
      auto &r = *Q.rbegin();

      if (min_range > r[0] - l[0])
      {
        range[0] = l[0];
        range[1] = r[0];
        min_range = r[0] - l[0];
      }

      int group_id = l[1];
      int index = l[2];
      Q.erase(Q.begin());

      if (++index < nums[group_id].size())
        Q.insert(node_t{nums[group_id][index], group_id, index});
    }
    return range;
  }
};

// 4 10 15
// 0 8 12
// 5 18 22

// [0, 4, 5] -> [4, 5, 8] -> [5, 8, 10]

// keep deleting the minimum value and append the next of minimum in that array
// by this way, we can find the minimum range

// SIMILAR TO merge k sorted array

} // end namespace leetcode

#endif