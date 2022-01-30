#ifndef INCLUDED_BINARY_SEARCH_2071_MAXIMUM_NUMBER_OF_TASKS_YOU_CAN_ASSIGN
#define INCLUDED_BINARY_SEARCH_2071_MAXIMUM_NUMBER_OF_TASKS_YOU_CAN_ASSIGN

namespace leetcode {

/** @brief: maximum number of tasks you can assign
 *  You have n tasks and m workers.
 *  Each task has a strength requirement stored
 *  in a 0-indexed integer array tasks,
 *  with the ith task requiring tasks[i] strength to complete.
 *  The strength of each worker is stored in a 0-indexed integer array workers,
 *  with the jth worker having workers[j] strength.
 *  Each worker can only be assigned to a single task and
 *  must have a strength greater than or equal
 *  to the task's strength requirement (i.e., workers[j] >= tasks[i]).
 **/

class Solution {
public:
  int maxTaskAssign(std::vector<int>& tasks,
                    std::vector<int>& workers,
                    int pills,
                    int strength)
  {
    // each worker can only be assigned one task, and can eat only one pill

    // find the maximum task to assign

    // find the maximum, it is a good choice to use binary search

    int k = std::min(tasks.size(), workers.size());

    std::sort(tasks.begin(), tasks.end());
    std::sort(workers.begin(), workers.end());

    int l = 0;
    int r = k;

    while (l < r) // [0, 1], [0]
    {
      int mid = r - (r-l)/2;
      if (can_assign(tasks, workers, pills, strength, mid))
        l = mid;
      else
        r = mid-1;
    }

    return l;
  }

private:
  bool can_assign(std::vector<int> &tasks,
                  std::vector<int> &workers,
                  int pills,
                  int strength,
                  int k)
  {
    // check if we can finish k tasks
    // greedy algorithm: check if the most k senior guys can finish
    //                   k easiest tasks
    //                   if most senior guy left can not finish the most hard
    //                   task, find best fit guy with strength to finish task

    std::deque<int> seniors;

    int n = workers.size();

    int j = n-1;

    for (int i = k-1; i >= 0; --i)
    {
      auto &task = tasks[i];

      while (j >= n-k && strength + workers[j] >= task)
        seniors.push_front(j--);

      if (seniors.empty())
        return false;

      if (workers[seniors.back()] >= task)
        seniors.pop_back();
      else
      {
        if (pills == 0 || workers[seniors.front()] + strength < task)
          return false;

        --pills;
        seniors.pop_front();
      }
    }
    return true;
  }
};


} // end namespace leetcode

#endif