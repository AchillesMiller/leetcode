#ifndef INCLUDED_ARRAY_31_NEXT_PERMUTATION
#define INCLUDED_ARRAY_31_NEXT_PERMUTATION

#include <vector>
#include <algorithm>

namespace leetcode {

class Solution {
public:
  void nextPermutation(std::vector<int>& nums) {
    // 123 -> 132 -> 213 -> 231 -> 123

    // from right to left, if it is ascending order, it is largest already,
    // e.g, 132,
    // 32 is largest already
    // 1 is the first pos that does not satisfy the ascending order
    // replace 1 with 2 and resort the 32 to 1 and 3,
    // result is 213

    // binary search is used to find the value we want to swap

    int i = nums.size()-2;

    while (i >= 0 && nums[i] >= nums[i+1])
      --i;

    // [i+1, nums.size()) turned into an ascending order
    std::reverse(nums.begin()+i+1, nums.end());

    if (i < 0)
      return;

    // for range [i+1, nums.size()), find first number(j) greater than nums[i]
    // swap the nums[i] and that number[j]
    //   since nums[i-1] <= nums[i] < nums[j] < nums[j+1]

    auto it = std::upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
    assert(it != nums.end());
    std::swap(*it, nums[i]);
    return;
  }
};

} // end namespace leetcode


#endif
