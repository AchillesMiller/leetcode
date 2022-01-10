#include <gtest/gtest.h>

#include <union_find/721.accounts_merge.h>

using namespace leetcode;


TEST(NO_721_accounts_merge, I)
{
  std::vector<std::vector<std::string>> accounts {
    {"John","johnsmith@mail.com","john_newyork@mail.com"},
    {"John","johnsmith@mail.com","john00@mail.com"},
    {"Mary","mary@mail.com"},
    {"John","johnnybravo@mail.com"}
  };

  std::set<std::vector<std::string>> expected {
    {"John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"},
    {"Mary","mary@mail.com"},
    {"John","johnnybravo@mail.com"},
  };

  auto x1 = Solution().accountsMerge(accounts);
  ASSERT_EQ(std::set<std::vector<std::string>>(x1.begin(), x1.end()), expected);

  auto x2 = Solution().accountsMerge2(accounts);
  ASSERT_EQ(std::set<std::vector<std::string>>(x2.begin(), x2.end()), expected);
}
