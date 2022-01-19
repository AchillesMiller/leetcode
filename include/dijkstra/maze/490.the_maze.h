#ifndef INCLUDED_DIJKSTRA_490_THE_MAZE
#define INCLUDED_DIJKSTRA_490_THE_MAZE

#include <vector>

namespace leetcode {


// @note: this is used BFS to check if there exists path
//        it is not dijkstra problem, but Maze II and III are.
//        so, put codes under dijkstra folder

class Solution {
public:
  bool hasPath(std::vector<std::vector<int>>& maze,
               std::vector<int>& src,
               std::vector<int>& dst)
  {
    // ball can only stop if against wall
    // 1 means block

    // a simple bfs to solve this problem
    // dfs is also ok

    // one interesting point is, we always want to find the next stop
    // instead of growing one level each time

    std::deque<point_t> Q;

    static int VISITED = -1;

    // if one pixel(x, y) is visited before, set maze[x][y] == -1
    Q.push_back(std::make_pair(src[0], src[1]));
    maze[src[0]][src[1]] = VISITED;

    while (!Q.empty())
    {
      auto curr = Q.front();
      Q.pop_front();

      auto points = neighbors(curr, maze);

      for (auto &p: points)
      {
        if (maze[p.first][p.second] == VISITED)
          continue;

        if (p.first == dst[0] && p.second == dst[1])
          return true;

        maze[p.first][p.second] = VISITED;
        Q.push_back(p);
      }
    }

    return false;
  }

private:
  using maze_t = std::vector<std::vector<int>>;
  using point_t = std::pair<int, int>;

  std::vector<point_t> neighbors(const point_t &curr, maze_t &maze)
  {
    std::vector<point_t> ns;
    ns.reserve(4);

    static const std::vector<std::pair<int, int>> dirs {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    for (auto &dir: dirs)
    {
      int r = curr.first;
      int c = curr.second;

      int dr = dir.first;
      int dc = dir.second;

      while (r + dr >= 0 && r + dr < maze.size()       &&
             c + dc >= 0 && c + dc < maze[r+dr].size() &&
             maze[r+dr][c+dc] != 1                      )
      {
        r += dr;
        c += dc;
      }

      if (r == curr.first && c == curr.second)
        continue;

      ns.push_back(std::make_pair(r, c));
    }

    return ns;
  }


};

} // end namespace leetcode

#endif