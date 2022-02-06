#ifndef INCLUDED_TREE_124_BINARY_TREE_MAXIMUM_PATH_SUM
#define INCLUDED_TREE_124_BINARY_TREE_MAXIMUM_PATH_SUM

namespace leetcode {

/** @brief: binary tree maximum path sum
 *  A path in a binary tree is a sequence of nodes
 *  where each pair of adjacent nodes in the sequence
 *  has an edge connecting them.
 *  A node can only appear in the sequence at most once.
 *  Note that the path does not need to pass through the root.
 *
 *  The path sum of a path is the sum of the node's values in the path.
 *
 *  Given the root of a binary tree,
 *  return the maximum path sum of any non-empty path.
 **/

class Solution {
public:
  int maxPathSum(TreeNode* root) {

    // there are several scenarios:
    // 1. pass root
    // 2. not pass root

    return max_path_sum(root).first;
  }

private:
  std::pair<int, int> max_path_sum(TreeNode *root)
  //        ---  ------
  //        sum  max routine
  {
    if (!root)
      return std::make_pair(INT_MIN, 0);

    auto l = max_path_sum(root->left);
    auto r = max_path_sum(root->right);

    int max_routine = std::max(l.second, r.second) + root->val;
    max_routine = std::max(root->val, max_routine);

    int max_sum = std::max(l.first, r.first);   // left's or right's
    max_sum = std::max(max_sum, max_routine);   // the max_routine
    max_sum = std::max(max_sum, l.second + root->val + r.second); // sum

    return std::make_pair(max_sum, max_routine);
  }
};

// @note: the path with maximum sum can pass root, cannot pass root
//        can starts at anywhere and ended at anywhere

} // end namespace leetcode

#endif