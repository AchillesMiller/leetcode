#ifndef INCLUDED_TREE_109_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE
#define INCLUDED_TREE_109_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE

namespace leetcode {

/** @brief convert sorted array to binary search tree
 *  Given the head of a singly linked list where elements are sorted
 *  in ascending order, convert it to a height balanced BST.
 **/

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {

    // definitely, the list is organized inorder
    // we would like to construct a tree based on inorder

    int len = get_len(head);

    return construct_bst_inorder(head, 0, len-1);
  }

private:
  int get_len(ListNode *head)
  {
    int len = 0;
    while(head)
    {
      ++len;
      head = head->next;
    }

    return len;
  }

  TreeNode * construct_bst_inorder(ListNode * &curr, int l, int r)
  {
    if (l > r)
      return nullptr;

    assert (curr);

    int m = l + (r-l)/2;

    auto left = construct_bst_inorder(curr, l, m-1);

    assert (curr);

    TreeNode *root = new TreeNode(curr->val);
    curr = curr->next;

    auto right = construct_bst_inorder(curr, m+1, r);

    root->left = left;
    root->right = right;

    return root;
  }

};

} // end namespace leetcode

#endif