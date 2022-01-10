#ifndef INCLUDED_PALINDROME_DP_PALINDROME_PARTITIONING_131
#define INCLUDED_PALINDROME_DP_PALINDROME_PARTITIONING_131

#include <string>
#include <vector>

namespace leetcode {

class Solution {
public:
  std::vector<std::vector<std::string>> partition(std::string s)
  {
    // find all possible palindrome partitions

    // DFS is the main algorithm to use, single partition and partitions are
    // passed as references to DFS method

    // but to check if one range [i, j) is palindrome, it fits dynamic
    // programming algorithm

    int N = s.size();
    // palindromes[i][j]: range [i, j] is palindrome

    std::vector<std::vector<bool>> palindromes(N, std::vector<bool>(N, false));
    find_palindromes(s, palindromes);

    partition_t p;
    partitions_t ps;

    partition(s, palindromes, 0, p, ps);

    return ps;
  }

private:
  using partition_t  = std::vector<std::string>;
  using partitions_t = std::vector<partition_t>;

  // dynamic programming to find all palindrome substring
  void find_palindromes(const std::string &s,
                        std::vector<std::vector<bool>> &palindromes)
  {
    int N = s.size();

    for (auto r = 0; r != N; ++r)   // r]
      for (int l = r; l >= 0; --l)  // [l
        if (s[l] == s[r])
          palindromes[l][r] = (r-l <= 1 || palindromes[l+1][r-1]);
  }

  // dfs and back-tracing
  void partition(const std::string &s,
                 const std::vector<std::vector<bool>> &palindromes,
                 int i,
                 partition_t &p,
                 partitions_t &ps)
  {
    if (i == s.size())
    {
      ps.push_back(p);
      return;
    }

    for (auto j = i; j != s.size(); ++j)
    {
      if (!palindromes[i][j])
        continue;

      p.push_back(s.substr(i, j-i+1));       // back-tracing
      partition(s, palindromes, j+1, p, ps); // DFS
      p.pop_back();
    }
  }
};

} // end namespace leetcode


#endif