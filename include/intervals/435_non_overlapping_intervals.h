#ifndef INCLUDED_INTERVALS_435_NON_OVERLAPPING_INTERVALS
#define INCLUDED_INTERVALS_435_NON_OVERLAPPING_INTERVALS

namespace leetcode {

/** @brief: Non-overlapping Intervals
 *  Given an array of intervals intervals where intervals[i] = [starti, endi],
 *  return the minimum number of intervals you need to remove
 *  to make the rest of the intervals non-overlapping.
 **/

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    // let's sort by the endᵢ

    // if two intervals are overlapped with each other,
    // definitely we need delete one interval.

    //  who will we want to delete, Mr. Left or Mr. Right?
    // Supposed the probability of one interval to overlap with others is P(x)
    // P(left) <= P(right), since left.end <= right.end
    // So, right is what it should be deleted

    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &l, const std::vector<int> &r)
              {
                return l[1] < r[1];
              })

    int curr = intervals[0].back();

    int erase = 0;

    for (auto i = 1; i != intervals.size(); ++i)
    {
      if (intervals[i][0] >= curr)
        curr = intervals[i][1];
      else
        erase ++;
    }

    return erase;
  }
};


} // end namespace leetcode


#endif