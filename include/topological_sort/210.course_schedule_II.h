#ifndef INCLUDED_TOPOLOGICAL_SORT_210_COURSE_SCHEDULE_II
#define INCLUDED_TOPOLOGICAL_SORT_210_COURSE_SCHEDULE_II

namespace leetcode {

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // it is obvious to be a topological sort

     std::vector<int> indegrees(numCourses, 0);

    using graph_t = std::vector<std::vector<int>>;

    graph_t G(numCourses);

    for (auto &edge: prerequisites)
    {
      auto &a = edge[0];
      auto &b = edge[1];

      indegrees[b] ++;

      G[a].push_back(b);
    }

    std::deque<int> Q;

    for (auto i = 0; i != indegrees.size(); ++i)
      if (indegrees[i] == 0)
        Q.push_back(i);

    std::vector<int> orders;
    orders.reserve(numCourses);

    while (!Q.empty())
    {
      int size = Q.size();

      while (size-- > 0)
      {
        auto curr = Q.front();
        Q.pop_front();

        orders.push_back(curr);

        for (auto &next: G[curr])
          if (--indegrees[next] == 0)
            Q.push_back(next);
      }
    }

    std::reverse(orders.begin(), orders.end());

    return (orders.size() == numCourses)? orders: std::vector<int>{};
  }
};

} // end namespace leetcode

#endif