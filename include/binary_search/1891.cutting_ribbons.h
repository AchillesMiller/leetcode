#ifndef INCLUDED_BINARY_SEARCH_1891_CUTTING_RIBBONS
#define INCLUDED_BINARY_SEARCH_1891_CUTTING_RIBBONS

#include <vector>

namespace leetcode {

class Solution {

public:
  int maxLength(std::vector<int> & ribbons, int k)
  {
    int max_ribbon = 0;

    for (auto &ribbon: ribbons)
      max_ribbon = std::max(ribbon, max_ribbon);

    int l = 1, r = max_ribbon;

    while (l <= r)
    {
      auto m = l + (r-l)/2;

      int count = 0;

      for (auto &ribbon: ribbons)
        count += ribbon/m;

      if (count < k) // m is too large
        r = m-1;
      else // m is small enough, want to try a larger one
        l = m+1;
    }

    assert(l == r+1);
    // a. when processing last operation, r-l+1 is equal to 2
    // b. if last operation is l = m+1, it means, l-1 is the last point that
    //    satisfies the k requirement
    // c. if last operation is r = m-1, it means, it is never able to find
    //    a good len to cut, in another word, it keeps decreasing r, until
    //    l > r, so, l == 1 for this case,
    //    should return l-1 = 0

    return l-1;
  }

};

} // end namespace leetcode

#endif
