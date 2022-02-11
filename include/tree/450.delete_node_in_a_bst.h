#ifndef INCLUDED_TREE_DELETE_NODE_IN_A_BST
#define INCLUDED_TREE_DELETE_NODE_IN_A_BST

namespace leetcode {

/** @brief: Delete Node in a BST
 *  Given a root node reference of a BST and a key,
 *  delete the node with the given key in the BST.
 *  Return the root node reference (possibly updated) of the BST.
 **/

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {

    // so, if we find the root->val == key,
    // the problem is changed to find the predecessor or successor
    // it is inorder problem now

    if (!root)
      return root;

    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else
    {
      if (!root->left && !root->right)
      {
        delete root;
        root = nullptr;
      }
      else if (root->left)
      {
        auto max_l = root->left;

        while(max_l->right)
          max_l = max_l->right;

        std::swap(root->val, max_l->val);
        root->left = deleteNode(root->left, key);
      }
      else
      {
        auto min_r = root->right;

        while(min_r->left)
          min_r = min_r->left;

        std::swap(root->val, min_r->val);
        root->right = deleteNode(root->right, key);
      }
    }

    return root;
  }
};

} // end namespace leetcode


#endif