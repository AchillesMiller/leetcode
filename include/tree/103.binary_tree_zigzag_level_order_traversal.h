#ifndef INCLUDED_TREE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL
#define INCLUDED_TREE_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL

namespace leetcode {

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    std::vector<std::vector<int>> orders;

    std::deque<TreeNode *> queue;

    if (root)
      queue.push_back(root);

    bool inorder = true;

    while (!queue.empty())
    {
      int n = queue.size();

      orders.push_back(std::vector<int>());
      orders.back().reserve(n);

      while (n-- > 0)
      {
        auto curr = queue.front();
        queue.pop_front();
        orders.back().push_back(curr->val);

        if (curr->left)  queue.push_back(curr->left);
        if (curr->right) queue.push_back(curr->right);
      }

      if (!inorder)
        std::reverse(orders.back().begin(), orders.back().end());

      inorder = !inorder;
    }

    return orders;
  }
};

} // end namespace leetcode

#endif