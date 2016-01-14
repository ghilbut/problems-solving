#include <gtest/gtest.h>
#include <random>
#include <cassert>

using namespace std;

// HINT: https://en.wikipedia.org/wiki/Digital_root


class Solution {
 public:
  int addDigits(int num) {
    assert(num >= 0);
    const int largest_multiple_of_9_less_than_num = 9 * ((num - 1) / 9);
    return num - largest_multiple_of_9_less_than_num;
  }
};


class P258_AddDigits_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P258_AddDigits_Test, throw_exception_when_input_is_negative) {
  ASSERT_DEATH(s.addDigits(-1), "");
}

TEST_F(P258_AddDigits_Test, return_itself_when_input_is_a_single_digit_number) {
  ASSERT_EQ(1, s.addDigits(1));
  ASSERT_EQ(2, s.addDigits(2));
  ASSERT_EQ(3, s.addDigits(3));
  ASSERT_EQ(4, s.addDigits(4));
  ASSERT_EQ(5, s.addDigits(5));
  ASSERT_EQ(6, s.addDigits(6));
  ASSERT_EQ(7, s.addDigits(7));
  ASSERT_EQ(8, s.addDigits(8));
  ASSERT_EQ(9, s.addDigits(9));
}

static int solve(int num) {
  assert(num > -1);
  
  if (num == 0) {
    return 0;
  }

  const int quotient = num / 10;
  const int remainder = num % 10;
  int sum = remainder + solve(quotient);
  while (sum / 10 != 0) {
    sum = solve(sum);
  }
  return sum;
}

TEST_F(P258_AddDigits_Test, return_itself_when_input_is_a_multiple_digits_number) {
  default_random_engine generator;
  uniform_int_distribution<int> distribution(10, 100);
  const int count = distribution(generator);
  for (int i = 0; i < count; ++i) {
    const int number = distribution(generator);
    const int expected = solve(number);
    ASSERT_EQ(expected, s.addDigits(number));
  }
}