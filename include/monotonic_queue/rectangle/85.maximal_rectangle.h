#ifndef INCLUDED_MONOTONIC_QUEUE_85_MAXIMAL_RECTANGLE
#define INCLUDED_MONOTONIC_QUEUE_85_MAXIMAL_RECTANGLE

#include <vector>

namespace leetcode {

class Solution {
public:
  int maximalRectangle(std::vector<std::vector<char>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    // iterating every row, and get the heights,

    int max_area = -1;

    std::vector<int> heights(n+2, 0); // with -1 and -1 in front and back

    heights[0] = -1;
    heights.back() = -1;

    for (auto i = 0; i != m; ++i)
    {
      for (auto j = 0; j != n; ++j)
      {
        if (matrix[i][j] == '0')
          heights[j+1] = 0;
        else
          heights[j+1] += 1;
      }

      max_area = std::max(max_area, maximal_rectangle_of_histogram(heights));
    }

    return max_area;
  }

private:
  int maximal_rectangle_of_histogram(std::vector<int> &heights)
  {
    // brute force, one height will be selected as height
    // so, for index i, find last heights[l] that is less than heights[i]
    //                  find next heights[r] that is less than heights[i]
    // area = heights[i] * (r-1 - (l+1) + 1) = heights[i] * (r-l-1)

    // so, when iterating j, if heights[j] < stack.back()
    // stack.back is popped, and if this index is selected
    // H[stack.back()] * (i-1 - (stack.back().back()+1) + 1)

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