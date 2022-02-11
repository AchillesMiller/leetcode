#ifndef INCLUDED_DESIGN_304_RANGE_SUM_QUERY_2D_IMMUTABLE
#define INCLUDED_DESIGN_304_RANGE_SUM_QUERY_2D_IMMUTABLE

namespace leetcode {

/** @brief: Range Sum Query 2D Immutable
 *  Given a 2D matrix matrix, handle multiple queries of the following type:
 *
 *  Calculate the sum of the elements of matrix
 *  inside the rectangle defined by its upper left corner (row1, col1)
 *  and lower right corner (row2, col2).
 **/

class NumMatrix {

std::vector<std::vector<int>> _sums;

public:
  NumMatrix(vector<vector<int>>& matrix)
  : _sums(matrix)
  {
    int m = _sums.size();
    int n = _sums[0].size();

    for (auto j = 1; j != n; ++j)
      _sums[0][j] += _sums[0][j-1];

    for (auto i = 1 ; i != m; ++i)
    {
      int sum = 0;

      for (auto j = 0; j != n; ++j)
      {
        sum += _sums[i][j];
        _sums[i][j] = sum + _sums[i-1][j];
      }
    }
  }

  // [row1, row2]
  // [col1, col2]
  int sumRegion(int row1, int col1, int row2, int col2)
  {

    if (row2 < 0 || col2 < 0)
      return 0;

    int sum = _sums[row2][col2];

    sum -= sumRegion(0, 0, row1-1, col1-1);   // top left
    sum -= sumRegion(0, col1, row1-1, col2); // top
    sum -= sumRegion(row1, 0, row2, col1-1); // left

    return sum;
  }
};

} // end namespace leetcode

#endif
