#include <gtest/gtest.h>
#include <dp/1048.longest_string_chain.h>

using namespace leetcode;

TEST(NO_1048_longest_string_chain, I)
{
  std::vector<std::string> strs {
    "a","b","ba","bca","bda","bdca"
  };


  ASSERT_EQ(Solution().longestStrChain(strs), 4);

}