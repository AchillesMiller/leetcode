#include "gtest/gtest.h"

#include <50/my_pow.h>

using namespace leetcode;

TEST(my_pow, a)
{
  ASSERT_EQ(my_pow().pow(2.0, 10), 1024);
}

TEST(my_pow, b)
{
  ASSERT_EQ(my_pow().pow(2.0, -2), 0.25);
}
