#ifndef INCLUDED_DIJKSTRA_787_CHEAPEST_FLIGHTS_WITH_K_STOPS
#define INCLUDED_DIJKSTRA_787_CHEAPEST_FLIGHTS_WITH_K_STOPS

#include <vector>

namespace leetcode {

/** @brief: cheapest flights with k stops
 *  There are n cities connected by some number of flights.
 *  You are given an array flights where flights[i] = [from, to, price]
 *  indicates there is a flight from city from to city toi with cost price.
 **/

class Solution {
public:
  int findCheapestPrice(int n,
                        std::vector<std::vector<int>>& flights,
                        int src, int dst, int k)
  {
    // find the cheapest price from src to dst within k stops

    // from one point to another point, find the minimum cost.
    // that is dijistra problem
    // time complexity of dijistra is O(E) + O(VlogV)

    // PSEUDO CODE of DIJISTRA:
    //   1. find node with minimum cost(distance)
    //   2. push neighbors into heap
    // repeating 1 and 2, till we find the destination,
    // it is guaranteed that distance of destination is smallest.

    // pruning, have a 1d array to record minimum distance from src to i
    // when pushing i, if distance previous visited is smaller, won't push

    // but for this question, since there is one more requirement that within
    // k stops, we need different pruning criteria that, if i is popped before,
    // and stops is less than current one, prevent pushing

    // 1. construct adjacent matrix
    std::vector<std::vector<int>> prices(n+1, std::vector<int>(n+1, INT_MAX));

    for (auto &flight: flights)
    {
      auto &x = flight[0];
      auto &y = flight[1];
      auto &p = flight[2];
      prices[x][y] = p;
    }

    std::vector<int> tickets(n+1, INT_MAX); // if city was visited, record
                                            // how many tickets i used

    // at most k stops, it is equal to at most k+1 tickets
    std::priority_queue<flight_t, std::vector<flight_t>, greater> Q;
    Q.push({0, src, 0}); // it takes 0 cost to arrive src with 0 ticket

    while (!Q.empty())
    {
      auto curr = Q.top();
      Q.pop();

      auto &cost = curr[0];
      auto &city = curr[1];
      auto &ticket = curr[2];

      if (city == dst)
        return cost;

      // first pruning
      if (ticket == k + 1) // we'v taken k+1 flights already
        continue;

      // city is visited in `ticket`, record it
      tickets[city] = std::min(tickets[city], ticket);

      // adjacent
      for (auto i = 0; i != prices[city].size(); ++i)
      {
        if (prices[city][i] == INT_MAX) // no flight between city and i
          continue;

        // second pruning
        if (ticket + 1 >= tickets[i]) // city i was visited before with less
                                      // ticket, based on dijistra algorithm
                                      // that distance is smaller than later
          continue;

        Q.push({prices[city][i] + cost, i, ticket + 1});
      }
    }

    // there is no available flight between src and dst
    return -1;
  }

private:
  using flight_t = std::vector<int>; // cost, city, tickets

  struct greater
  {
    bool operator()(const flight_t &l, const flight_t &r) const
    {
      return l[0] > r[0];
    }
  };

};

} // end namespace leetcode

#endif