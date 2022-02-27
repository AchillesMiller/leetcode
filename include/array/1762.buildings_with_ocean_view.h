#ifndef INCLUDED_ARRAY_1762_BUILDINGS_WITH_OCEAN_VIEW
#define INCLUDED_ARRAY_1762_BUILDINGS_WITH_OCEAN_VIEW

namespace leetcode {

/** @brief: Buildings With an Ocean Views
 *  return a list of indices of buildings that have an ocean views
 **/

class Solution {
public:
  vector<int> findBuildings(vector<int>& heights) {

    // from right to left
    // if the current building is highest so far, we want to store it

    std::vector<int> buildings;
    buildings.reserve(heights.size());

#if 0
    for (int i = heights.size()-1; i >= 0; --i)
      if (buildings.empty() || heights[buildings.back()] < heights[i])
        buildings.push_back(i);

    std::reverse(buildings.begin(), buildings.end());

#else // monotonic queue

    for (auto i = 0; i != heights.size(); ++i)
    {
      while(!buildings.empty() && heights[buildings.back()] <= heights[i])
        buildings.pop_back();

      buildings.push_back(i);
    }

#endif
    return buildings;
  }
};

} // end namespace leetcode

#endif