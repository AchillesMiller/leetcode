#ifndef INCLUDED_BFS_127_WORD_LADDER
#define INCLUDED_BFS_127_WORD_LADDER

namespace leetcode {

/** @brief: Word Ladder
 *  Given two words, beginWord and endWord, and a dictionary wordList,
 *  return the number of words in the shortest transformation sequence
 *  from beginWord to endWord, or 0 if no such sequence exists.
 **/

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    // find the shortest sequence, bfs to solve the problem
    std::unordered_map<std::string, int> m;
    //                 -----------  ---
    //                   word       1/2
    m.reserve(wordList.size()+1);

    for (auto &word: wordList)
      m[word] = 0;

    if (m.find(endWord) == m.end())
      return 0;

    std::deque<std::string> top;
    top.push_back(beginWord);
    m[beginWord] = 1;

    std::deque<std::string> bottom;
    bottom.push_back(endWord);
    m[endWord] = 2;

    int len1 = 1;
    int len2 = 1;

    while (!top.empty() && !bottom.empty())
    {
      // step on the next layer
      if (step(top, m, 1, 2))
        return len1 + len2;

      ++len1;

      if (step(bottom, m, 2, 1))
        return len1 + len2;

      ++len2;
    }

    return 0;
  }

private:
  bool step(std::deque<std::string> &q,
            std::unordered_map<std::string, int> &m,
            int start,
            int end)
  {
    int size = q.size();

    while (size -- > 0)
    {
      auto curr = q.front();
      q.pop_front();

      for (auto &c: curr)
        for (auto x = 'a'; x <= 'z'; ++x)
        {
          std::swap(c, x);

          auto it = m.find(curr);

          if (it != m.end())
          {
            if (it->second == 0) // good to step on
            {
              q.push_back(it->first);
              it->second = start;
            }
            else if (it->second == end)
              return true;
          }

          std::swap(c, x);
        }
    }

    return false;
  }
};

} // end namespace leetcode


#endif