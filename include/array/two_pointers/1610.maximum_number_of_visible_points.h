#ifndef INCLUDED_ARRAY_TWO_POINTERS_1610_MAXIMUM_NUMBER_OF_VISIBLE_POINTS
#define INCLUDED_ARRAY_TWO_POINTERS_1610_MAXIMUM_NUMBER_OF_VISIBLE_POINTS

#include <vector>

namespace leetcode {

class Solution {
public:
  int visiblePoints(std::vector<std::vector<int>>& points,
                    int angle,
                    std::vector<int>& location)
  {
    // Find the maximum visible points with in [-angle/2 + orientation,
    //                                           angle/2 + orientation]

    // sort points based on angle firstly
    // use two pointers to get the maximum number of points

    // 1. erase all points that are in location
    int n = points.size();

    auto remove_it =
      std::remove_if(points.begin(),
                     points.end(),
                     [&](const point_t &p)
                     { return p[0] == location[0] && p[1] == location[1]; });

    points.erase(remove_it, points.end());

    int visible = n - points.size();

    std::vector<double> radians;
    radians.reserve(points.size());

    for (auto i = 0; i != points.size(); ++i)
      radians.push_back(calc_radian(location, points[i]));

    std::sort(radians.begin(), radians.end());

    static double PI = atan2(1, 0) * 2.0;

    // append radian itself to the end
    n = radians.size();

    for (auto i = 0; i != n; ++i)
      radians.push_back(radians[i] + PI * 2.0);

    double radian = static_cast<double>(angle)/180.0 * PI;

    int max_pts = 0;

    for (auto l = 0, r = 0; r < radians.size(); ++r)
    {
      while (radians[r] - radians[l] > radian)
        ++l;

      max_pts = std::max(max_pts, r-l+1);
    }

    visible += max_pts;
    return visible;
  }

private:
  using point_t = std::vector<int>;

  double calc_radian(const point_t &o, const point_t &d)
  {
    double x = d[0] - o[0];
    double y = d[1] - o[1];
    return atan2(y, x);
  }
};

} // end namespace leetcode

#endif