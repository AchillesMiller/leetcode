#ifndef INCLUDED_UNION_FIND_REDUNDANT_CONNECTION_II
#define INCLUDED_UNION_FIND_REDUNDANT_CONNECTION_II

#include <vector>

namespace leetcode {

// tried to find the redundant directed connection
// so, in another words, if there exists one node of which indegree >= 2
// those two edges are candidates, we want to choose one edge

// but, it may only have one circle, so, the indegree of each node is exactly
// equal to 1

// in this case, the last edge that caused union_find.union failed will be
// the edge to remove

class Solution {
public:
  std::vector<int>
    findRedundantDirectedConnection(std::vector<std::vector<int>>& edges)
  {
    using edge_t = std::vector<int>;

    // one constraint: len(nodes) == len(edges) and 1 <= nodes[i] <= len(nodes)
    int n = edges.size();
    std::vector<int> froms(n+1, -1);

    edge_t candidate_1;
    edge_t candidate_2;

    for (auto &edge: edges)
    {
      auto &e = edge[1];
      if (froms[e] != -1)
      {
        candidate_1 = edge_t{froms[e], e};
        candidate_2 = edge;

        // erase current edge
        edge[0] = edge[1] = -1;
        break;
      }

      froms[e] = edge[0];
    }

    union_find U(n+1);

    // if there still exists circle
    //     if candidate_1 is set before, return candidate_1
    //     else return the edge that caused the union_find.do_union failure
    // else
    //   return candidate_2
    for (auto &edge: edges)
    {
      auto &s = edge[0];
      auto &e = edge[1];

      if (s == -1)
        continue;

      if (!U.do_union(s, e))
        return candidate_1.empty()? edge: candidate_1;
    }

    return candidate_2;
  }

private:
  struct union_find
  {
    std::vector<int> parents;
    std::vector<int> ranks;

    union_find(int n)
    : parents(n, 0)
    , ranks(n, 0)
    {
      for (auto i = 0; i != parents.size(); ++i)
        parents[i] = i;
    }

    int parent(int x)
    {
      if (parents[x] == x)
        return x;

      parents[x] = parent(parents[x]);
      return parents[x];
    }

    bool do_union(int x, int y)
    {
      auto px = parent(x);
      auto py = parent(y);

      if (px == py)
        return false;

      if (ranks[px] > ranks[py])
        std::swap(px, py);

      parents[px] = py;

      if (ranks[px] == ranks[py])
        ranks[py] ++;

      return true;
    }
  };

};

} // end namespace leetcode

#endif