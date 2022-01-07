#include <gtest/gtest.h>
#include <greedy_algorithm/string/68.text_justification.h>

using namespace leetcode;

TEST(text_justification_68, I)
{

  std::vector<std::string> words {
    "I", "AM", "TEXT", "1234567"
  };

  int max_width = 10;

  std::vector<std::string> expected {
    "I  AM TEXT", "1234567   "
  };

  ASSERT_EQ(Solution().fullJustify(words, max_width), expected);
}
