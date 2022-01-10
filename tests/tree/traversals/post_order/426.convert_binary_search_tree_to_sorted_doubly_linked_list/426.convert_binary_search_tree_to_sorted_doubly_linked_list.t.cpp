#include <gtest/gtest.h>

#include <tree/traversals/post_order/426.convert_binary_search_tree_to_sorted_doubly_linked_list.h>

using namespace leetcode;

TEST(NO_426_convert_binary_search_tree_to_sorted_doubly_linked_list, I)
{
  Node * root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);

  auto dlinked = Solution().treeToDoublyList(root);

  // the order to go left is  [1, 2, 3, 4, 5]
  // the order to go right is [5, 4, 3, 2, 1]

  std::vector<int> lorders;
  lorders.reserve(5);

  auto it = dlinked;
  while(it)
  {
    lorders.push_back(it->val);
    it = it->right;
    if (it == dlinked)
      break;
  }

  std::vector<int> rorders;
  rorders.reserve(5);

  it = dlinked;
  while(it)
  {
    rorders.push_back(it->val);
    it = it->left;
    if (it == dlinked)
      break;
  }

  std::vector<int> lexpected{1, 2, 3, 4, 5};
  std::vector<int> rexpected{1, 5, 4, 3, 2};

  ASSERT_EQ(lorders, lexpected);
  ASSERT_EQ(rorders, rexpected);

  tree::break_circle(dlinked);

  delete dlinked;
}