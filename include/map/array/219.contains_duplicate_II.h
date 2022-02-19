#ifndef INCLUDED_MAP_ARRAY_219_CONTAINS_DUPLICATE_II
#define INCLUDED_MAP_ARRAY_219_CONTAINS_DUPLICATE_II

namespace leetcode {

/** @brief: contains dumplicate II
 *  Given an integer array nums and an integer k,
 *  return true if there are two distinct indices i and j in the array
 *  such that nums[i] == nums[j] and abs(i - j) <= k.
 **/

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k)
  {
    std::unordered_map<int, int> counts;
    counts.reserve(nums.size());

    for (auto i = 0; i != nums.size(); ++i)
    {
      if (i - k - 1 >= 0)
        counts[nums[i-k-1]] --;

      auto it = counts.insert(std::make_pair(nums[i], 0));

      if (++it.first->second >= 2)
        return true;
    }

    return false;
  }
};

} // end namespace leetcode

#endif