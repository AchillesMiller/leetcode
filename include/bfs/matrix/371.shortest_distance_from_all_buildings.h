#ifndef INCLUDED_SHORTEST_DISTANCE_FROM_ALL_BUILDINGS_317
#define INCLUDED_SHORTEST_DISTANCE_FROM_ALL_BUILDINGS_317

#include <vector>
#include <deque>

namespace leetcode {

class Solution {
private:
  using matrix_t = std::vector<std::vector<int>>;

public:
  /**
   * @brief get the shortest distance to reach out all buildings,
   *        return -1 if one or more buildings are not reachable
   **/
  int shortestDistance(std::vector<std::vector<int>>& grid) {
    // to solve the shortest distance, the first thing came to mind is BFS

    // it is easy to solve if there exists one source(one building)
    // but for this case, it need process multiple buildings

    // therefore, we will create a matrix, and matrix[i][j] will record how many
    // buildings can reach out so far,
    // by this way, we can prune the bfs tree earlier.
    // ** if the position cannot be reached out earlier, it is a meaningless
    //    to continue bfs **

    // we can reuse the grid to record the distance, which is a negative number

    int M = grid.size();
    int N = grid[0].size();

    int it = 0; // bfs run times

    matrix_t reached(M, std::vector<int>(N, 0));

    for (auto i = 0; i != M; ++i)
      for (auto j = 0; j != N; ++j)
        if (grid[i][j] == 1) // building
          bfs(grid, i, j, reached, it++);

    int min_dist = std::numeric_limits<int>::max();

    for (auto i = 0; i != M; ++i)
      for (auto j = 0; j != N; ++j)
        if (reached[i][j] == it)
          min_dist = std::min(min_dist, -grid[i][j]);

    return min_dist == std::numeric_limits<int>::max()? -1: min_dist;
  }

private:
  void bfs(matrix_t &grid, int r, int c, matrix_t &reached, int it)
  {
    using point_t = std::pair<int, int>;
    using direction_t = std::pair<int, int>;

    int distance = 0;

    std::deque<point_t> q;
    q.push_back({r, c});

    while (!q.empty())
    {
      int size = q.size();

      ++distance;

      while(size-- > 0)
      {
        auto curr = q.front();
        q.pop_front();

        static std::vector<direction_t> ds {
          {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (auto &d: ds)
        {
          auto r = curr.first + d.first;
          auto c = curr.second + d.second;

          if (r < 0 || r >= grid.size()    ||  // out of bound
              c < 0 || c >= grid[r].size() ||  // out of bound
              grid[r][c] > 0               ||  // blocks or buildings
              reached[r][c] != it           )  // one or more buildings cannot reach
            continue;

          reached[r][c] ++;
          grid[r][c] -= distance;
          q.push_back({r, c});
        }
      }
    }
  }
};

} // end namespace leetcode

#endif
