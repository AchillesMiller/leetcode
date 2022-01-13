#ifndef INCLUDED_BFS_MATRIX_1293_SHORTEST_PATH_GRID_WITH_OBSTACLES_ELIMINATION
#define INCLUDED_BFS_MATRIX_1293_SHORTEST_PATH_GRID_WITH_OBSTACLES_ELIMINATION

#include <vector>
#include <queue>

namespace leetcode {

// 1. shortest path problem, use BFS
// 2. usually, when visited a node, we set block to prevent visit again
//    but this question, when pushing into queue, this node have chance to be
//    visited again, that is, with less obstacle elimination.
//    in another word, if we tried to push that node into queue, and found
//    it was visited before with less obstacle eliminations, it is temporarily
//    blocked

class Solution {
public:
  int shortestPath(std::vector<std::vector<int>>& grid, int k) {

    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> eliminations(m, std::vector<int>(n, INT_MAX));
    //                                                                ---------
    //                                              initialized to be REACHABLE

    using point_t = std::pair<int, int>; // row, col

    int path = 0;

    if (m == 1 && n == 1) // no move needed
      return path;

    std::deque<point_t> Q;
    Q.push_back({0, 0});

    eliminations[0][0] = 0;

    while (!Q.empty())
    {
      // access layer
      int size = Q.size();
      while (size-- > 0)
      {
        auto curr = Q.front();
        Q.pop_front();

        static const std::vector<std::pair<int, int>> ds {
          {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        for (auto &d: ds)
        {
          auto r = d.first + curr.first;
          auto c = d.second + curr.second;

          if (r < 0 || r >= m || c < 0 || c >= grid[r].size())
            continue;

          int elimination = eliminations[curr.first][curr.second] + grid[r][c];

          if (elimination > k || elimination >= eliminations[r][c])
          //  ---------------    ---------------------------------
          //  unreachable        was arrived before with less eliminations
          //                     not necessary to continue the BFS
            continue;

          if (r + 1 == m && c + 1 == n)
            return path + 1;

          eliminations[r][c] = elimination;

          Q.push_back({r, c});
        }

      }
      ++ path; // increment path
    }

    return -1;
  }
};

} // end namespace leetcode

#endif