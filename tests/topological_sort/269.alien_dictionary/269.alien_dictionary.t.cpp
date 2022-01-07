#include <gtest/gtest.h>
#include <topological_sort/269.alien_dictionary.h>

using namespace leetcode;

TEST(alien_dictionary_269, I)
{
  std::vector<std::string> words {
    "wrt","wrf","er","ett","rftt"
  };

  ASSERT_EQ(Solution().alienOrder(words), "wertf");
}
