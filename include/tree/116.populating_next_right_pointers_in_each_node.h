#ifndef INCLUDED_TREE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE
#define INCLUDED_TREE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE

namespace leetcode {

/** @brief: populating next right pointers in each node
 *  You are given a perfect binary tree where all leaves are on the same level,
 *  and every parent has two children.
 *  Populate each next pointer to point to its next right node.
 *  If there is no next right node, the next pointer should be set to NULL.
 **/

class Solution {
public:
  Node* connect(Node* root) {

    if (!root)
      return root;

    auto it = root;
    auto head = it->left;

    while (it)
    {
      if (it->left)
        it->left->next = it->right;

      if (it->right && it->next)
        it->right->next = it->next->left;

      if (it->next)
        it = it->next;
      else
      {
        it = head;
        if (head) head = head->left;
      }
    }

    return root;
  }
};

} // end namespace leetcode

#endif