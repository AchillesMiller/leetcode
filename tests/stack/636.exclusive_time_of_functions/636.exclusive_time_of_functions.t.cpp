#include <gtest/gtest.h>
#include <stack/636.exclusive_time_of_functions.h>

using namespace leetcode;

TEST(NO_636_EXCLUSIVE_TIME_OF_FUNCTIONS, I)
{
  std::vector<std::string> logs {
    "0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"
  };

  std::vector<int> expected {8};

  ASSERT_EQ(Solution().exclusiveTime(1, logs), expected);
}