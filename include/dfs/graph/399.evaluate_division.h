#ifndef INCLUDED_DFS_GRAPH_399_EVALUATE_DIVISION
#define INCLUDED_DFS_GRAPH_399_EVALUATE_DIVISION

namespace leetcode {

/** @brief calculate equation
 * You are given an array of variable pairs equations and
 * an array of real numbers values, where equations[i] = [Ai, Bi]
 * and values[i] represent the equation Ai / Bi = values[i].
 * Each Ai or Bi is a string that represents a single variable.
 *
 * You are also given some queries, where queries[j] = [Cj, Dj] represents
 * the jth query where you must find the answer for Cj / Dj = ?.
 *
 * Return the answers to all queries.
 * If a single answer cannot be determined, return -1.0.
 **/

class Solution {
public:
  std::vector<double> calcEquation(std::vector<std::vector<string>>& equations,
                                   std::vector<double>& values,
                                   std::vector<std::vector<std::string>>& queries)
  {
    // (equation[0], equation[1]) = value
    // creating a graph and using DFS algorithm to calculate the value

    // there is on trick that, we can convert string to integer,
    // then the map becomes a vector

    std::unordered_map<std::string, int> lookup;
    //                 ------------ ----
    //                  equation    index

    // maximum length of equations is 20
    // so the maximum lengths of unique equation is 40

    int MAX_EQ = 41;

    std::vector<std::vector<double>> graph(MAX_EQ,
                                           std::vector<double>(MAX_EQ, -1));

    for (auto i = 0; i != equations.size(); ++i)
    {
      auto &a = equations[i][0];
      auto &b = equations[i][1];

      auto ait = lookup.insert({a, lookup.size()});
      auto bit = lookup.insert({b, lookup.size()});

      graph[ait.first->second][bit.first->second] = values[i];
      graph[bit.first->second][ait.first->second] = 1.0/values[i];
    }

    std::vector<double> results(queries.size(), -1);

    std::vector<bool> visited(graph.size(), false);

    for (auto i = 0; i != queries.size(); ++i)
    {
      auto &a = queries[i][0];
      auto &b = queries[i][1];

      auto ait = lookup.find(a);
      auto bit = lookup.find(b);

      if (ait == lookup.end() || bit == lookup.end())
        continue;

      results[i] = dfs(ait->second, bit->second, graph, visited);
    }

    return results;
  }

private:

  double dfs(int src, int dst,
             std::vector<std::vector<double>> &graph,
             std::vector<bool> &visited)
  {
    if (src == dst)
      return 1.0;

    visited[src] = true;

    double ret = -1;

    for (auto i = 0; i != graph[src].size(); ++i)
    {
      if (graph[src][i] == -1 || visited[i]) // no edge or visited before
        continue;

      double value = dfs(i, dst, graph, visited);

      if (value == -1.0)
        continue;

      ret =  graph[src][i] * value;
      break;
    }

    visited[src] = false;

    return ret;
  }
};

} // end namespace leetcode

#endif