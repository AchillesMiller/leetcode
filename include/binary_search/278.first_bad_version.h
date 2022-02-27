#ifndef INCLUDED_BINARY_SEARCH__278_FIRST_BAD_VERSION
#define INCLUDED_BINARY_SEARCH__278_FIRST_BAD_VERSION

namespace leetcode {

/** @brief Find first bad version
 */

class Solution {
public:
  int firstBadVersion(int n) {

    int l = 1, r = n;

    while (l <= r)
    {
      int m = l + (r-l)/2;

      if (isBadVersion(m))
        r = m-1;
      else
        l = m+1;
    }

    // if version exists, it must be l
    // else, l == n+1

    // in this scenario, bad version exists

    assert (l <= n);

    return l;
  }
};

} // end namespace leetcode

#endif