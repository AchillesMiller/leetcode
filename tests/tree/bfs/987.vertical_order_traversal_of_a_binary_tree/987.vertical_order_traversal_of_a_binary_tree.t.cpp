#include <gtest/gtest.h>
#include <tree/bfs/987.vertical_order_traversal_of_a_binary_tree.h>

using namespace leetcode;

TEST(vertical_order_traversal_of_a_binary_tree_987, I)
{
  TreeNode * root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  std::vector<std::vector<int>> expected {
    {9},
    {3, 15},
    {20},
    {7}
  };

  ASSERT_EQ(Solution().verticalTraversal(root), expected);
}

TEST(vertical_order_traversal_of_a_binary_tree_987, II)
{
  TreeNode * root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::vector<std::vector<int>> expected {
    {4},
    {2},
    {1, 5, 6},
    {3},
    {7}
  };

  ASSERT_EQ(Solution().verticalTraversal(root), expected);
}


