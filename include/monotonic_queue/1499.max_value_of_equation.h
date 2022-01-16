#ifndef INCLUDED_MONOTONIC_QUEUE_1499_MAX_VALUE_OF_EQUATION
#define INCLUDED_MONOTONIC_QUEUE_1499_MAX_VALUE_OF_EQUATION

#include <vector>

namespace leetcode {

class Solution {
public:
  int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k)
  {
    // for a sorted points in ascending order of point.x
    // find largest yᵢ + yⱼ + | xᵢ - xⱼ | where i < j and | xᵢ - xⱼ | <= k
    // -> largest yᵢ - xᵢ + yⱼ + xⱼ
    // we always want to find the largest yᵢ - xᵢ previously

    // so, we can maintain a deque to record the largest yᵢ - xᵢ

    int max_eq = std::numeric_limits<int>::min();

    std::deque<int> maximums; // a double linked queue of indices
                              // points[index} is in non-ascending order

    auto y_minus_x = [](const std::vector<int> &p) -> int
    {
      return p[1] - p[0];
    };

    for (int j = 0; j != points.size(); ++j)
    {
      auto value = y_minus_x(points[j]);

      // removing all invalid solution
      while (!maximums.empty()                            &&
             points[j][0] - points[maximums.front()][0] > k)
        maximums.pop_front();

      if (!maximums.empty())
      {
        auto &i = maximums.front();
        max_eq = std::max(max_eq,
                          points[j][0] + points[j][1] + y_minus_x(points[i]));
      }

      // pushing j
      while (!maximums.empty()                        &&
             y_minus_x(points[maximums.back()]) < value) // < instead of <=
        maximums.pop_back();

      maximums.push_back(j);
    }

    return max_eq;
  }
};

} // end namespace leetcode


#endif