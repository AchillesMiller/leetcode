#ifndef INCLUDED_TWO_POINTERS_632_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS
#define INCLUDED_TWO_POINTERS_632_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS

#include <vector>

namespace leetcode {

class Solution {
public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums)
  {
    //
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