#ifndef INCLUDED_BINARY_SEARCH_74_SEARCH_A_2D_MATRIX
#define INCLUDED_BINARY_SEARCH_74_SEARCH_A_2D_MATRIX

namespace leetcode {

/** @brief search a 2d matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:

   - Integers in each row are sorted from left to right.
   - The first integer of each row is greater than the last integer
     of the previous row.
 */

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // binary search can solve this problem
    // so,
    // for row-wide, find the first row of which front is greater than
    // target
    // for column-wide, find first column of which value is greater than/equal to
    // target

    auto rit =
      std::upper_bound(matrix.begin(), matrix.end(),
                       std::vector<int>(1, target), less());

    if (rit == matrix.begin())
      return false;

    rit = std::prev(rit, 1);

    auto &row = *rit;

    auto it = std::lower_bound(row.begin(), row.end(), target);

    if (it != row.end() && *it == target)
      return true;

    return false;
  }

private:
  struct less
  {
    bool operator()(const std::vector<int> &l, const std::vector<int> &r) const
    {
      return l.front() < r.front();
    }
  };

};

} // end namespace leetcode

#endif