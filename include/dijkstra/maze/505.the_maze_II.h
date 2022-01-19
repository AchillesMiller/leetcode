#ifndef INCLUDED_DIJKSTRA_MAZE_505_THE_MAZE_II
#define INCLUDED_DIJKSTRA_MAZE_505_THE_MAZE_II

#include <vector>

namespace leetcode {

class Solution {
public:
  int shortestDistance(std::vector<std::vector<int>>& maze,
                       std::vector<int>& src,
                       std::vector<int>& dst)
  {
    // Given a ball at src, find the shortest path to dst

    // It is DIJKSTRA problem to find the shortest path from one single
    // source to destination

    // DIJKSTRA CODE
    //   1. pop the node with shortest  path
    //       if node i is visited, it is guaranteed to be shorts path
    //   2. pushing nodes' neighbors to heap

    // pruning: if record distance of node is smaller
    //          won't push this node again


    // dijkstra time performance: O(E + VlogV)

    // unlike the normal dijkstra problem - V is fixed.
    // we need continue finding nodes and do our job

    // maze[i][j] == 1 means block
    // change 1 to -1, and other 0 to be INT_MAX <- dijkstra 

    for (auto &r: maze)
      for (auto &c: r)
        c = (c == 1)? -1: INT_MAX;

    // point_t: std::vector<int>      x, y, distance

    std::priority_queue<point_t, std::vector<point_t>, greater> Q;
    Q.push({src[0], src[1],   0});
    //      ------ ---------  ---
    //         r       c       d
    maze[src[0]][src[1]] = 0;

    while (!Q.empty())
    {
      auto curr = Q.top();
      Q.pop();

      if (curr[0] == dst[0] && curr[1] == dst[1]) // visited dst
                                                  // shortest !!!!
        return curr[2];

      maze[curr[0]][curr[1]] = curr[2];

      auto nodes = neighbors_of(curr, maze);

      for (auto &n: nodes)
      {
        auto &r        = n[0];
        auto &c        = n[1];

        if (maze[r][c] != INT_MAX) // erased
          continue;

        Q.push(n);
      }
    }

    return -1;
  }

private:
  using point_t = std::vector<int>;
  using maze_t = std::vector<std::vector<int>>;

  struct greater
  {
    bool operator()(const point_t &l, const point_t &r) const
    {
      return l[2] > r[2];
    }
  };

  std::vector<point_t> neighbors_of(const point_t &x, const maze_t &m)
  {
    std::vector<point_t> neighbors;
    neighbors.reserve(4);

    static std::vector<std::pair<int, int>> dirs {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}
    };

    for (auto &dir: dirs)
    {
      int r = x[0];
      int c = x[1];
      int d = x[2];
      int dr = dir.first;
      int dc = dir.second;

      while (r + dr >= 0 && r + dr < m.size()       &&
             c + dc >= 0 && c + dc < m[r+dr].size() &&
             m[r+dr][c+dc] != -1                     )
      {
        r += dr;
        c += dc;
        d ++;
      }

      if (d == x[2]) // itself
        continue;

      neighbors.push_back({r, c, d});
    }

    return neighbors;

  }
};

} // end namespace leetcode

#endif