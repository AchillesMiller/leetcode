#ifndef INCLUDED_TREE_LCA_1650
#define INCLUDED_TREE_LCA_1650

#include <tree/tree_node.h>
#include <unordered_set>

namespace leetcode::lca {

class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q) {
    // given the parent of node, find the lowest common ancestor
    // there are two solutions, firstly, using the hash table to lookup

    std::unordered_set<Node *> parents;
    parents.insert(q); // insert q, if find q, return it
    auto lca = lookup(p, parents);

    if (lca) // find lowest common ancestor, which is q
      return lca;

    parents.erase(q);  // erase q

    return lookup(q, parents);
  }

private:

  Node* lookup(Node *p, std::unordered_set<Node *> &parents)
  {
    auto it = parents.insert(p);

    // p is inserted before
    if (!it.second) return *it.first;

    if (!p) // it is nullptr
      return nullptr;

    return lookup(p->parent, parents);
  }

public:
  Node* lowestCommonAncestor2(Node* p, Node * q) {
    // this is O(1) space complexity solution

    //     root
    //     [x]
    //     lca
    //   [x1]  [x2]
    //  p         q

    // it will takes x1 step to arrive lca from p, and x2 step from q
    // and it will takes x steps to arrive root
    // supposed, root's parent is p and q, it will takes x2 + x + x1 to
    // arrive lca from q, and x1 + x + x2 steps to arrive lca from p

    // no doubt, lca will be arrived in the same from p or q

    auto a = p, b = q;

    while (a != b)
    {
      a = a? a->parent: q;
      b = b? b->parent: p;
    }

    return a;
  }

};

} // end namespace leetcode::lca