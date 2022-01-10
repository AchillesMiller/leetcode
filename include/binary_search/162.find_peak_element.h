#ifndef INCLUDED_BINARY_SEARCH_162_FIND_PEAK_ELEMENT
#define INCLUDED_BINARY_SEARCH_162_FIND_PEAK_ELEMENT

#include <vector>

namespace leetcode {

class Solution {
public:
  int findPeakElement(std::vector<int>& nums) {

    // find peak element
    // 1. brute force algorithm, is iterate all element and get index
    // 2. O(nlogn), binary search algorithm

    //  1 10 2 11 3
    //    *     *

    // basic rule is, if median+1 is larger than median,
    //                peak should appear between [median+1, right]
    //                else
    //                peak should appear between [left, median]
    // since median is calculated leaping toward left, median shouldn't -1

    // check median element
    // if right is larger than median, go to right,
    // else, go to left

    int l = 0, r = nums.size()-1;

    // length = 2, l = 0, r = 1, median = 0, median+1 = 1
    // length = 3, l = 0, r = 2, median = 1, median+1 = 2

    // since we compare median and right(median+1), (0+1)/2 = 0
    // so, median = l+ (r-l)/2, leaping toward left
    // if we want to compare the left(median-1) and median,
    // so median = r - (r-l)/2, leaping toward right

    while (l < r)
    {
      int median = l + (r-l)/2;

      if (nums[median+1] > nums[median])
        l = median+1;
      else
        r = median;
    }

    assert(r == l);

    return r;
  }
};

} // end namespace leetcode

#endif
