#ifndef INCLUDED_ARRAY_TWO_POINTERS_1423_MAXIMUM_POINTS_OBTAIN_FROM_CARDS
#define INCLUDED_ARRAY_TWO_POINTERS_1423_MAXIMUM_POINTS_OBTAIN_FROM_CARDS

#include <vector>

namespace leetcode {

/** @brief Maximum points you can obtain from cards
 *  There are several cards arranged in a row,
 *  and each card has an associated number of points.
 *  The points are given in the integer array cardPoints.
 *
 *  In one step, you can take one card from the beginning or
 *  from the end of the row. You have to take exactly k cards.
 *
 *  Your score is the sum of the points of the cards you have taken.
 *
 *  Given the integer array cardPoints and the integer k,
 *  return the maximum score you can obtain.
 **/

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

    int range_sum = 0;

    int min = std::accumulate(cards.begin(), cards.begin()+k, 0);

    int range = min;

    for (auto i = k; i != cards.size(); ++i)
    {
      range = range + cards[i] - cards[i-k];
      min = std::min(range, min);
    }
    return min;
  }
};

} // end namespace leetcode

#endif