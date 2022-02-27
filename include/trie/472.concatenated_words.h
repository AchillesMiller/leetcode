#ifndef INCLUDED_TRIE_472_CONCATENATED_WORDS
#define INCLUDED_TRIE_472_CONCATENATED_WORDS

namespace leetcode {

/** @brief: concatenated words
 *  Given an array of strings words (without duplicates),
 *  return all the concatenated words in the given list of words.
 *
 *  A concatenated word is defined as a string that is comprised entirely
 *  of at least two shorter words in the given array.
 **/

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

    // generate trie from words
    // time cost is O(m) for each insert, m is word.size()
    // and, each search is O(m) also

    // in total, the time cost is O(m * n), which n is words.size()

    // [search] for current trie, use dfs to find if there exists a
    //          concatenate candidate
    // [insert] add word to current trie, and assign is_end=true for the last
    //          tire node

    std::sort(words.begin(), words.end(),
              [](const std::string &l, const std::string &r)
              {
                return l.size() < r.size();
              });

    TrieNode * tree = new TrieNode;

    std::vector<std::string> concatenated;
    concatenated.reserve(words.size());

    for (auto &word: words)
    {
      if (search(tree, word))
        concatenated.push_back(word);

      insert(tree, word);
    }

    return concatenated;
  }

private:

  struct TrieNode
  {
    bool is_end;
    TrieNode *next[26];

    TrieNode(): is_end(false)
    {
      for (auto i = 0; i != 26; ++i)
        next[i] = nullptr;
    }
  };

  // use dfs to search
  bool search(TrieNode *tree, const std::string & word, int curr=0)
  {
    if (word.empty())
      return false;

    if (curr == word.size() && tree)
      return true;

    auto it = tree;

    while (it && curr < word.size())
    {
      it = it->next[word[curr++]-'a'];

      if (!it)
        return false;

      if (it->is_end && search(tree, word, curr))
        return true;
    }

    return false;
  }

  void insert(TrieNode *tree, const std::string &word)
  {
    auto it = tree;

    for (auto i = 0; i != word.size(); ++i)
    {
      if (!it->next[word[i]-'a'])
        it->next[word[i]-'a'] = new TrieNode;

      it = it->next[word[i]-'a'];
    }

    it->is_end = true;
  }

};

}

#endif