#ifndef INCLUDED_UNION_FIND_NUMBER_OF_ISLANDS_II
#define INCLUDED_UNION_FIND_NUMBER_OF_ISLANDS_II

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


namespace leetcode {

// game of theory:
// 1. observation
//    when add a land, we can increase the count
//    in the same time, if this land succeed to union with one of its neighbor.
//       --count.
//        1
//     1  x  1
//        1

//     for this case, it can succeed to union once, after it, x becomes 1
//
// 2. when processing the positions, the neighbor to check is
//    neighbor land is added before
//    if it is true, try to do the union

class Solution {
public:
  std::vector<int> numIslands2(int m, int n,
                               std::vector<std::vector<int>>& positions)
  {
    // each time one land is added, the number of islands ++;
    // there are four directions to check
    // if we can union the current land with one cluster , -1
    //                                       two clusters, -2
    //                                      four clusters, -4

    // create a vector to store positions and lookup map

    std::unordered_map<point_t, int, point_hash> lookup;
    std::vector<point_t> points;
    points.reserve(positions.size());

    for (auto &p: positions)
    {
      auto it = lookup.insert({{p[0], p[1]}, points.size()});
      if (it.second) // succeed to insert
        points.push_back(std::make_pair(p[0], p[1]));
    }

    union_find U(points.size());

    std::unordered_set<int> visited;

    std::vector<int> islands;
    islands.reserve(positions.size());

    int count = 0;

    for (auto &p: positions)
    {
      islands.push_back(count);

      std::pair<int, int> x(p[0], p[1]);

      int idx = lookup[x];

      auto it = visited.insert(idx);

      if (!it.second)
        continue;

      ++count;

      static const std::vector<std::pair<int, int>> ds {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
      };

      for (auto &d: ds)
      {
        auto r = d.first + x.first;
        auto c = d.second + x.second;

        if (r < 0 || r >= m || c < 0 || c >= n)
          continue;

        auto found = lookup.find({r, c});

        if (found == lookup.end())   // check existence, == has associated idx
          continue;

        auto &nidx = found->second;

        if (visited.find(nidx) == visited.end()) // not processed yet
          continue;

        if (U.do_union(idx, nidx))
          --count;
      }

      islands.back() = count;
    }

    return islands;
  }

private:

  using point_t = std::pair<int, int>;

  struct point_hash
  {
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &p) const
    {
      std::size_t ret = 17;

      ret = 31 * ret + std::hash<T>()(p.first);
      ret = 31 * ret + std::hash<U>()(p.second);
      return ret;
    }
  };

  struct union_find {

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
        return parents[x];

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

      if (ranks[py] == ranks[px])
        ranks[py] += 1;

      return true;
    }
  };
};

} // end namespace leetcode

#endif