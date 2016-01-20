#include <gtest/gtest.h>
#include <random>

using namespace std;


class Solution {
 public:
  bool canWinNim(int n) {
    return (n % 4) != 0;
  }
};


class P292_NimGame_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P292_NimGame_Test, can_win_if_number_is_less_than_four) {
  ASSERT_TRUE(s.canWinNim(1));
  ASSERT_TRUE(s.canWinNim(2));
  ASSERT_TRUE(s.canWinNim(3));
}

TEST_F(P292_NimGame_Test, can_not_win_if_number_is_equal_four) {
  ASSERT_FALSE(s.canWinNim(4));
}

TEST_F(P292_NimGame_Test, can_not_win_if_number_is_a_muliple_of_four) {
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, 100);
  const int count = distribution(generator);
  for (int i = 0; i < count; ++i) {
    const int number = distribution(generator);
    ASSERT_FALSE(s.canWinNim(number * 4));
  }
}

TEST_F(P292_NimGame_Test, can_win_when_number_is_not_a_multiple_of_four) {
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, 100);
  const int count = distribution(generator);
  for (int i = 0; i < count; ++i) {
    const int number = distribution(generator);
    ASSERT_TRUE(s.canWinNim(number * 4 + 1));
    ASSERT_TRUE(s.canWinNim(number * 4 + 2));
    ASSERT_TRUE(s.canWinNim(number * 4 + 3));
  }
}