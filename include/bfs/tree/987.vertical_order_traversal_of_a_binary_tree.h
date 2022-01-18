#ifndef INCLUDE_TREE_BFS_987_VERTICAL_ORDER_TRAVERSAL_OF_A_BINARY_TREE
#define INCLUDE_TREE_BFS_987_VERTICAL_ORDER_TRAVERSAL_OF_A_BINARY_TREE

// BFS to generate the vertical information together with tree node itself
// use a map to maintain the column buckets                -> impl struct node
// use a sorted vector to maintain the order inside bucket -> impl less method

#include <vector>
#include <algorithm>
#include <tree/tree_node.h>
#include <deque>

namespace leetcode {

class Solution {

public:
  /**
   *@brief Vertical Order Traversal of a Binary Tree
   */
  std::vector<std::vector<int>> verticalTraversal(TreeNode* root)
  {
    // try to organize the tree nodes to different buckets, bucket's label is
    // the column value.
    // and, inside the bucket, the node is sorted by row and value

    // therefore, first thing to do is to create a map from column value to
    //   a vector of node(TreeNode *n, int column, int row)
    // this map acts as the buckets

    // and, the vector of node should be sorted during the period to insert more
    // node

    std::vector<std::vector<int>> rets;

    if (!root) return rets;

    std::map<int, std::vector<node>> buckets;
    //       ---  -----------------
    //       col  node vector

    // USE BFS to generate the nodes

    std::deque<node> Q;
    Q.push_back(node(root, 0, 0));

    while (!Q.empty())
    {
      int size = Q.size();

      while(size-- > 0)
      {
        auto &curr = Q.front();

        auto &n = curr.n;
        auto &col = curr.col;
        auto &row = curr.row;

        if (n->left)  Q.push_back(node(n->left , col-1, row+1));
        if (n->right) Q.push_back(node(n->right, col+1, row+1));

        // visiting current node
        auto it = buckets.insert({col, std::vector<node>()});
        auto &vec = it.first->second;

        auto pos = std::lower_bound(vec.begin(), vec.end(), curr, less());
        vec.insert(pos, std::move(curr));

        Q.pop_front();
      }
    }

    rets.reserve(buckets.size());

    for (auto &x: buckets)
    {
      auto &vec = x.second;
      rets.push_back({});
      rets.back().reserve(vec.size());

      for (auto &n: vec)
        rets.back().push_back(n.n->val);
    }

    return rets;
  }

private:
  struct node
  {
    TreeNode *n;
    int       col;
    int       row;

    node(TreeNode *x, int c, int r)
    : n(x)
    , col(c)
    , row(r)
    {}
  };

  struct less {
    bool operator()(const node &l, const node &r) const
    {
      if (l.col == r.col && l.row == r.row)
        return l.n->val < r.n->val;

      if (l.col == r.col)
        return l.row < r.row;

      return l.col < r.col;
    }
  };

};

} // end namespace leetcode

#endif