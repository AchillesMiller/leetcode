#ifndef INCLUDED_TREE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE
#define INCLUDED_TREE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE

#include <tree/tree_node.h>

namespace leetcode {

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    // preorder traversal:
    // 1. check if root is lowest common ancestor,
    // 2. find lca in the left subtree
    // 3. find lca in the right subtree

    if (!root)
      return nullptr;

    if (root == q || root == p)
      return root;

    if (p->val > q->val)
      std::swap(p, q);

    // p is in the left and q is in the right
    if (p->val < root->val && q->val > root->val)
      return root;

    if (p->val < root->val) // lca is in left subtree
      return lowestCommonAncestor(root->left, p, q);

    return lowestCommonAncestor(root->right, p, q);
  }
};

} // end namespace leetcode

#endif