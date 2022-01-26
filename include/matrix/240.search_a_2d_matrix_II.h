#ifndef INCLUDED_MATRIX_240_SEARCH_A_2D_MATRIX
#define INCLUDED_MATRIX_240_SEARCH_A_2D_MATRIX

#include <vector>

namespace leetcode {

/** @brief: Search A 2D Matrix
 * Write an efficient algorithm that searches
 * for a target value in an m x n integer matrix.
 * The matrix has the following properties:

   - Integers in each row are sorted in ascending from left to right.
   - Integers in each column are sorted in ascending from top to bottom.
**/

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
  {
    // for target, starting from bottom left,
    //   1. find last row that is less than/equal to target
    //   2. find first column that is greater than/equal to target

    int m = matrix.size();
    int n = matrix[0].size();

    // starting from (m-1, 0)
    int r = m-1;
    int c = 0;

    while (r >= 0 && c < n)
    {
      if (matrix[r][c] == target)
        return true;

      // find last row that [r][c] is less than/equal to target
      while (r >= 0 && matrix[r][c] > target)
        --r;

      if (r < 0)
        break;

      // first first column that [r][c] is greater than/equal to target
      // it can be replaced with

      // it = std::lower_bound(matrix[r].begin() + c, matrix[r].end(), target);
      // c = it - matrix[r].begin()

      while (c < n && matrix[r][c] < target)
        ++c;
    }

    return false;
  }
};

} // end namespace leetcode

#endif