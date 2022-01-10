#ifndef INCLUDED_TREE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_II
#define INCLUDED_TREE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_II

#include <tree/tree_node.h>

namespace leetcode {

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    // find lowest common ancestor of a binary tree
    // p, and q is not necessary to have the same root
    // so, lca is not guaranteed to be existed

    // an auxiliary function lca, returning a std::pair<TreeNode *, int>
    //                                                  ----------  ---
    //                                                    lca       count

    auto l = lca(root, p, q);

    if (l.second == 2)
      return l.first;

    return nullptr;
  }

private:
  std::pair<TreeNode *, int> lca(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    // post order traversal
    // check left, right and checking root at last

    if (!root) return std::make_pair(nullptr, 0);

    auto l = lca(root->left, p, q);
    auto r = lca(root->right, p, q);

    if (root == p || root == q)
      return std::make_pair(root, l.second+r.second+1);

    if (l.first && r.first)
      return std::make_pair(root, l.second+r.second);

    return l.first? l: q;
  }
};

} // end namespace leetcode

#endif