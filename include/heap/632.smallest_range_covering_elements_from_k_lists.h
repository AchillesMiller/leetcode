#ifndef INCLUDED_HEAP_632_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS
#define INCLUDED_HEAP_632_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS

#include <vector>
#include <set>

namespace leetcode {

class Solution {
public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {

    // if we find one smallest range [a, b] covering all arrays,
    // it is obvious that both a and b appears in those arrays

    // any sorted data structure can be used in this case

    using node_t = std::vector<int>; // value, group_id, index_id

    std::set<node_t> queue;

    for (auto i = 0; i != nums.size(); ++i)
      queue.insert({nums[i][0], i, 0});

    int min_range = INT_MAX;
    std::vector<int> range{-1, -1};

    while (queue.size() == nums.size())
    {
      auto &l = *queue.begin();
      auto &r = *queue.rbegin();

      if (min_range > r[0]-l[0])
      {
        min_range = r[0]-l[0];
        range[0] = l[0];
        range[1] = r[0];
      }

      int group_id = l[1];
      int index = l[2];

      queue.erase(queue.begin());

      if (++index < nums[group_id].size())
        queue.insert({nums[group_id][index], group_id, index});
    }

    return range;
  }
};

} // end naemspace leetcode

#endif