#ifndef INCLUDED_BINARY_SEARCH_153_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY
#define INCLUDED_BINARY_SEARCH_153_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY

namespace leetcode {

/** Suppose an array of length n sorted in ascending order is rotated
 *  between 1 and n times. For example,
 *  the array nums = [0,1,2,4,5,6,7] might become:
 *      [4,5,6,7,0,1,2] if it was rotated 4 times.
 *      [0,1,2,4,5,6,7] if it was rotated 7 times.
 **/

class Solution {
public:
  int findMin(std::vector<int>& nums)
  {
    assert (!nums.empty());

    int n = nums.size();

    int l = 0;
    int r = n-1;

    while (l < r)
    {
      int m = l + (r-l)/2;
      if (nums[m] == nums[r])
        --r;
      else if (nums[m] < nums[r])
        r = m;
      else
        l = m+1;
    }

    return nums[l];
  }
};

// find min -> find local minimum
} // end namespace leetcode

#endif
