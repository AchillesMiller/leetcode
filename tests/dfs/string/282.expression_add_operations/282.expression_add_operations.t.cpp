#include <gtest/gtest.h>
#include <dfs/string/282.expression_add_operations.h>

TEST(expression_add_operations_282, I)
{
  std::string num = "123";
  int target = 6;

  std::vector<std::string> expected {
    "1+2+3", "1*2*3"
  };

  ASSERT_EQ(Solution().addOperators(num, target), expected);
}
