#ifndef INCLUDED_INTERVALS_56_MERGE_INTERVAL
#define INCLUDED_INTERVALS_56_MERGE_INTERVAL

#include <vector>
#include <algorithm>

namespace leetcode {

class interval_merger {

public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
  {
    // sweep line algorithm
    // 1. sort the points with coordinate
    // 2. iterate all points, if START, ++it
    //                        else      --it
    // if it is decremented to 0, one merged interval is generated

    std::vector<std::vector<int>> rets;

    int N = intervals.size();
    rets.reserve(N);

    std::vector<point_t> points;
    points.reserve(2*N);

    for (auto &x: intervals)
    {
      points.push_back(std::make_pair(x[0], START));
      points.push_back(std::make_pair(x[1], END));
    }

    // ascending order
    std::sort(points.begin(), points.end(), less());

    int it = 0;
    std::vector<int> interval(2, 0);

    for (auto &p: points)
    {
      switch(p.second)
      {
        case START:
          if (it++ == 0)
            interval[0] = p.first;
          break;

        case END:
          if (--it == 0)
          {
            interval[1] = p.first;
            rets.push_back(interval);
          }
          break;
        default:
          assert(0);
      }
    }

    return rets;
  }

  std::vector<std::vector<int>> merge2(std::vector<std::vector<int>> &intervals)
  {
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;
    merged.reserve(intervals.size());

    for (auto &interval: intervals)
    {
      auto &start = interval[0];
      auto &end = interval[1];

      if (merged.empty() || merged.back()[1] < start)
        merged.push_back({start, end});
      else
        merged.back()[1] = std::max(merged.back()[1], end);
    }
    return merged;
  }

private:
  enum point_type
  {
    START      = 0,
    END        = 1,
    NUM_POINT_TYPE
  };

  using point_t = std::pair<int, point_type>;
  //                        ---- -----------
  //                       coord START/END

  struct less
  {
    bool operator()(const point_t &l, const point_t &r) const
    {
      if (r.first == l.first)
        return l.second < r.second;
      return l.first < r.first;
    }
  };

};

} // end namespace leetcode

#endif
