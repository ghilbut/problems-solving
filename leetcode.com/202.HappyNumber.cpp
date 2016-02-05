#include <gtest/gtest.h>

using namespace std;


class Solution {
 public:
  bool isHappy(int n) {
    int slow = n;
    int fast = n;
    do {
      slow = Next(slow);
      fast = Next(Next(fast));
      
    } while(slow != fast);
    return (slow == 1);
  }
  
  int Next(int n) {
    int sum = 0;
    while (n != 0) {
      int r = n % 10;
      sum += (r * r);
      n /= 10;
    }
    return sum;
  }
};


class P202_HappyNumber_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P202_HappyNumber_Test, pass) {
  ASSERT_TRUE(s.isHappy(19));
}
