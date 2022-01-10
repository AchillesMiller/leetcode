#include <gtest/gtest.h>

#include <array/two_pointers/408.valid_word_abbreviation.h>

using namespace leetcode;


TEST(NO_408_valid_word_abbreviation, I)
{
  std::string word = "sort";
  std::string abbr1 = "s2t";
  std::string abbr2 = "2rt";

  ASSERT_TRUE(Solution().validWordAbbreviation(word, abbr1));
  ASSERT_TRUE(Solution().validWordAbbreviation(word, abbr2));
}
