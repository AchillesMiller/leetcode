#ifndef INCLUDED_BINARY_SEARCH_275_H_INDEX_II
#define INCLUDED_BINARY_SEARCH_275_H_INDEX_II

namespace leetcode {

/** @brief: H Index II
 *  A scientist has an index h if h
 *  of their n papers have at least h citations each,
 *  and the other n − h papers have no more than h citations each.
 *
 *  If there are several possible values for h,
 *  the maximum one is taken as the h-index.
 **/

class Solution {
public:
  int hIndex(std::vector<int>& citations) {

    // log(n) to solve this problem since it is sorted well
    // so, for citations[i], if citations[i] <= n-i
    // it is a good solution

    // we want to find the largest i that satisfy citations[i] <= n-i

    int n = citations.size();
    int l = 0;
    int r = n-1;

    while (l <= r)
    {
      // [0, 1]
      // [0]
      int k = r - (r-l)/2;

      if (citations[k] == n-k)
        return n-k;

      if (citations[k] < n-k)
        l = k + 1;
      else
        r = k - 1;
    }

    return n-l;
  }
};

} // end namespace leetcode

#endif