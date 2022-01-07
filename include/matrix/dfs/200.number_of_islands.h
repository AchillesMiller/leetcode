#ifndef INCLUDED_MATRIX_DFS_NUMBER_OF_ISLANDS_200
#define INCLUDED_MATRIX_DFS_NUMBER_OF_ISLANDS_200

#include <vector>

namespace leetcode {

// dfs / union find, both are ok to find the connected components
// here, dfs is just a easy solution

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {

    int M = grid.size();
    int N = grid[0].size();

    int island = 0;

    for (auto r = 0; r != M; ++r)
      for (auto c = 0; c != N; ++c)
        if (dfs(grid, r, c))
          ++island;

    return island;
  }

private:
  bool dfs(std::vector<std::vector<char>> &grid, int r, int c)
  {
    if (grid[r][c] != '1') // either visited or is ocean
      return false;

    grid[r][c] = '0';

    static const std::vector<std::pair<int, int>> ds {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    for (auto &d: ds)
    {
      auto rr = r + d.first;
      auto cc = c + d.second;

      if (rr < 0 || rr >= grid.size()     ||
          cc < 0 || cc >= grid[rr].size() ||
          grid[rr][cc] != '1')
        continue;

      dfs(grid, rr, cc);
    }

    return true;
  }

};

} // end namespace leetcode

#endif
