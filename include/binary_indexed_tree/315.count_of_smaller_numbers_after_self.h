#ifndef INCLUDED_BINARY_INDEXED_TREE_351_COUNT_OF_SMALLER_NUMBERS_AFTER
#define INCLUDED_BINARY_INDEXED_TREE_351_COUNT_OF_SMALLER_NUMBERS_AFTER

namespace leetcode {

/** @brief count of smaller numbers after self
 * You are given an integer array nums and you have to return new counts array.
 * The counts array has the property
 * where counts[i] is the number of smaller elements to the right of nums[i].
 */

// a binary indexed tree can be used to hold the number information
// both query and modify is O(nlogn)

// binary indexed tree is always starts from 1, which means, you need +1 for val

struct binary_indexed_tree
{
  std::vector<int> _arr;

  binary_indexed_tree(int max)
  : _arr(max+1, 0)
  {}

  void modify(int i, int val)
  {
    assert (i > 0);
    for (auto j = i; j < _arr.size(); j += lowbit(j))
      _arr[j] += val;
  }

  int query(int i)
  {
    assert (i < _arr.size());

    int sum = 0;
    for (auto j = i; j > 0; j -= lowbit(j))
      sum += _arr[j];
    return sum;
  }

  int lowbit(int j) { return j & (-j); }
};

class Solution {
public:
  std::vector<int> countSmaller(std::vector<int>& nums)
  {
    if (nums.size() <= 1)
      return std::vector<int>(nums.size(), 0);

    auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());

    int delta = 1 - *min_it;
    int min = *min_it + delta;
    int max = *max_it + delta;

    binary_indexed_tree tree(max);

    std::vector<int> counts(nums.size(), 0);

    for (int i = nums.size()-1; i >= 0; --i)
    {
      int num = nums[i] + delta;
      counts[i] = tree.query(num - 1);
      tree.modify(num, 1);
    }

    return counts;
  }
};

} // end namespace leetcode


#endif