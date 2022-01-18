#ifndef INCLUDED_MONOTONIC_QUEUE_84_LARGEST_RECTANGLE_IN_HISTOGRAM
#define INCLUDED_MONOTONIC_QUEUE_84_LARGEST_RECTANGLE_IN_HISTOGRAM

#include <vector>

namespace leetcode {

class Solution {
public:
  int largestRectangleArea(std::vector<int>& heights)
  {
    // brute force, one height will be selected as height
    // so, for index i, find last heights[l] that is less than heights[i]
    //                  find next heights[r] that is less than heights[i]
    // area = heights[i] * (r-1 - (l+1) + 1) = heights[i] * (r-l-1)

    // so, when iterating j, if heights[j] < stack.back()
    // stack.back is popped, and if this index is selected
    // H[stack.back()] * (i-1 - (stack.back().back()+1) + 1)

    heights.reserve(heights.size() + 2);

    heights.insert(heights.begin(), -1);
    heights.push_back(-1);

    std::vector<int> Q;
    Q.reserve(heights.size());

    int max_area = -1;

    for (auto i = 0; i < heights.size(); ++i)
    {
      while (!Q.empty() && heights[Q.back()] > heights[i])
      {
        int H = heights[Q.back()];
        Q.pop_back();

        int r = i-1;
        int l = Q.back()+1;

        int W = r-l+1;

        max_area = std::max(max_area, W*H);
      }

      Q.push_back(i);
    }

    return max_area;
  }
};

} // end namespace leetcode

#endif
