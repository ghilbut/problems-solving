#include <gtest/gtest.h>

using namespace std;


class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i =0; i <32; ++i) {
      if ((n & 0x01) == 0x01) {
        ++count;
      }
      n = (n >> 1);
    }
    return count;
  }
};


class P191_NumberOf1Bits_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P191_NumberOf1Bits_Test, case0) {
  ASSERT_EQ(0, s.hammingWeight(0x00));
}

TEST_F(P191_NumberOf1Bits_Test, case1) {
  ASSERT_EQ(1, s.hammingWeight(0x01));
}

TEST_F(P191_NumberOf1Bits_Test, case2) {
  ASSERT_EQ(1, s.hammingWeight(0x80000000));
}

TEST_F(P191_NumberOf1Bits_Test, case3) {
  ASSERT_EQ(2, s.hammingWeight(0x80000001));
}

TEST_F(P191_NumberOf1Bits_Test, case4) {
  ASSERT_EQ(32, s.hammingWeight(0xffffffff));
}
