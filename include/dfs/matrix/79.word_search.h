#ifndef INCLUDED_DFS_MATRIX_79_WORD_SEARCH
#define INCLUDED_DFS_MATRIX_79_WORD_SEARCH

namespace leetcode {

/** @brief word search
 *  Given an m x n grid of characters board and a string word,
 *  return true if word exists in the grid.
 *
 *  The word can be constructed from letters of sequentially adjacent cells,
 *  where adjacent cells are horizontally or vertically neighboring.
 *  The same letter cell may not be used more than once.
 **/

class Solution {
public:
  bool exist(std::vector<std::vector<char>>& board, std::string word)
  {
    // use dfs to check if word exists
    for (auto i = 0; i != board.size(); ++i)
      for (auto j = 0; j != board[i].size(); ++j)
        if (dfs(board, i, j, word))
          return true;

    return false;
  }

private:
  bool dfs(std::vector<std::vector<char>> &board,
           int r, int c,
           std::string &word,
           int pos = 0)
  {
    if (pos == word.size())
      return true;

    if (r < 0 || r >= board.size()    || // out of bound
        c < 0 || c >= board[r].size() || // out of bound
        board[r][c] != word[pos]       ) // not same
      return false;

    board[r][c] = '#';

    bool found = dfs(board, r+1, c, word, pos+1) |
                 dfs(board, r-1, c, word, pos+1) |
                 dfs(board, r, c-1, word, pos+1) |
                 dfs(board, r, c+1, word, pos+1) ;

    board[r][c] = word[pos];

    return found;
  }
};

} // end namespace leetcode

#endif