#ifndef INCLUDED_MAP_939_MINIMUM_AREA_RECTANGLE
#define INCLUDED_MAP_939_MINIMUM_AREA_RECTANGLE

namespace leetcode {

/** @brief: minimum area rectangle
 *  You are given an array of points in the X-Y plane points
 *  where points[i] = [xi, yi].
 *
 *  Return the minimum area of a rectangle formed from these points,
 *  with sides parallel to the X and Y axes. If there is not any such rectangle,
 *  return 0.
 **/

class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {

    // how to find rectangle?
    // we can check pairwise as diagonal, check their other two corners exist

    // so, we need a data structure to record there is a point

    auto hash = [](int x, int y) -> uint32_t
    {
      return (x << 16) | y;
    };

    std::unordered_set<uint32_t> pts;
    pts.reserve(points.size());

    for (auto &p: points)
      pts.insert(hash(p[0], p[1]));

    int min_area = INT_MAX;

    for (auto i = 0; i != points.size(); ++i)
      for (auto j = i+1; j != points.size(); ++j)
      {
        auto &p1 = points[i];
        auto &p2 = points[j];

        if (p1[0] == p2[0] || p1[1] == p2[1])
          continue;

        if (pts.find(hash(p1[0], p2[1])) != pts.end() &&
            pts.find(hash(p2[0], p1[1])) != pts.end()  )
          min_area = std::min(min_area,
                              std::abs((p1[0]-p2[0]) * (p1[1]-p2[1])));
      }

    return (min_area == INT_MAX)? 0: min_area;
  }
};


} // end namespace leetcode

#endif