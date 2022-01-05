#ifndef INCLUDED_MAXIMUM_SWAP_670
#define INCLUDED_MAXIMUM_SWAP_670

#include <algorithm>
#include <string>


namespace leetcode {

class Solution {
public:
  /**
   * You are given an integer num.
   * You can swap two digits at most once to get the maximum valued number.
   *
   * Return the maximum valued number you can get.
   **/
  int maximumSwap(int num) {

    // this question can be interpreted as for each digit,
    // find the largest digit on the right

    // O(nlogn) time performance

    std::string s = std::to_string(num);

    // a non-ascending order vector acts a monotonic stack
    std::string t = s;
    std::sort(t.begin(), t.end(), std::greater<int>());

    int j = 0;

    for (auto i = 0; i != s.size(); ++i)
    {
      // find the largest digit on the right of i
      // if multiple exists, select the rightmost one

      if (s[i] == t[j]) // i is the largest, in anothe word, no larger one
                        // on the right
      {
        ++j;
        continue;
      }

      int k = s.size()-1;

      for (; k >= i+1; --k)
        if (s[k] == t[j]) // with the help of t, we know k is largest
          break;

      std::swap(s[i], s[k]);

      return stoi(s);
    }

    // nothing happens inside loop, return num itself
    return num;

  }
};

} // end namespace leetcode

#endif
