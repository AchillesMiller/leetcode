#ifndef INCLUDED_DFS_GRAPH_465_OPTIMAL_ACCOUNT_BALANCING
#define INCLUDED_DFS_GRAPH_465_OPTIMAL_ACCOUNT_BALANCING

#include <vector>

namespace leetcode {

class Solution {
public:
  int minTransfers(std::vector<std::vector<int>>& transactions) {

    // Make total debt to be 0 with minimum transaction
    // it can be interpreted as minimum transaction to
    // make debt of each account to be 0

    // if one account has positive debt, it can give all its money to
    // another account, and declare debt free.
    // if ............... negative debt, it can ask money from another account
    // and declare debt free

    // either case is one transaction

    int N = 21; // only 21 persons

    std::vector<int> debts(N, 0);

    for (auto &t: transactions)
    {
      auto &fr = t[0];
      auto &to = t[1];

      debts[fr] -= t[2];
      debts[to] += t[2];
    }

    return dfs(debts, 0);
  }

private:
  int dfs(std::vector<int> &debts, int start)
  {
    // reach to the end
    if (start == debts.size())
      return 0;

    auto &curr = debts[start];

    if (curr == 0) // current debt is 0, return transaction to make total debt
                   //                    to be 0 from start+1
      return dfs(debts, start+1);

    int transaction = INT_MAX;

    for (auto i = start+1; i < debts.size(); ++i)
    {
      auto &next = debts[i];

      // if curr is positive, check the min transaction with all negative number

      if (curr * next < 0)
      {
        debts[i] += curr;

        transaction = std::min(transaction, dfs(debts, start+1)+1);

        debts[i] -= curr; // back-tracing

        // if it happens to be debt-free between two account, it produces
        // the minimum distance
        if (debts[i] + curr == 0)
          break;

      }
    }

    assert (transaction != INT_MAX); // at least one distance is
    return transaction;
  }

};

} // end namespace leetcode


#endif