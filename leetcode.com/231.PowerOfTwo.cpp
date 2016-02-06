#include <gtest/gtest.h>

using namespace std;


class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n < 1) {
      return false;
    }
    while (n != 1) {
      if (n % 2 != 0) {
        return false;
      }
      n /= 2;
    }
    return true;
  }
};


class P231_PowerOfTwo_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P231_PowerOfTwo_Test, is_not_power_of_two) {
  ASSERT_FALSE(s.isPowerOfTwo(-1));
  ASSERT_FALSE(s.isPowerOfTwo(0));
}

TEST_F(P231_PowerOfTwo_Test, is_power_of_two) {
  ASSERT_TRUE(s.isPowerOfTwo(1));
  ASSERT_TRUE(s.isPowerOfTwo(2));
  ASSERT_TRUE(s.isPowerOfTwo(4));
  ASSERT_TRUE(s.isPowerOfTwo(8));
  ASSERT_TRUE(s.isPowerOfTwo(16));
}
