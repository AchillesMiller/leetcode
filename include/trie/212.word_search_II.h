#ifndef INCLUDED_TRIE_212_WORD_SEARCH_II
#define INCLUDED_TRIE_212_WORD_SEARCH_II

namespace leetcode {

/** @brief: word search II
 *  Given an m x n board of characters and a list of strings words,
 *  return all words on the board.
 *
 *  Each word must be constructed from letters of sequentially adjacent cells,
 *  where adjacent cells are horizontally or vertically neighboring.
 *  The same letter cell may not be used more than once in a word.
 **/

class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // if finding one word, the time complexity is O(m*n*4^l),
    // where,
    //   m, n = board.shape() and l = len(word)
    // the time complexity of x words is O(x * m * n * 4 ^ l)

    // using a trie will reduce the time complexity to O(m*n*4^l)
    // where l is the maximum length of x words

    TrieNode * tree = generate_trie(words);

    std::vector<std::string> rets;
    rets.reserve(words.size());

    for (auto i = 0; i != board.size(); ++i)
      for (auto j = 0; j != board[i].size(); ++j)
        dfs(board, i, j, tree, rets);

    delete tree;

    return rets;
  }

private:
  struct TrieNode
  {
    TrieNode * next[26];
    std::string *str;

    TrieNode()
    {
      for (auto i = 0; i != 26; ++i)
        next[i] = nullptr;
      str = nullptr;
    }

    ~TrieNode()
    {
      for (auto i = 0; i != 26; ++i)
        delete this->next[i];
    }
  };

  TrieNode * generate_trie(std::vector<std::string> &words)
  {
    TrieNode *root = new TrieNode;

    for (auto &word: words)
    {
      auto it = root;

      for (auto &c: word)
      {
        if (!it->next[c-'a'])
          it->next[c-'a'] = new TrieNode;
        it = it->next[c-'a'];
      }

      it->str = &word;
    }

    return root;
  }

  void dfs(std::vector<std::vector<char>> &board,
           int r, int c,
           TrieNode *it,
           std::vector<std::string> &results)
  {
    if (r < 0 || r >= board.size()    ||  // out of bound
        c < 0 || c >= board[r].size() ||  // out of bound
        board[r][c] == '#'             )  // visited before
      return;

    auto &n = it->next[board[r][c]-'a'];

    if (!n) return; // not exists

    // visiting board
    auto bk = board[r][c];
    board[r][c] = '#';

    if (n->str)
    {
      results.push_back(*(n->str));
      n->str = nullptr;
    }

    dfs(board, r+1, c, n, results);
    dfs(board, r-1, c, n, results);
    dfs(board, r, c+1, n, results);
    dfs(board, r, c-1, n, results);

    board[r][c] = bk;
  }
};

} // end namespace leetcode

#endif