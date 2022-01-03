#ifndef INCLUDED_STRING_TWO_POINTERS_42_TRAPPING_RAIN_WATER
#define INCLUDED_STRING_TWO_POINTERS_42_TRAPPING_RAIN_WATER

#include <vector>

namespace leetcode {

class Solution {
public:
  int trap(std::vector<int>& height) {

    // for each index i, the water it can trap
    //  W(i) = (std::min(max_left_H, max_right_H)-H(i))
    // this function is quite clear

    int N = height.size();

    std::vector<int> lh(N, 0); // left max height

    lh[0] = 0;

    for (auto i = 1; i != height.size(); ++i)
      lh[i] = std::max(lh[i-1], height[i-1]);

    int water = 0;

    int rh = 0;

    for (int i = height.size()-2; i >= 0; --i)
    {
      rh = std::max(rh, height[i+1]);
      int H = std::min(lh[i], rh)-height[i];
      if (H < 0) continue;
      water += H;
    }

    return water;
  }

  int trap2(std::vector<int> &height) {
    // another solution is to use monotonic queue with descending height
    // when iterate to a height that is larger than the previous max height
    // two phenomena:
    //    1. the index of the last height in queue(pi) + 1 = current index(ci)
    //    2. set the H[pi] as the base and pop pi
    //    3. the index of the last height in queue is pi now
    //    4. trapped water += *std::min(H[ci], H[pi]) - base) * (ci-pi-1)
    //    repeating 2 - 4 until we can push back the current ci

    // height = [1 3 2 4 1]
    // ----------------------------------------------------------------------
    // operations                       monotonic stack of index
    // ------------------------------  --------------------------------------
    // push index 0                  : [0]
    // pop index 0, and push index 3 : [1] water+=[min(1, NIL)-base] * 0
    // push index 2                  : [1, 2]
    // pop index 2                   : [1] water += [min(4, 3)-2] * (3-1-1)
    // push index 1                  : [1, 4]
    // -----------------------------------------------------------------------
    // water = 1

    int N = height.size();

    std::vector<int> Q; // non ascending order
    Q.reserve(N);

    int water = 0;

    for (auto i = 0; i != N; ++i)
    {
      // 10 4 4 4 4 3 5
      // the last 4 should be kept in the queue, so it is non-ascending order

      while (!Q.empty() && height[Q.back()] < height[i])
      {
        auto &pi = Q.back();
        auto base = height[pi];

        Q.pop_back();

        if (!Q.empty())
          water += (std::min(height[i],height[Q.back()])-base) * (i-Q.back()-1);
          //        -----------------------------------------     ------------
          //                          height                          width
      }

      Q.push_back(i);
    }

    return water;
  }
};

} // end namespace leetcode

#endif