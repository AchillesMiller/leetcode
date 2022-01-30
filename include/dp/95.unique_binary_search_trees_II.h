#ifndef INCLUDED_DP_95_UNIQUE_BINARY_SEARCH_TREES_II
#define INCLUDED_DP_95_UNIQUE_BINARY_SEARCH_TREES_II

namespace leetcode {

/** @brief: unique binary search trees II
 * Given an integer n,
 * return all the structurally unique BST's (binary search trees),
 * which has exactly n nodes of unique values from 1 to n.
 * Return the answer in any order.
 **/

class Solution {
public:
  std::vector<TreeNode*> generateTrees(int n)
  {
    std::vector<std::vector<nodes_t>> dp(n+1, std::vector<nodes_t>(n+1));

    return generate_trees(dp, 1, n);
  }

private:
  using nodes_t = std::vector<TreeNode *>;

  // [l, r]
  nodes_t & generate_trees(std::vector<std::vector<nodes_t>> &dp, int l, int r)
  {
    static nodes_t empties{nullptr};

    if (l > r) return empties;

    if (!dp[l][r].empty())
      return dp[l][r];

    for (auto i = l; i <= r; ++i)
    {
      auto &ltrees = generate_trees(dp, l, i-1);
      auto &rtrees = generate_trees(dp, i+1, r);

      for (auto &left: ltrees)
        for (auto &right: rtrees)
          dp[l][r].push_back(new TreeNode(i, left, right));
    }

    return dp[l][r];
  }

};

} // end namespace leetcode

#endif