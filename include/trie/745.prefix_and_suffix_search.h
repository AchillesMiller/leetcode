#ifndef INCLUDED_TRIE_745_PREFIX_AND_SUFFIX_SEARCH
#define INCLUDED_TRIE_745_PREFIX_AND_SUFFIX_SEARCH

namespace leetcode {

/** @brief: Design a special dictionary with some words that searches
 *          the words in it by a prefix and a suffix.
 **/

// prefix and suffix
// so, we want to search the word satisfies (prefix, suffix)

// brute force, query: O(N * (max(prefix) + max(suffix)))

// how to improve the query?
// it is ok to improve to O(max(prefix)+max(postfix)) using trie
// and, it need O(N* K *K) memory


class WordFilter {
public:
  WordFilter(vector<string>& words)
  : _tree(generate_trie(words))
  {}

  int f(string prefix, string suffix) {
    std::reverse(suffix.begin(), suffix.end());
    std::string x = prefix.append(1, 'a'+26).append(suffix);
    return query_trie(x);
  }

private:
  struct TrieNode
  {
    int index; // word index

    TrieNode *next[27];

    TrieNode(): index(-1)
    {
      for (auto i = 0; i != 27; ++i)
        next[i] = nullptr;
    }
  };

  TrieNode *_tree;

  TrieNode *generate_trie(const std::vector<std::string> &words)
  {
    TrieNode *root = new TrieNode;

    for (auto i = 0; i != words.size(); ++i)
    {
      auto &word = words[i];

      auto it = root;

      // prefix [0: j]
      for (auto j = 0; j != word.size(); ++j)
      {
        if (!it->next[word[j]-'a'])
          it->next[word[j]-'a'] = new TrieNode;
        it = it->next[word[j]-'a'];

        auto suffix_it = it;
        if (!suffix_it->next[26])
          suffix_it->next[26] = new TrieNode;

        suffix_it = suffix_it->next[26];

        for (int k = word.size()-1; k >= 0; --k)
        {
          if (!suffix_it->next[word[k]-'a'])
            suffix_it->next[word[k]-'a'] = new TrieNode;
          suffix_it = suffix_it->next[word[k]-'a'];
          suffix_it->index = std::max(suffix_it->index, i);
        }
      }
    }

    return root;
  }

  int query_trie(std::string &x)
  {
    auto it = _tree;

    for (auto &c: x)
    {
      it = it->next[c-'a'];
      if (!it)
        break;
    }

    return it? it->index: -1;
  }

};

} // end namespace leetcode


#endif