#ifndef INCLUDED_TREE_IN_ORDER_1382_BALANCE_A_BINARY_SEARCH_TREE
#define INCLUDED_TREE_IN_ORDER_1382_BALANCE_A_BINARY_SEARCH_TREE

#include <tree/tree_node.h>

namespace leetcode {

class Solution {
public:
  TreeNode* balanceBST(TreeNode* root)
  {
    // convert the tree to an vector of TreeNode by inorder traversal
    std::vector<TreeNode *> arr;
    inorder(root, arr);

    // re-construct the tree using preorder traversal
    return bst(arr, 0, arr.size()-1);
  }

private:

  void inorder(TreeNode *root, std::vector<TreeNode *> &arr)
  {
    if (!root)
      return;

    inorder(root->left, arr);
    arr.push_back(root);
    inorder(root->right, arr);
  }

  TreeNode *bst(std::vector<TreeNode *> &arr, int l, int r)
  {
    if (l > r)
    {
      assert (l == r+1);
      return nullptr;
    }

    int mid = l + (r-l)/2;
    TreeNode *root = arr[mid];

    root->left = bst(arr, l, mid-1);
    root->right = bst(arr, mid+1, r);

    return root;
  }

};

} // end namespace leetcode


#endif
