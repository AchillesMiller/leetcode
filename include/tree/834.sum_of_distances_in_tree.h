#ifndef INCLUDED_TREE_834_SUM_OF_DISTANCES_IN_TREE
#define INCLUDED_TREE_834_SUM_OF_DISTANCES_IN_TREE


namespace leetcode {

/** @brief: sum of distance in tree
 *  Return an array answer of length n where answer[i]
 *  is the sum of the distances
 *  between the ith node in the tree and all other nodes.
 **/

 class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    // it is a undirected graph problem.

    // D(x) = the distance between x and its descendants
    // C(x) = the number of its descendants

    // iteration one, post-order
    // D(parent) = Σ(D(child)) + Σ(C(child) + 1)

    // iteration two, pre-order
    // D(child) = D(parent) + (N-C(child)-1) - (C(child) + 1)
    //          = D(parent) + N - C(child) -1 - C(child) - 1

    std::vector<std::unordered_set<int>> next(n);

    for (auto &e: edges)
    {
      next[e[0]].insert(e[1]);
      next[e[1]].insert(e[0]);
    }

    std::vector<int> D(n, 0);
    std::vector<int> C(n, 0);

    post_order(next, 0, D, C);
    pre_order(next, 0, D, C);
    return D;
  }

  void post_order(std::vector<std::unordered_set<int>> &next, int curr,
                  std::vector<int> &D, std::vector<int> &C)
  {
    for (auto &child: next[curr])
    {
      next[child].erase(curr);
      post_order(next, child, D, C);

      D[curr] += C[child] + 1 + D[child];
      C[curr] += 1 + C[child];
    }
  }

  void pre_order(std::vector<std::unordered_set<int>> &next, int curr,
                 std::vector<int> &D, std::vector<int> &C)
  {
    for (auto &child: next[curr])
    {
      D[child] = D[curr] + next.size() - C[child] - C[child] - 2;
      pre_order(next, child, D, C);
    }
  }
};

} // end namespace leetcode

#endif