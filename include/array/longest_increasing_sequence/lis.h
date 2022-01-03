#ifndef INCLUDED_ARRAY_LONGEST_INCREASING_SEQUENCE_LIS
#define INCLUDED_ARRAY_LONGEST_INCREASING_SEQUENCE_LIS

#include <vector>
#include <algorithm>

namespace leetcode {

/**
 * return the length of longest increasing subsequence
 * @param std::vector<T>
 */

template <typename T>
inline int lis(const std::vector<T> &arr)
{
  // the implementation based on the observation that
  // if value is greater or equal to the back of current longest
  //   increasing subsequence, we can safely push this value to the end
  // else
  //   we can replace this value in the upper bound

  // 1 2 10 12 3 2 4
  // a) 1 2 10 12
  // b) 1 2 3 12
  // c) 1 2 2 12
  // d) 1 2 2 4

  // this can be rewritten by binary indexed tree also

  if (arr.empty())
    return 0;

  std::vector<T> L;
  L.reserve(arr.size());
  L.push_back(arr[0]);

  for (auto i = 1; i < arr.size(); ++i)
  {
    if (arr[i] >= L.back())
      L.push_back(arr[i]);
    else
    {
      // the first element that is greater than arr[i]
      auto it = std::upper_bound(L.begin(), L.end(), arr[i]);
      assert (it != L.end());
      *it = arr[i];
    }
  }

  return L.size();
}

} // end namespace leetcode

#endif