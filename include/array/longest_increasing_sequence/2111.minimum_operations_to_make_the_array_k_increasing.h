#ifndef INCLUDED_ARRAY_LONGEST_INCREASING_SEQUENCE_2111_MOTMTAKI
#define INCLUDED_ARRAY_LONGEST_INCREASING_SEQUENCE_2111_MOTMTAKI

#include <vector>

#include <array/longest_increasing_sequence/lis.h> // lis

namespace leetcode {

class Solution
{
public:
  /**
   * @brief The minimum operations to make the array k increasing
   * @param arr std::vector<int> &
   * @param k   int
   **/
  int kIncreasing(std::vector<int>& arr, int k)
  {
    // in another word, we need check k sequence
    // the minimum operations to make the array k increasing is equal to
    // size - the maximum longest increasing subsequence for those k sequence

    assert (k != 0);

    if (arr.empty()) return 0;

    std::vector<int> seq;

    // 1 2 3, k = 2 -> len of subsequence 3/2
    // 1 2 3 4, k = 2 -> len of subsequence 4/2
    seq.reserve(arr.size()/k);

    int ops = 0; // the minimum operations to make it k increasing

    // iterate [0, k), there are at most k subsequence to check
    for (auto i = 0; i < k; ++i)
    {
      seq.clear();
      for (auto j = i; j < arr.size(); j+=k)
        seq.push_back(arr[j]);
      // calculate the length of longest increasing subsequence
      int l = lis<int>(arr);
      ops += seq.size()-l;
    }

    return ops;
  }
};

} // end namespace leetcode

#endif
