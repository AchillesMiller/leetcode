#include "gtest/gtest.h"

#include <divide_and_conquer/50.my_pow.h>

using namespace leetcode;

TEST(NO_50_my_pow, I)
{
  ASSERT_EQ(my_pow().pow(2.0, 10), 1024);
}

TEST(NO_50_my_pow, II)
{
  ASSERT_EQ(my_pow().pow(2.0, -2), 0.25);
}
