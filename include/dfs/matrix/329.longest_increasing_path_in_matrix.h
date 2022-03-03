#ifndef INCLUDED_DFS_MATRIX_329_LONGEST_INCREASING_PATH_IN_A_MATRIX
#define INCLUDED_DFS_MATRIX_329_LONGEST_INCREASING_PATH_IN_A_MATRIX

namespace leetcode {

/** @brief: longest increasing path in a matrix
 *  Given an m x n integers matrix,
 *  return the length of the longest increasing path in matrix.
 *
 *  From each cell, you can either move in four directions:
 *      left, right, up, or down.
 *  You may not move diagonally or move outside the boundary
 *  (i.e., wrap-around is not allowed).
 **/

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    // lip[i][j]: longest increasing path ended in (i, j)
    // lip[i][j] = lip[i'][j'] + 1
    // where matrix[i'][j'] > matrix[i][j] and lip[i'][j'] is greatest

    std::vector<std::vector<int>> lip(m, std::vector<int>(n, -1));

    int max = 1;

    for (auto i = 0; i != m; ++i)
      for (auto j = 0; j != n; ++j)
        max = std::max(max, dfs(matrix, i, j, lip));

    return max;
  }

private:
  int dfs(std::vector<std::vector<int>> &m,
          int i, int j,
          std::vector<std::vector<int>> &cache)
  {
    if (cache[i][j] != -1)
      return cache[i][j];

    cache[i][j] = 1;

    int bk = m[i][j]; // this is for fun, if we want to get the longest
                      // non-descending len, this is a choice
    m[i][j] = INT_MAX;

    static const std::vector<std::pair<int, int>> ds = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}
    };

    for (auto &d: ds)
    {
      int r = i + d.first;
      int c = j + d.second;

      if (r < 0 || r >= m.size()    ||
          c < 0 || c >= m[r].size() ||
          bk <= m[r][c]              )
        continue;

      cache[i][j] = std::max(cache[i][j], dfs(m, r, c, cache)+1);
    }

    m[i][j] = bk;

    return cache[i][j];
  }

};

} // end namespace leetcode

#endif