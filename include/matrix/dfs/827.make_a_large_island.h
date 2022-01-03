#ifndef INCLUDED_MATRIX_DFS_827_MAKE_A_LARGE_ISLAND
#define INCLUDED_MATRIX_DFS_827_MAKE_A_LARGE_ISLAND

#include <vector>
#include <unordered_set>

namespace leetcode {

class Solution {

private:
  using matrix_t = std::vector<std::vector<int>>;

public:
  /**
   * @brief Make a largest island by changing one 0 to be 1
   **/
  int largestIsland(std::vector<std::vector<int>>& grid) {

    // Get connected components from grid, it can be either DFS/BFS
    // After we got the list of connected components, try to change each 0
    //   to see if this change connects multiple connected component into one

    // 1. for each dfs run, we want to label the connected component(CC)
    //    with different number and record its area
    // 2. for each 0 left, we want to check if it connects multiple CCs,
    //    if it is, sum up the area of those CCs

    std::vector<int> areas{0, 0}; // the area vector
                                  // after running dfs, all 1 changed to label
                                  // so both area[0] and area[1] should be 0

    int M = grid.size();
    int N = grid[0].size();

    int max_area = 0;

    for (auto i = 0; i != M; ++i)
      for (auto j = 0; j != N; ++j)
        if (grid[i][j] == 1) // island
        {
          // let's dance
          int label = areas.size();
          areas.push_back(0);

          areas.back() = island(grid, i, j, label);
          max_area = std::max(areas.back(), max_area);
        }

    // the grid is labeled with different number now

    for (auto i = 0; i != M; ++i)
      for (auto j = 0; j != N; ++j)
        if (grid[i][j] == 0) // ocean
        {
          int area = connected_component(grid, i, j, areas);
          max_area = std::max(area, max_area);
        }

    return max_area;
  }

private:

  static const std::vector<std::pair<int, int>> & directions()
  {
    static std::vector<std::pair<int, int>> dirs {
      {1, 0},   // bottom
      {-1, 0},  // up
      {0, -1},  // left
      {0, 1}    // right
    };

    return dirs;
  }

  int island(matrix_t & grid, int r, int c, int label)
  {
    int area = 1;

    // visiting (r, c)
    grid[r][c] = label;

    for (auto &d: directions())
    {
      auto rr = r + d.first;
      auto cc = c + d.second;

      if (rr < 0 || rr >= grid.size() || cc < 0 || cc >= grid[rr].size() ||
          grid[rr][cc] != 1)
        continue;

      area += island(grid, rr, cc, label);
    }
    return area;
  }

  int connected_component(const matrix_t &grid,
                          int r, int c,
                          const std::vector<int> &areas)
  {
    int area = 1;
    std::unordered_set<int> labels;

    for (auto &d: directions())
    {
      auto rr = r + d.first;
      auto cc = c + d.second;

      if (rr < 0 || rr >= grid.size() || cc < 0 || cc >= grid.size())
        continue;

      labels.insert(grid[rr][cc]);
    }

    for (auto &label: labels)
      area += areas[label];

    return area;
  }

};

} // end namespace leetcode

#endif
