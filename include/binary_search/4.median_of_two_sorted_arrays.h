#ifndef INCLUDED_BINARY_SEARCH_4_MEDIAN_TWO_SORTED_ARRAYS
#define INCLUDED_BINARY_SEARCH_4_MEDIAN_TWO_SORTED_ARRAYS

namespace leetcode {

/** @brief: median of two sorted arrays
 *  Given two sorted arrays nums1 and nums2 of size m and n respectively,
 *  return the median of the two sorted arrays.
 *
 *  The overall run time complexity should be O(log (m+n)).
 **/

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2)
  {
    // O(log(m+n)) to solve the problem, so it must be binary search

    if (nums1.size() > nums2.size())
      std::swap(nums1, nums2);

    int m = nums1.size();
    int n = nums2.size();

    // the problem to find median of sorted array can be interpreted to be
    // find the k-th smallest value

    // if m+n is even, k = (m+n)/2 -1;
    // if m+n is odd , k = (m+n)/2
    // so, the general k = (m+n-1)/2

    int k = (m+n-1)/2;

    // [1]        l = 0, r = 0 -> l = 1, r = 0, k-l = 0
    // [2, 3]

    // [4]        l = 0, r = 0 -> l = 0, r = -1, k-l = 1
    // [2, 3]

    // [1]        l = 0, r = 0 -> l = 1, r = 0, k-l = -1
    // [2]

    int l = 0, r = m-1;

    while (l <= r)
    {
      int mid = l + (r-l)/2;

      if (nums1[mid] >= nums2[k-mid])
        r = mid-1;
      else
        l = mid+1;
    }

    int i = r;
    int j = k-l;

    double median = std::max((i >= 0)? nums1[i]: INT_MIN,
                             (j >= 0)? nums2[j]: INT_MIN);

    if ((m+n) % 2 == 1)
      return median;

    ++i;
    ++j;

    median += std::min((i < nums1.size())? nums1[i]: INT_MAX,
                       (j < nums2.size())? nums2[j]: INT_MAX);

    return median/2.0;
  }
};

} // end namespace leetcode

#endif
