#ifndef INCLUDED_TREE_TRAVERSALS_POST_ORDER_366_FIND_LEAVES_OF_BINARY_TREE
#define INCLUDED_TREE_TRAVERSALS_POST_ORDER_366_FIND_LEAVES_OF_BINARY_TREE

#include <vector>
#include <tree/tree_node.h>

namespace leetcode {

class Solution {
public:
  std::vector<std::vector<int>> findLeaves(TreeNode* root) {
    // the height of leaf is 0
    // and without those leaves, node with height == 1 becomes leaf

    // this question has a assumption that size of nodes is less than or equal
    // to 200

    std::vector<std::vector<int>> heights;
    heights.reserve(201);

    height(root, heights);

    return heights;
  }

  int height(TreeNode *node, std::vector<std::vector<int>> &heights)
  {
    if (!node) return -1;

    int l = height(node->left, heights);
    int r = height(node->right, heights);

    int h = std::max(l, r) + 1;

    if (h == heights.size())
      heights.push_back(std::vector<int>());

    assert (h < heights.size());
    heights[h].push_back(node->val);

    return h;
  }

};

} // end namespace leetcode


#endif