#ifndef INCLUDED_BINARY_SEARCH_410_SPLIT_ARRAY_LARGEST_SUM
#define INCLUDED_BINARY_SEARCH_410_SPLIT_ARRAY_LARGEST_SUM

#include <vector>

namespace leetcode {

class Solution {
public:
  int splitArray(std::vector<int>& nums, int m) {

    // split array to m, and make sure the sum of subarray is minimal

    int l = 0, r = 0;

    for (auto &num: nums)
    {
      l = std::max(num, l);
      r += num;
    }

    while (l <= r)
    {
      int mid = l + (r-l)/2;

      int count = split_array(nums, mid);

      if (count <= m) // mid is too large, decrease it
        r = mid-1;
      else
        l = mid+1;
    }

    // [x] since there exists solution, r is decreased, l is solution
    // [x, x] it will map to [x] finally
    // [x, x, x], it will map to [x] since mid points to 2nd

    return l;
  }

private:
  int split_array(std::vector<int> &nums, int value)
  {
    int count = 0;
    int sum = 0;

    for (auto &num: nums)
    {
      if (sum + num > value)
      {
        ++count;
        sum = num;
      }
      else
        sum += num;
    }

    return ++count;
  }
};

} // end namespace leetcode

#endif