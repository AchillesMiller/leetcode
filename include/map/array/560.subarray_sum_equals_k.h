#ifndef INCLUDED_MAP_ARRAY_560_SUBARRAY_SUM_EQUALS_K
#define INCLUDED_MAP_ARRAY_560_SUBARRAY_SUM_EQUALS_K

#include <vector>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
  int subarraySum(std::vector<int>& nums, int k) {
    // get all (i, j] fo which the sum is equal to k
    // in another word, presums[j]-presums[i] == k

    // we can use a unordered_map<int,      int> to store in one pass
    //                            ---       ---
    //                          presums[i] count
    // ================================================================
    // curr-prev = k, prev = curr-k
    // time performance, is O(N)

    std::vector<int> presums(nums.size(), 0);
    presums[0] = nums[0];

    for (auto i = 1; i != nums.size(); ++i)
      presums[i] = presums[i-1] + nums[i];

    std::unordered_map<int, int> m;
    m.insert({0, 1});

    int count = 0;

    for (auto &x: presums)
    {
      // x-prev == k, we want to find x-k
      // find k-x previously, if exists, count += m[x-k]
      auto found = m.find(x-k);
      if (found != m.end())
        count += found->second;

      // insert current x, if exists, increment
      auto it = m.insert({x, 0});
      it.first->second++;
    }

    return count;
  }
};

} // end namespace leetcode

#endif
