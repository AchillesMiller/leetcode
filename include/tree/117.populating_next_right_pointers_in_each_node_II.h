#ifndef INCLUDED_TREE_117_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II
#define INCLUDED_TREE_117_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II

namespace leetcode {

/** Populate each next pointer to point to its next right node.
 *  If there is no next right node, the next pointer should be set to NULL.
 **/

class Solution {
public:
  Node* connect(Node* root) {

    if (!root)
      return root;

    auto it = root;
    Node * head = nullptr;
    Node * prev = nullptr;

    while (it)
    {
      if (!head)
        head = it->left? it->left: it->right;

      if (it->left && prev)
        prev->next = it->left;

      prev = it->left? it->left: prev;

      if (it->right && prev)
        prev->next = it->right;

      prev = it->right? it->right: prev;

      it = it->next;

      if (!it)
      {
        it = head;
        head = nullptr;
        prev = nullptr;
      }
    }

    return root;
  }
};

} // end namespace leetcode

#endif