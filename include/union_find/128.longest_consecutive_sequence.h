#ifndef INCLUDED_UNION_FIND_128_LONGEST_CONSECUTIVE_SEQUENCE
#define INCLUDED_UNION_FIND_128_LONGEST_CONSECUTIVE_SEQUENCE

#include <vector>
#include <unordered_map>

namespace leetcode {

// DFS and union_find solution

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    // 100, 3, 200, 2, 1, 4
    // for this case, the longest consecutive length is 4

    return longest_consecutive_dfs(nums);
  }

private:
  int longest_consecutive_dfs(std::vector<int> &nums)
  {
    // dfs solution

    // for each num, if num-1 does not exist, we know num is start of one chain
    // therefore, dfs can go with num++, until num does not exist again

    // in this way, we can get length of each chain

    std::unordered_map<int, bool> visited;

    for (auto &x: nums)
      visited[x] = false;

    int max_length = 0;

    for (auto &x: nums)
    {
      auto it = visited.find(x);
      if (it->second) // x is visited before
        continue;

      if (visited.find(x-1) == visited.end())
      {
        int length = 0;
        // there exists one chain starts with x

        while (it != visited.end())
        {
          length ++;
          it->second = true;

          it = visited.find(++x);
        }

        max_length = std::max(length, max_length);
      }
    }
    return max_length;
  }

  //////////////////////////////////////////////////////////////////////////////
  int longest_consecutive_union_find(std::vector<int> &nums)
  {
    // since there is O(N) time complexity constraint
    // first thing came into my mind is union find,
    // the amortized time complexity of one operation is O(1)

    union_find U(nums);

    for (auto &num: nums)
    {
      U.do_union(num, num-1);
      U.do_union(num, num+1);
    }

    int max_length = 0;

    for (auto &x: U.parents)
    {
      auto p = U.parent(x.first);
      // 1 -> 3: parent is always larger than x.first
      max_length = std::max(max_length, p-x.first+1);
    }

    return max_length;
  }

  struct union_find
  {
    std::unordered_map<int, int> parents;

    union_find(std::vector<int> &nums)
    : parents()
    {
      for (auto &num: nums)
        parents[num] = num;
    }

    int parent(int x)
    {
      auto it = parents.find(x);

      if (it == parents.end())
        return INT_MAX;

      if (it->second == x)
        return x;

      it->second = parent(it->second);
      return it->second;
    }

    bool do_union(int x, int y)
    {
      auto px = parent(x);
      auto py = parent(y);

      if (px == INT_MAX || py == INT_MAX || px == py)
        return false;

      if (px > py)
        std::swap(px, py);

      parents[px] = py;

      return true;
    }

  };

};

} // end namespace leetcode

#endif