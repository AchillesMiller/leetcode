#ifndef INCLUDED_TREE_TRAVERSALS_POST_ORDER_426
#define INCLUDED_TREE_TRAVERSALS_POST_ORDER_426

#include <vector>
#include <tree/tree_node.h>

namespace leetcode {

class Solution {

private:
  std::pair<Node *, Node *> tree_to_doubly_list(Node *root)
  {
    // 1) processing left subtree to get its left/right most node
    // 2) processing right subtree to get its left/right most node
    // 3) right most of left subtree <-> root
    //    left most of right subtree <-> root
    // 4) return the left and right most for root

    if (!root) return {nullptr, nullptr};

    auto l = tree_to_doubly_list(root->left);
    auto r = tree_to_doubly_list(root->right);

    Node *leftmost = l.first? l.first: root;
    Node *rightmost = r.second? r.second: root;

    root->left = l.second;
    if (l.second) l.second->right = root;

    root->right = r.first;
    if (r.first) r.first->left = root;

    return {leftmost, rightmost};
  }

public:
  /**
   * @brief Convert Binary Search Tree to Sorted Doubly Linked List
   **/
  Node* treeToDoublyList(Node* root)
  {
    // recursive algorithm is the first thing to come into mind.
    // and, rightmost of left tree <-> root <-> leftmost of right tree

    // obviously, the recursive method should return a pair of Node
    // and node are processed in post order traversal

    auto lr = tree_to_doubly_list(root);

    if (!lr.first) return lr.first;

    // link l.first and l.second

    lr.first->left = lr.second;
    lr.second->right = lr.first;

    return lr.first;
  }

};

} // end namespace leetcode


#endif