#ifndef INCLUDED_ARRAY_LONGEST_INCREASING_SEQUENCE_300_LIS
#define INCLUDED_ARRAY_LONGEST_INCREASING_SEQUENCE_300_LIS

#include <vector>
#include <array/longest_increasing_sequence/lis.h>

namespace leetcode {

class Solution {
public:
  int lengthOfLIS(std::vector<int>& nums) {
    return lis<int>(nums);
  }

};

}// end namespace leetcode

#endif
