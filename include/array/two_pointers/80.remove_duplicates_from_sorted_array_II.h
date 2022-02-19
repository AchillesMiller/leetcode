#ifndef INCLUDED_ARRAY_TWO_POINTERS_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY
#define INCLUDED_ARRAY_TWO_POINTERS_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY

namespace leetcode {

/** @brief: remove duplicates from sorted array
 *  Given an integer array nums sorted in non-decreasing order,
 *  remove some duplicates in-place such that each unique element appears
 *  at most twice. The relative order of the elements should be kept the same.
 **/

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {

    std::pair<int, int> it(0, 1);
    //        ---  ----
    //       value count

    int allowed = 2;

    for (auto i = 1; i != nums.size(); ++i)
    {
      auto &num = nums[i];

      if (num == nums[it.first] && ++it.second > allowed)
        continue;

      if (num != nums[it.first])
        it.second = 1;

      ++it.first; // this is the index to dump data to

      std::swap(num, nums[it.first]);
    }

    return it.first + 1;
  }
};

} // end namespace leetcode

#endif