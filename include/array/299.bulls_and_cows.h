#ifndef INCLUDED_ARRAY_299_BULLS_AND_COWS
#define INCLUDED_ARRAY_299_BULLS_AND_COWS

namespace leetcode {

/** @brief: bulls and cows
 *  if secret[i] == guess[i], bulls++
 *  if secret[i] == guess[j] and i != j, cows++
 **/

class Solution {
public:
  string getHint(string secret, string guess) {

    // 1 2 0 0
    // 3 2 1 4
    // 1A1B

    // for secret, let's increment corresponding bucket
    // for guess,  let's decrement corresponding bucket
    // cache     0  1  2  3  4  5  6  7  8  9
    // 0th:         1    -1
    // 1st:
    // 2nd:      1  1-1

    std::vector<int> states(10, 0);

    int bulls = 0;
    int cows = 0;

    for (auto i = 0; i != secret.size(); ++i)
    {
      auto &s = secret[i];
      auto &g = guess[i];

      if (s == g)
        bulls ++;
      else
      {

        if (states[s-'0'] < 0)
          cows ++;

        if (states[g-'0'] > 0)
          ++cows;

        states[s-'0'] ++;
        states[g-'0'] --;
      }
    }

    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
  }
};

} // end namespace leetcode

#endif