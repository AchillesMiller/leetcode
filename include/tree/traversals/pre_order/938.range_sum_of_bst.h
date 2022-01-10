#ifndef INCLUDED_TREE_TRAVERSAL_PRE_ORDER_938_RANGE_SUM_OF_BST
#define INCLUDED_TREE_TRAVERSAL_PRE_ORDER_938_RANGE_SUM_OF_BST

#include <tree/tree_node.h>

namespace leetcode {

class Solution {
public:
  int rangeSumBST(TreeNode* root, int low, int high)
  {
    if (!root) return 0;

    // sum up all value between [low, high]

    // sum = root->val +
    //       rangeSumBST(root->left)  if root->val >= low
    //       rangeSumBST(root->right) if root->val <= high

    int sum = 0;

    auto &val = root->val;

    if (val >= low && val <= high)
      sum += val;

    if (val >= low)
      sum += rangeSumBST(root->left, low, std::min(high, val));

    if (val <= high)
      sum += rangeSumBST(root->right, std::max(low, val), high);

    return sum;
  }
};

} // end namespace leetcode

#endif