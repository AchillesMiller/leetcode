#ifndef INCLUDED_ARRAY_TWO_POINTERS_768_MAX_CHUNKS_TO_MAKE_SORTED
#define INCLUDED_ARRAY_TWO_POINTERS_768_MAX_CHUNKS_TO_MAKE_SORTED

namespace leetcode {

/** @brief: max chunks to make sorted
 * You are given an integer array arr.
 * We split arr into some number of chunks (i.e., partitions),
 * and individually sort each chunk. After concatenating them,
 * the result should equal the sorted array.
 * Return the largest number of chunks we can make to sort the array.
 */

class Solution {
public:
  int maxChunksToSorted(std::vector<int>& arr) {
    // when a chunk can be split?
    //  for one arr[i], if max in [0, i] is less than/equal to the min (i, end)

    // why?
    //  it means, the maximum in [0, i] is at least equal to minimum on the right
    //  when sorted the left part, it always good to concatenate

    // 2, 3, 1, 4, 9
    // 1, 2, 3, 4, 9

    std::vector<int> rmins(arr.size(), INT_MAX);

    for (int i = arr.size()-2; i >= 0; --i)
      rmins[i] = std::min(rmins[i+1], arr[i+1]);

    int lmax = INT_MIN;
    int count = 0;

    for (auto i = 0; i != arr.size(); ++i)
    {
      lmax = std::max(lmax, arr[i]);

      if (lmax <= rmins[i])
        ++count;
    }

    return count;
  }
};

} // end namespace leetcode

#endif