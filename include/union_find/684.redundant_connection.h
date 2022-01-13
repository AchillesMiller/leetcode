#ifndef INCLUDED_UNION_FIND_684_REDUNDANT_CONNECTION
#define INCLUDED_UNION_FIND_684_REDUNDANT_CONNECTION

#include <vector>

namespace leetcode {

class Solution {
public:

  /** @brief find redundant connections
   *  Find the redundant connections, (find edge that forms circle)
   **/
  std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
  {
    // constraints: nodes.length == edges.length
    //              1 <= node <= nodes.length
    int n = edges.size();

    union_find U(n+1);

    std::vector<int> redundant;

    for (auto &edge :edges)
    {
      auto &a = edge[0];
      auto &b = edge[1];

      if (!U.do_union(a, b))
        redundant = edge;
    }

    return redundant;
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
      if (x == parents[x])
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