#ifndef INCLUDED_ARRAY_TWO_POINTERS_1423_MAXIMUM_POINTS_OBTAIN_FROM_CARDS
#define INCLUDED_ARRAY_TWO_POINTERS_1423_MAXIMUM_POINTS_OBTAIN_FROM_CARDS

#include <vector>

namespace leetcode {

class Solution {
public:
  int maxScore(std::vector<int>& cardPoints, int k) {

    // select k cards from either front and back
    // supposed there is n cards
    // it is equal to find a subarray with length n-k of which sum is minimal

    int n = cardPoints.size();

    int sum = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
    return sum - minScore(cardPoints, n-k);
  }

private:
  int minScore(std::vector<int> &cards, int k)
  {
    if (k <= 0)
      return 0;

    // pre-sums
    for (auto i = 1; i != cards.size(); ++i)
      cards[i] += cards[i-1];

    // cards[i]: sum of range [0, i]
    // so, subarray[i, i + k - 1] is what we want to check
    //  = cards[i+k-1] - cards[i-1]
    //  = cards[j] - cards[j-k]

    int min = cards[k-1];

    for (auto j = k; j != cards.size(); ++j)
      min = std::min(min, cards[j] - cards[j-k]);

    return min;
  }
};

} // end namespace leetcode

#endif