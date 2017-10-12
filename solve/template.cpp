#include <gtest/gtest.h>
#include <utils.h>


class Solution {
 public:
  bool solve() {
    return true;
  }
};


class SolutionTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(SolutionTest, pass) {
  ASSERT_TRUE(s.solve());
}

TEST_F(SolutionTest, fail) {
  ASSERT_FALSE(s.solve());
}
