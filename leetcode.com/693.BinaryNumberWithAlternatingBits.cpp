#include <climits>
#include <gtest/gtest.h>
#include <utils.h>


class Solution {
 public:
  bool hasAlternatingBits(int n) {
    while (n > 0) {
      const int l = n & 0x01;
      const int r = (n >>= 1) & 0x01;
      if (l == r) {
        return false;
      }
    }
    return true;
  }
};


class P693_BinaryNumberWithAlternatingBits_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P693_BinaryNumberWithAlternatingBits_Test, case0) {
  ASSERT_TRUE(s.hasAlternatingBits(0));
  ASSERT_TRUE(s.hasAlternatingBits(1));
  ASSERT_TRUE(s.hasAlternatingBits(2));
}

TEST_F(P693_BinaryNumberWithAlternatingBits_Test, case1) {
  ASSERT_TRUE(s.hasAlternatingBits(5));
  ASSERT_FALSE(s.hasAlternatingBits(7));
  ASSERT_TRUE(s.hasAlternatingBits(10));
  ASSERT_FALSE(s.hasAlternatingBits(11));
}

TEST_F(P693_BinaryNumberWithAlternatingBits_Test, case2) {
  ASSERT_FALSE(s.hasAlternatingBits(4));
}
