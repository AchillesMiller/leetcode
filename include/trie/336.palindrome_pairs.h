#ifndef INCLUDED_TRIE_336_PALINDROME_PAIRS
#define INCLUDED_TRIE_336_PALINDROME_PAIRS

namespace leetcode {

/** @brief: Palindrome Pairs
 *  Given a list of unique words,
 *  return all the pairs of the distinct indices (i, j) in the given list,
 *  so that concatenation of the two words words[i] + words[j] is a palindrome.
 **/

// each node will cache the index of word of which remaining part is palindrome

class Solution {
public:
  std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words)
  {
    // a trie can solve this problem
    // 1, 2
    // 3, 2, 1  -> in tree, it is 1->2->3

    // 1 2 3
    // 2 1      -> in tree, it is 1->2

    // the trie maintains a postfix order,
    // there are two scenarios
    // for first case, the iterator ended in 2,
    //   and 2 node also store an index array telling which word's remaining
    //   is palindrome
    // for the second case, the iterator ended in 2 also,
    //   and, 1->2->3 is not finished yet, so, check if remaining 3 is palindrome

    TrieNode * postfix = generate_trie(words);

    std::vector<std::vector<int>> pairs;
    pairs.reserve(words.size() * (words.size()-1));

    for (auto i = 0; i != words.size(); ++i)
    {
      auto &word = words[i];

      int j = 0;

      auto it = postfix; // word[-1]

      for (; j < word.size(); ++j)
      {
        // [0, j-1] has one path
        if (it->index != -1 && it->index != i &&
            is_palindrome(word, j, word.size()-1))
          pairs.push_back({i, it->index});

        it = it->next[word[j]-'a'];

        // there is no road anymore for word[j]
        if (!it) break;
      }

      if (j == word.size()) // went through the word, some long word(s) may match
      {
        assert (it);

        for (auto &ind: it->indices) // indices is the word indices of which
                                     // the remaining is palindrome
          if (i != ind)
            pairs.push_back({i, ind});
      }
    }

    return pairs;
  }

private:
  bool is_palindrome(const std::string &s, int l, int r)
  {
    while (l < r)
      if (s[l++] != s[r--])
        return false;

    return true;
  }

  struct TrieNode
  {
    int index;                // index of word ended here
    std::vector<int> indices; // index of word of which remaining is palindrome
    TrieNode * next[26];      // next

    TrieNode() : index(-1), indices()
    {
      for (auto i = 0; i != 26; ++i)
        next[i] = nullptr;
    }
  };

  TrieNode * generate_trie(const std::vector<std::string> &words)
  {
    TrieNode *root = new TrieNode;

    for (auto i = 0; i != words.size(); ++i)
    {
      auto it = root;
      auto &word = words[i];

      for (int j = word.size()-1; j >= 0; --j)
      {
        if (is_palindrome(word, 0, j))
          it->indices.push_back(i); // put it in the above node of word[j]

        if (!it->next[word[j]-'a'])
          it->next[word[j]-'a'] = new TrieNode;

        it = it->next[word[j]-'a'];
      }

      it->index = i;
      it->indices.push_back(i);
    }

    return root;
  }


};

} // end namespace leetcode

#endif