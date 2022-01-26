#ifndef INCLUDED_ARRAY_769_MAX_CHUNKS_TO_MAKE_SORTED
#define INCLUDED_ARRAY_769_MAX_CHUNKS_TO_MAKE_SORTED

namespace leetcode {

/** @brief: max chunks to make sorted
 * You are given an integer array arr of length n that represents a permutation
 * of the integers in the range [0, n - 1].
 *
 * We split arr into some number of chunks (i.e., partitions),
 * and individually sort each chunk. After concatenating them,
 * the result should equal the sorted array.

 * Return the largest number of chunks we can make to sort the array.
 */

class Solution {
public:
  int maxChunksToSorted(std::vector<int>& arr) {
    // [3, 2, 0, 1, 5, 4]
    // there exists two partitions:
    // [3, 2, 0, 1] and [4], which can concatenate to [0, 1, 2, 3, 4]

    // when iterate to 1, max = 3, which is equal to index i
    // in another word, there are i+1 elements, and max is 3
    // so, previous one can be sorted as one partition

    int max = -1;
    int count = 0;

    for (auto i = 0; i != arr.size(); ++i)
    {
      max = std::max(arr[i], max);
      if (max == i)
        ++count;
    }

    return count;
  }
};

} // end namespace leetcode

#endif