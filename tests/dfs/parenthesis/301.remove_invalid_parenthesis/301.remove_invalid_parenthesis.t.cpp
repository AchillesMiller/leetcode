#include <gtest/gtest.h>
#include <dfs/parenthesis/301.remove_invalid_parenthesis.h>

using namespace leetcode;

TEST(NO_301_remove_invalid_parenthesis, I)
{
  std::string s = "()())()";

  std::vector<std::string> expected {
    "()()()", "(())()"
  };

  ASSERT_EQ(Solution().removeInvalidParentheses(s), expected);
}
