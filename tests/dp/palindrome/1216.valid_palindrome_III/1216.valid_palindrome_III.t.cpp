#include <gtest/gtest.h>
#include <dp/palindrome/1216.valid_palindrome_III.h>

using namespace leetcode;

TEST(NO_1261_valid_palindrome_III, I)
{
  std::string s = "abcdeca";

  ASSERT_TRUE(Solution().isValidPalindrome(s, 2));
  ASSERT_TRUE(Solution().isValidPalindrome(s, 3));
  ASSERT_FALSE(Solution().isValidPalindrome(s, 1));
}