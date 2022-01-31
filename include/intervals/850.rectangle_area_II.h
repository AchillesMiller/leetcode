#ifndef INCLUDED_INTERVALS_850_RECTANGLE_AREA_II
#define INCLUDED_INTERVALS_850_RECTANGLE_AREA_II

namespace leetcode {

/** @brief: rectangle area II
 *  Calculate the total area covered by all rectangles in the plane.
 *  Any area covered by two or more rectangles should only be counted once.
 **/

class Solution {
public:
  int rectangleArea(std::vector<std::vector<int>>& rectangles) {

    // iterate each x coordinates, each x coordinate will have a corresponding
    // interval list

    // for each interval list, we can use sweep line again to solve

    std::vector<point_x_t> xs;
    xs.reserve(rectangles.size() * 2);

    for (auto &r: rectangles)
    {
      if (r[0] >= r[2] || r[1] >= r[3])
        continue;
      xs.push_back(point_x_t{r[0], OPEN, r[1], r[3]});
      xs.push_back(point_x_t{r[2], CLOSE, r[1], r[3]});
    }

    std::sort(xs.begin(), xs.end()); // close go firstly

    int64_t area = 0;

    std::vector<point_y_t> ys;
    add_interval(ys, xs[0][2], xs[0][3]);

    for (auto i = 1; i != xs.size(); ++i)
    {
      area += gain_area(ys, xs[i-1][0], xs[i][0]);

      if (xs[i][1] == OPEN) // OPEN
        add_interval(ys, xs[i][2], xs[i][3]);
      else
        erase_interval(ys, xs[i][2], xs[i][3]);
    }

    return area % int64_t(1e9+7);
  }

private:
  enum mode
  {
    CLOSE = 0,
    OPEN = 1
  };

  using point_x_t = std::vector<int>; // x, mode, y0, y1
  using point_y_t = std::vector<int>; // y, mode

  int64_t gain_area(std::vector<point_y_t> &ys, int x0, int x1)
  {
    if (ys.empty())
      return 0;

    int64_t W = x1-x0;
    int64_t H = 0;

    int open = 0;
    int64_t y0 = 0;

    for (auto &y: ys)
    {
      switch(y[1])
      {
        case OPEN : if (open ++ == 0) y0 = y[0]     ; break;
        case CLOSE: if (-- open == 0) H += y[0] - y0; break;
      }
    }

    static int64_t MODULO = 1e9 + 7;
    return (H % MODULO * W % MODULO) % MODULO;
  }

  void add_interval(std::vector<point_y_t> &ys, int y0, int y1)
  {
    auto it = std::lower_bound(ys.begin(), ys.end(), point_y_t{y0, OPEN});
    ys.insert(it, point_y_t{y0, OPEN});

    it = std::lower_bound(ys.begin(), ys.end(), point_y_t{y1, CLOSE});
    ys.insert(it, point_y_t{y1, CLOSE});
  }

  void erase_interval(std::vector<point_y_t> &ys, int y0, int y1)
  {
    auto it = std::lower_bound(ys.begin(), ys.end(), point_y_t{y0, OPEN});
    assert (it != ys.end());
    ys.erase(it);

    it = std::lower_bound(ys.begin(), ys.end(), point_y_t{y1, CLOSE});
    assert (it != ys.end());
    ys.erase(it);
  }
};

} // end namespace leetcode

#endif