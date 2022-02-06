#ifndef INCLUDED_TREE_129_SUM_ROOT_TO_LEAF_NUMBERS
#define INCLUDED_TREE_129_SUM_ROOT_TO_LEAF_NUMBERS

namespace leetcode {

/** @brief: Sum Root to Leaf Numbers
 *  You are given the root of a binary tree containing digits from 0 to 9 only.
 *
 * Each root-to-leaf path in the tree represents a number.
 *
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * Return the total sum of all root-to-leaf numbers.
 * Test cases are generated so that the answer will fit in a 32-bit integer.
 *
 * A leaf node is a node with no children.
 **/

class Solution {
public:
  int sumNumbers(TreeNode* root) {

    // so, sum = sum(left) + sum(right)
    // path sum should be passed to left and right

    return sum_numbers(root);
  }

private:
  int sum_numbers(TreeNode *root, int path=0)
  {
    assert (root); // logical error

    path = 10 * path + root->val;

    int sum = 0;

    if (!root->left && !root->right)
      return path;

    if (root->left)
      sum += sum_numbers(root->left, path);

    if (root->right)
      sum += sum_numbers(root->right, path);

    return sum;
  }

};

} // end namespace leetcode

#endif