#ifndef INCLUDED_TREE_TREE_NODE
#define INCLUDED_TREE_TREE_NODE

namespace leetcode {

namespace tree {
template <typename T> struct node;
} // end namespace node;

// leetcode declaration of TreeNode
using TreeNode = tree::node<int>;

namespace tree {
template <typename T>
struct node
{
  T        val;
  node<T> *left;
  node<T> *right;

  node() : val(0), left(nullptr), right(nullptr) {}
  node(T x): val(x), left(nullptr), right(nullptr) {}
  node(T x, TreeNode *left, TreeNode *r): val(x), left(left), right(right) {}

  ~node()
  {
    // postorder to release memory
    if (this->left)  delete this->left;
    if (this->right) delete this->right;
  }
};

} // end namespace tree

} // end namespace leetcode::tree

#endif
