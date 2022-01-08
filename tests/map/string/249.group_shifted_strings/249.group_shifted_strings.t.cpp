#include <gtest/gtest.h>
#include <map/string/249.group_shifted_strings.h>

using namespace leetcode;

TEST(group_shifted_strings_249, I)
{
  std::vector<std::string> strs {
    "za", "bc", "abz", "bca"
  };

  std::vector<std::vector<std::string>> expected {
    {"za", "bc"},
    {"abz", "bca"}
  };

  ASSERT_EQ(Solution().groupStrings(strs), expected);

}