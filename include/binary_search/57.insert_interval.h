#ifndef INCLUDED_BINARY_SEARCH_57_INSERT_INTERVAL
#define INCLUDED_BINARY_SEARCH_57_INSERT_INTERVAL

namespace leetcode {

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval)
  {
    using interval_t = std::vector<int>;

    auto l =
      std::lower_bound(intervals.begin(), intervals.end(),
                       interval_t{0, newInterval[0]},
                       [](const interval_t &x, const interval_t &y)
                       { return x[1] < y[1]; });

    auto r =
      std::upper_bound(intervals.begin(), intervals.end(),
                       interval_t{newInterval[1], INT_MAX});

    if (l != r)
    {
      newInterval[0] = std::min(newInterval[0], (*l)[0]);
      newInterval[1] = std::max(newInterval[1], (*std::prev(r, 1))[1]);
    }

    auto it = intervals.erase(l, r);
    intervals.insert(it, newInterval);

    return intervals;
  }
};

// 1. new interval is not overlap with intervals
// -----         -------
//        -----

// 2. new interval is overlap with intervals

// -----      --------
//    ------

// first interval of which end is greater than/equal to start of newInterval (i)
// first interval of which start is greater than end of newInterval (j)

// merge [i, j) with newInterval, later erase [i, j)

} // end namespace leetcode

#endif