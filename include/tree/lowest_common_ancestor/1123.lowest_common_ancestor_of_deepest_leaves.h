#ifndef INCLUDED_TREE_LOWEST_COMMON_ANCESTOR_OF_DEEPEST_LEAVES
#define INCLUDED_TREE_LOWEST_COMMON_ANCESTOR_OF_DEEPEST_LEAVES

#include <tree/tree_node.h>

namespace leetcode {

class Solution {
public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    // it is post order traversal, each lca will root and its height

    return lca(root).first;
  }

private:
  std::pair<TreeNode *, int> lca(TreeNode *x)
  {
    if (!x) return std::make_pair(x, 0);

    auto l = lca(x->left);
    auto r = lca(x->right);

    // both left and right have the same depth,
    // root is lca of deepest leaves for this subtree

    if (l.second == r.second)
      return std::make_pair(x, l.second+1);

    // if depth of left subtree is larger, increment and return l
    if (l.second > r.second)
    {
      l.second++;
      return l;
    }

    r.second++;
    return r;
  }
};

} // end namespace leetcode

#endif
