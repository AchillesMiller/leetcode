#ifndef INCLUDED_TOPOLOGICAL_SORT_310_MINIMUM_HEIGHT_TREES
#define INCLUDED_TOPOLOGICAL_SORT_310_MINIMUM_HEIGHT_TREES

namespace leetcode {

/** @brief: Find root of minimum height trees
  * Given a tree of n nodes labelled from 0 to n - 1,
  * and an array of n - 1 edges where edges[i] = [ai, bi] indicates
  * that there is an undirected edge between the two nodes ai and bi
  * in the tree, you can choose any node of the tree as the root.
  * When you select a node x as the root, the result tree has height h.
  * Among all possible rooted trees, those with minimum height (i.e. min(h))
  * are called minimum height trees (MHTs).
  **/

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
  {
    // each time, the outer nodes will be erased
    // till there are less than 2 nodes

    // so, topological sort

    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) return {0, 1};

    using graph_t = std::vector<std::vector<int>>;

    graph_t G(n);
    std::vector<int> indegrees(n, 0);

    for (auto &edge: edges)
    {
      auto &a = edge[0];
      auto &b = edge[1];

      indegrees[a] ++;
      indegrees[b] ++;

      G[a].push_back(b);
      G[b].push_back(a);
    }

    std::deque<int> Q;

    for (auto i = 0; i != indegrees.size(); ++i)
      if (indegrees[i] == 1)
        Q.push_back(i);

    int count = 0;

    while (!Q.empty())
    {
      int size = Q.size();

      while (size -- > 0)
      {
        auto curr = Q.front(); // erase
        Q.pop_front();
        ++count;

        for (auto &next: G[curr])
          if (--indegrees[next] == 1)
            Q.push_back(next);
      }

      if (count == n-1 || count == n - 2)
        break;
    }

    std::vector<int> rets;
    rets.reserve(Q.size());

    while (!Q.empty())
    {
      rets.push_back(Q.front());
      Q.pop_front();
    }

    return rets;
  }

  // 1 - 2 - 3 : the root with minimum height is 2
  // 1 - 2 - 3 - 4: the root of minimum height is 2 and 3
};

} // end namespace leetcode

#endif