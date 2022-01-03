#ifndef INCLUDED_TREE_TREE_NODE
#define INCLUDED_TREE_TREE_NODE

#include <unordered_set>
#include <deque>

namespace leetcode {

namespace tree {
template <typename T> struct node;

template <typename T> struct node; // double linked node

} // end namespace node;

// leetcode declaration of TreeNode and Node(double linked node)

using TreeNode = tree::node<int>;
using Node     = tree::node<int>;

namespace tree {

template <typename T>
struct node
{
  T        val;
  node<T> *left;
  node<T> *right;

  node() : val(0), left(nullptr), right(nullptr) {}
  node(T x): val(x), left(nullptr), right(nullptr) {}
  node(T x, node<T> *l, node<T> *r): val(x), left(l), right(r) {}

  ~node()
  {
    // use post order to do garbage collection
    if (this->left)  delete this->left;
    if (this->right) delete this->right;
  }
};

template <typename T>
inline void break_circle(node<T> *root)
{
  std::unordered_set<node<T> *> visited;

  std::deque<node<T> *> Q;
  Q.push_back(root);

  visited.insert(root);
  visited.insert(nullptr);

  while (!Q.empty())
  {
    int size = Q.size();

    while (size-- > 0)
    {
      auto curr = Q.front();
      Q.pop_front();

      auto it = visited.insert(curr->left);
      if (it.second) Q.push_back(curr->left);
      else           curr->left = nullptr;

      it = visited.insert(curr->right);
      if (it.second) Q.push_back(curr->right);
      else           curr->right = nullptr;
    }
  }
}

} // end namespace tree

} // end namespace leetcode::tree

#endif
