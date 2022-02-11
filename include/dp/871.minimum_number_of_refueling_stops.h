#ifndef INCLUDED_DP_871_MINIMUM_NUMBER_OF_REFUELING_STOPS
#define INCLUDED_DP_871_MINIMUM_NUMBER_OF_REFUELING_STOPS

#include <vector>
#include <queue>

namespace leetcode {

/** @brief: minimum number of refueling stops
 *  station = []

class Solution {
public:
  int minRefuelStops(int target, int startFuel,
                     std::vector<std::vector<int>>& stations)
  {
    // this question can be solved by either dp or a priority_queue

    return min_refuel_stops_sort(target, startFuel, stations);
  }

private:
  using stations_t = std::vector<std::vector<int>>;

  int min_refuel_stops_dp(int target, int startFuel, stations_t &stations)
  {
    // * ........ 1 ........ 2 ...................3 .............. target
    //                      🚗
    // when car arrives at station 2,  we can either choose 0 stop, 1 stops and
    // 2 stops.

    // dp[i] = the maximum miles we can arrive if stop i times
    // for station j, the dp[i] = std::max(dp[i], dp[i-1] + fuels of station j)
    // we need update the dp in reversed order [j, 0] for station j

    // so, at each station i, the dp[0, 1, ... i] will be updated

    // and dp[0] = startFuel
    //     dp[1] = std::max(dp[0] + fuels of station2, dp[1])
    //                      -------------------------  -------
    //                        only if it can arrive    previous calculation

    // the dp[0: target] is kept updating

    int n = stations.size();

    std::vector<long> dp(n+1, 0);
    // if there is n stations, we can have 0, 1, 2, 3, .... n solutions

    dp[0] = startFuel;

    for (auto i = 1; i <= n; ++i)
      for (auto j = i; j >= 1; ++j)
      {
        if (dp[j-1] < stations[i-1][0])
          // choose j-1 before cannot arrive at this station
          // and choose j-2 definitely cannot arrive this stations
          break;
        dp[j] = std::max(dp[j-1] + stations[i-1][1], dp[j]);
      }

    for (auto i = 0; i != dp.size(); ++i)
      if (dp[i] >= target)
        return i;

    return -1;
  }

  int min_refuel_stops_sort(int target, int startFuel, stations_t &stations)
  {
    // fuel      100        20
    // * ........ 1 ........ 2 ...................3 .............. target
    //                         🚗
    // if the car arrived there, and cannot reach out to 3
    // the greedy algorithm is to choose fuel in station 1
    // if we can still not arrive station 3, we choose 2

    stations.push_back({target, 0});

    std::priority_queue<int> fuels;

    int curr = startFuel;
    int stops = 0;

    for (auto i = 0; i != stations.size(); ++i)
    {
      while (curr < stations[i][0] && !fuels.empty())
      {
        curr += fuels.top();
        fuels.pop();
        ++stops;
      }

      if (curr < stations[i][0])
        return -1;

      if (curr >= target)
        return stops;

      fuels.push(stations[i][1]);
    }

    return -1;
  }

};


}


#endif