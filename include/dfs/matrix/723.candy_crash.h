#ifndef INCLUDED_DFS_MATRIX_723_CANDY_CRASH
#define INCLUDED_DFS_MATRIX_723_CANDY_CRASH

namespace leetcode {

class Solution {
public:
  vector<vector<int>> candyCrush(vector<vector<int>>& board) {

    while (crush(board))
      tetris(board);

    return board;
  }

private:

  using matrix_t = std::vector<std::vector<int>>;

  bool crush(matrix_t &mat)
  {
    int m = mat.size();
    int n = mat[0].size();

    bool crushed = false;

    // we want to starts with (i, j)

    for (auto i = 0; i != m; ++i)
      for (auto j = 0; j+2 < n; ++j)
        if (std::abs(mat[i][j]) == std::abs(mat[i][j+1])  &&
            std::abs(mat[i][j+1]) == std::abs(mat[i][j+2] ))
          mat[i][j] = mat[i][j+1] = mat[i][j+2] = - std::abs(mat[i][j]);

    for (auto j = 0; j != n; ++j)
      for (auto i = 0; i + 2 < m; ++i)
        if (std::abs(mat[i][j]) == std::abs(mat[i+1][j])  &&
            std::abs(mat[i+1][j]) == std::abs(mat[i+2][j] ))
          mat[i][j] = mat[i+1][j] = mat[i+2][j] = - std::abs(mat[i][j]);

    for (auto &r: mat)
      for (auto &c: r)
        if (c < 0)
        {
          crushed = true;
          c = 0;
        }

    return crushed;
  }

  void tetris(matrix_t &mat)
  {
    // for each column, we want fall down

    int m = mat.size();
    int n = mat[0].size();

    // 1 0 1 1
    // f     f
    // l   l

    for (auto c = 0; c != n; ++c)
    {
      int it = m-1;
      for (int r = m-1; r >= 0; --r)
      {
        if (mat[r][c] != 0)
        {
          std::swap(mat[r][c], mat[it][c]);
          --it;
        }
      }
    }
  }

};

} // end namespace leetcode

#endif