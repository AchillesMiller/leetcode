#ifndef INCLUDED_ARRAY_TWO_POINTERS_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY
#define INCLUDED_ARRAY_TWO_POINTERS_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY

namespace leetcode {

/** @brief: Remove duplicates from sorted array
 *  Given an integer array nums sorted in non-descending order,
 *  remove duplicates in-place
 **/

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {

    int it = 0; // indicates where it for now

    for (auto i = 1; i != nums.size(); ++i)
      if (nums[i] != nums[it])
        std::swap(nums[i],nums[++it]);

    return 1+it;
  }
};

} // end namespace leetcode

#endif