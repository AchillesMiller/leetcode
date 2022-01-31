#ifndef INCLUDED_TOPOLOGICAL_SORT_207_COURSE_SCHEDULE
#define INCLUDED_TOPOLOGICAL_SORT_207_COURSE_SCHEDULE

namespace leetcode {

/** @brief: course schedule
  * There are a total of numCourses courses you have to take,
  * labeled from 0 to numCourses - 1. You are given an array prerequisites
  * where prerequisites[i] = [ai, bi] indicates
  * that you must take course bi first if you want to take course ai.
  **/

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
  {
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

    int count = 0;

    while (!Q.empty())
    {
      int size = Q.size();

      while (size-- > 0)
      {
        auto curr = Q.front();
        Q.pop_front();

        ++count;

        for (auto &next: G[curr])
          if (--indegrees[next] == 0)
            Q.push_back(next);
      }
    }

    return count == numCourses;
  }
};

} // end namespace leetcode

#endif