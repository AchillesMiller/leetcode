#ifndef INCLUDED_ARRAY_BUCKET_SORT_274_H_INDEX
#define INCLUDED_ARRAY_BUCKET_SORT_274_H_INDEX

namespace leetcode {

/** @brief H INDEX
 *  A scientist has an index h if h of their n papers have
 *  at least h citations each, and the other n − h papers
 *  have no more than h citations each.
 *
 * If there are several possible values for h,
 * the maximum one is taken as the h-index.
 **/

class Solution {
public:
  int hIndex(std::vector<int>& citations) {
    // hindex = there are h papers has at lest h citations

    int n = citations.size();
    std::vector<int> buckets(n+1, 0);

    for (auto &c: citations)
    {
      if (c > n) buckets[n] ++;
      else       buckets[c] ++;
    }

    if (buckets[n] >= n)
      return n;

    for (int i = n-1; i >= 0; --i)
    {
      buckets[i] += buckets[i+1];
      if (buckets[i] >= i)
        return i;
    }

    return 0;
  }
};

} // end namespace leetcode

#endif