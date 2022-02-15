#ifndef INCLUDED_ARRAY_2170_MINIMUM_OPERATIONS_TO_MAKE_THE_ARRAY_ALTERNATING
#define INCLUDED_ARRAY_2170_MINIMUM_OPERATIONS_TO_MAKE_THE_ARRAY_ALTERNATING

namespace leetcode {

/** @brief: minimum operations to make the array alternating
 *  The array nums is called alternating if:
 *
 *  nums[i - 2] == nums[i], where 2 <= i <= n - 1.
 *  nums[i - 1] != nums[i], where 1 <= i <= n - 1.
 *  In one operation, you can choose an index i and
 *  change nums[i] into any positive integer.
 *
 * Return the minimum number of operations
 * required to make the array alternating.
 **/

class Solution {
public:
  int minimumOperations(vector<int>& nums) {

    // alternating:
    // numbers of even indices are the same
    // numbers of odd indices are the same

    int n = nums.size();

    std::unordered_map<int, int> even, odd;
    //                ----- ----
    //                value count
    even.reserve((n+1)/2);
    odd.reserve(n/2);

    for (auto i = 0; i < n; i += 2)
      ++ even[nums[i]];

    for (auto i = 1; i < n; i += 2)
      ++ odd[nums[i]];

    auto evens = find_k_frequent(even, 2, n); // descending order
    auto odds  = find_k_frequent(odd, 2, n);

    if (evens[0].first != odds[0].first)
      return n - evens[0].second - odds[0].second;

    if (evens[1].first == -1 && odds[1].first == -1)
      return n/2;

    if (evens[1].first == -1)      // only one value in even sequence
      return n/2 - odds[1].second; // change all odd except odds[1].first

    if (odds[1].first == -1)            // only one value in odd sequence
      return (n+1)/2 - evens[1].second; // change all even except evens[1].first

    return n - std::max(evens[0].second + odds[1].second,
                        evens[1].second + odds[0].second);
  }

private:
  using pair_t = std::pair<int, int>;

  std::vector<pair_t> find_k_frequent(std::unordered_map<int, int> &m,
                                      int k,
                                      int n)
  {
    std::vector<pair_t> ks(k, std::make_pair(-1, 0));

    std::vector<std::vector<pair_t>> buckets(n+1);

    for (auto &x: m)
      buckets[x.second].push_back(x);

    int i = 0;

    for (auto it = buckets.rbegin(); it != buckets.rend(); ++it)
    {
      for (auto &x: *it)
      {
        if (i == k)
          break;
        ks[i++] = x;
      }
    }
    return ks;
  }

};

} // end namespace leetcode


#endif