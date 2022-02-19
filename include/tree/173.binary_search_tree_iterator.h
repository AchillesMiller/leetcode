#ifndef INCLUDED_TREE_173_BINARY_SEARCH_TREE_ITERATOR
#define INCLUDED_TREE_173_BINARY_SEARCH_TREE_ITERATOR

namespace leetcode {

class BSTIterator {

private:
  std::stack<TreeNode *> _nodes;

public:
  BSTIterator(TreeNode* root)
  : _nodes()
  {
    while (root)
    {
      _nodes.push(root);
      root = root->left;
    }
  }

  int next()
  {
    auto n = _nodes.top();
    int val = n->val;
    _nodes.pop();

    n = n->right;

    while(n)
    {
      _nodes.push(n);
      n = n->left;
    }

    return val;
  }

  bool hasNext()
  {
    return !_nodes.empty();
  }
};

} // end namespace leetcode

#endif