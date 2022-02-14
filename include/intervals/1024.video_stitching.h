#ifndef INCLUDED_INTERVALS_1024_VIDEO_STITCHING
#define INCLUDED_INTERVALS_1024_VIDEO_STITCHING

namespace leetcode {

/** @brief: Video Stitching
 *  Return the minimum number of clips needed
 *  so that we can cut the clips into segments
 *  that cover the entire sporting event [0, time].
 *  If the task is impossible, return -1.
 **/

class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int time) {

    // we want to find the minimum number of clips that can cover [0, time]

    // there are two greedy criterion:
    // 1. need find at least one interval that is <= current start
    // 2. need filter those interval candidates <= current start to get
    //    longest overlap (largest right)

    if (clips.empty()) return -1;

    using video_t = std::vector<int>; // [start, end]

    std::sort(clips.begin(), clips.end(),
              [](const video_t &l, const video_t &r)
              {
                return l[0] < r[0];
              });

    int videos = 0;
    int curr = 0;

    int i = 0;
    while (i < clips.size() && curr < time)
    {
      // collect all interval of which clips[i][0] <= curr, and
      // get the maximum right
      int right = -1;

      while (i < clips.size() && clips[i][0] <= curr)
      {
        right = std::max(right, clips[i][1]);
        i++;
      }

      if (right == -1) // no available interval that can continue our work
        return -1;

      curr = right;
      videos ++;
    }

    return (curr >= time)? videos: -1;

  }
};

} // end namespace leetcode


#endif