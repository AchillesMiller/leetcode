#ifndef INCLUDED_TOPOLOGICAL_SORT_ALIEN_DICTIONARY_269
#define INCLUDED_TOPOLOGICAL_SORT_ALIEN_DICTIONARY_269

#include <vector>
#include <string>
#include <deque>

namespace leetcode {

class Solution {
public:
  /**
   * @brief alien order
   * words is the alien dictionary, get correct lexicographically order
   **/
  std::string alienOrder(std::vector<std::string>& words) {

    auto index = [](char &c ) -> int
    {
      return c-'a';
    };

    // in-degrees
    std::vector<int> ins(26, -1);
    graph_t g(26, std::vector<bool>(26, false));

    // only character appears in the words is meaningful
    for (auto &w: words)
      for (auto &c: w)
        ins[index(c)] = 0;

    for (auto i = 1; i != words.size(); ++i)
    {
      auto &curr = words[i];
      auto &prev = words[i-1];

      // abc and ab, it is not a correct lexicographically order
      if (prev.size() > curr.size() && prev.find(curr) == 0)
        return "";

      for (auto k = 0; k != std::min(curr.size(), prev.size()); ++k)
        if (curr[k] != prev[k])
        {
          // it is important to check if prev[k]->curr[k] is recorded or not
          // to avoid incorrectness of in-degrees
          if (!g[index(prev[k])][index(curr[k])])
          {
            g[index(prev[k])][index(curr[k])] = true;
            ins[index(curr[k])] ++;
          }
          break;
        }
    }


    return topological_sort(g, ins);
  }

private:

  using graph_t = std::vector<std::vector<bool>>;

  // typical topological sort
  std::string topological_sort(const graph_t &g, std::vector<int> &ins)
  {
    int count = 0;
    for (auto &x: ins)
      if (x != -1)
        ++count;

    std::string order;
    order.reserve(ins.size());

    std::deque<int> Q;

    for (auto i = 0; i != ins.size(); ++i)
      if (ins[i] == 0)
        Q.push_back(i);

    while (!Q.empty())
    {
      int size = Q.size();

      while (size -- > 0)
      {
        auto curr = Q.front();
        Q.pop_front();

        order.append(1, curr+'a');

        for (auto i = 0; i != 26; ++i)
          if (g[curr][i]  && // curr -> i
              --ins[i] == 0) // no input edges anymore
            Q.push_back(i);
      }
    }

    if (order.size() == count)
      return order;

    return "";
  }

};

} // end namespace leetcode

#endif
