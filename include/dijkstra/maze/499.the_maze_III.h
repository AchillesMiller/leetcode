#ifndef INCLUDED_DIJKSTRA_MAZE_499_THE_MAZE_III
#define INCLUDED_DIJKSTRA_MAZE_499_THE_MAZE_III

namespace leetcode {

class Solution {

  // @note: erase node when popping
  //        check if node is erased in pushing

public:
  std::string findShortestWay(std::vector<std::vector<int>>& maze,
                              std::vector<int>& ball,
                              std::vector<int>& hole)
  {
    // still using DIJKSTRA Algorithm
    // but this time, we need record path as a string


    for (auto &r: maze)
      for (auto &c: r)
        c = (c == 1)? BLOCK: INT_MAX;

    // so a node structure is declared together with path cached
    std::priority_queue<node, std::vector<node>, greater> Q;

    Q.push(std::move(node(ball[0], ball[1], 0, "")));

    while (!Q.empty())
    {
      auto curr = Q.top();
      Q.pop();

      if (curr.r == hole[0] && curr.c == hole[1]) // shortest!!!
        return curr.p;

      maze[curr.r][curr.c] = curr.d; // set shortest

      // find curr's neighbors
      auto nodes = neighbors_of(curr, maze, hole);

      for (auto &n: nodes)
      {
        if (maze[n.r][n.c] != INT_MAX) // skip already-shortest
          continue;
        Q.push(n);
      }
    }

    return "impossible";
  }

private:
  static int BLOCK; // -1

private:
  struct node
  {
    int         r;
    int         c;
    int         d;
    std::string p;

    node(int r, int c, int d, const std::string &p): r(r), c(c), d(d), p(p) {}
  };

  struct greater
  {
    bool operator()(const node &l, const node &r) const
    {
      if (l.d == r.d)
        return l.p > r.p;
      return l.d > r.d;
    }
  };

private:
  using maze_t = std::vector<std::vector<int>>;

  std::vector<node>
    neighbors_of(const node &n, maze_t &m, std::vector<int> &hole)
  {
    std::vector<node> neighbors;
    neighbors.reserve(4);

    static std::vector<std::pair<int, int>> dirs {
      {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };

    static std::string dir_names = "lrud";

    for (auto i = 0; i != dirs.size(); ++i)
    {
      int r = n.r, c = n.c, d = n.d;
      int dr = dirs[i].first, dc = dirs[i].second;

      auto p = n.p;

      while (r+dr >= 0 && r+dr < m.size()       &&
             c+dc >= 0 && c+dc < m[r+dr].size() &&
             m[r+dr][c+dc] != BLOCK              )
      {
        r += dr;
        c += dc;
        d ++;
        if (r == hole[0] && c == hole[1])
          break;
      }

      if (d == n.d)
        continue;

      neighbors.push_back(node(r, c, d, p.append(1, dir_names[i])));
    }

    return neighbors;

  }

};

int Solution::BLOCK = -1;

} // end namespace leetcode

#endif