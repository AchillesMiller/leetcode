#ifndef INCLUDED_BINARY_SEARCH_69_SQRT_X
#define INCLUDED_BINARY_SEARCH_69_SQRT_X

namespace leetcode {

class Solution {
public:
  int mySqrt(int x) {

    int l = 1;
    int r = x;

    while(l <= r)
    {
      int m = l + (r-l)/2;

      if (m <= x/m)
        l = m+1;
      else
        r = m-1;
    }

    // sqrt must exist, so, l * l must be > x
    // and r is one less than r, it is the solution
    return r;
  }
};


} // end namespace leetcode

#endif