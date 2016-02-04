#include <gtest/gtest.h>

using namespace std;


class Solution {
 public:
  bool isUgly(int num) {
    if (num < 1) {
      return false;
    }

    int quotient = num;
    int remainder = 0;
    while (quotient != 1) {
      remainder = quotient % 2;
      if (remainder != 0) {
        break;
      }
      quotient = quotient / 2;
    }
    while (quotient != 1) {
      remainder = quotient % 3;
      if (remainder != 0) {
        break;
      }
      quotient = quotient / 3;
    }
    while (quotient != 1) {
      remainder = quotient % 5;
      if (remainder != 0) {
        break;
      }
      quotient = quotient / 5;
    }
    return (quotient == 1);
  }
};


class P263_UglyNumber_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P263_UglyNumber_Test, case0) {
  ASSERT_TRUE(s.isUgly(1));
  ASSERT_TRUE(s.isUgly(2));
  ASSERT_TRUE(s.isUgly(3));
  ASSERT_TRUE(s.isUgly(5));
  ASSERT_TRUE(s.isUgly(6));
  ASSERT_TRUE(s.isUgly(8));
}

TEST_F(P263_UglyNumber_Test, case1) {
  ASSERT_FALSE(s.isUgly(-1));
  ASSERT_FALSE(s.isUgly(0));
  ASSERT_FALSE(s.isUgly(14));
}
