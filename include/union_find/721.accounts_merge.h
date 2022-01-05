#ifndef INCLUDED_UNION_FIND_ACCOUNTS_MERGE_721
#define INCLUDED_UNION_FIND_ACCOUNTS_MERGE_721

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

namespace leetcode {

class Solution {

private:
  using account_t = std::vector<std::string>;
  using accounts_t = std::vector<account_t>;

public:
  /**
   * @brief merge accounts
   */
  accounts_t accountsMerge2(accounts_t & accounts)
  {
    // we can treat each individual account as one node,
    // then, the same email can acts as edge
    // therefore,  firstly construct the Graph
    //             then use DFS to find connected components

    int N = accounts.size();
    graph_t G(N, std::vector<bool>(N, false));

    // email to the indices of account
    std::unordered_map<std::string, std::vector<std::size_t>> email_to_accounts;

    // building a NxN adjacent graph

    for (auto i = 0; i != accounts.size(); ++i)
    {
      auto &a = accounts[i];
      auto &name = a[0];

      for (auto j = 1; j != a.size(); ++j)
      {
        auto it = email_to_accounts.insert({a[j], std::vector<std::size_t>()});
        auto &indices = it.first->second;

        for (auto &j: indices)
        {
          G[j][i] = true;  // bi-directional
          G[i][j] = true;
        }

        indices.push_back(i);
      }
    }

    accounts_t rets;
    rets.reserve(N);

    // dfs to find all connected components
    for (auto i = 0; i != G.size(); ++i)
    {
      if (accounts[i].empty()) // visited before
        continue;

      auto &name = accounts[i][0];

      account_t a;
      a.push_back(name);

      dfs(accounts, G, i, a);

      rets.push_back(a);
    }

    return rets;
  }

  accounts_t accountsMerge(accounts_t &accounts)
  {
    // another solution is, union find algorithm can be used
    // emails of each account are treated as a subtree.
    // if one email doesn't have parent,
    //    add this email to subtree and a[1] is the root
    // else union current subtree with parent[email]'s subtree

    // union find,
    // 1. find_parent(x): find parent of x and
    //                    reset parent of node in this routine
    // 2. union :         union two unconnected component

    std::map<std::string, std::string> parents;
    std::unordered_map<std::string, std::string> names;

    // union finds
    for (auto &a: accounts)
    {
      auto &name = a[0];
      auto &root = a[1];

      names.insert({root, name});

      // emails
      for (auto i = 1; i != a.size(); ++i)
      {
        auto &email = a[i];
        auto it = parents.insert({email, email});

        auto &parent = it.first->second;
        if (parent == email)
          parents[email] = find_parent(parents, root);
        else
          parents[find_parent(parents, root)] = find_parent(parents, email);
      }
    }

    std::unordered_map<std::string, int> email_to_indices;
    //                 ------------  ---
    //                 parent email  index

    std::vector<std::vector<std::string>> rets;
    rets.reserve(accounts.size());

    for (auto &x: parents)
    {
      auto &email = x.first;
      auto parent = find_parent(parents, email);

      auto it = email_to_indices.insert({parent, rets.size()});
      if (it.second)
        rets.push_back(std::vector<std::string>(1, names[parent]));

      auto &v = rets[it.first->second];
      v.push_back(email);
    }

    return rets;

  }

  std::string find_parent(std::map<std::string, std::string> &parents,
                          const std::string &email)
  {
    if (parents[email] == email)
      return email;

    parents[email] = find_parent(parents, parents[email]);
    return parents[email];
  }

private:
  using graph_t = std::vector<std::vector<bool>>;

  void dfs(accounts_t &accounts, graph_t &G, int start, account_t &a)
  {
    auto &account = accounts[start];
    auto &name = account[0];

    if (account.empty()) // visited
      return;

    a.reserve(a.size()+accounts.size());

    // push account.emails to `a` in non-descending order
    for (auto i = 1; i < account.size(); ++i)
    {
      auto &email = account[i];
      auto it = std::lower_bound(a.begin()+1, a.end(), email);

      if (it == a.end())     a.push_back(email);
      else if (*it != email) a.insert(it, email);
    }

   account.clear();

    for (auto i = 0; i != G.size(); ++i)
      if (G[start][i]) // connected
        dfs(accounts, G, i, a);
  }

};

} // end namespace leetcode

#endif