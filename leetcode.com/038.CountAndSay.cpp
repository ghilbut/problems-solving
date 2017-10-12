#include <gtest/gtest.h>
#include <sstream>
#include <cassert>

using namespace std;


class Solution {
 public:
  string countAndSay(int n) {
    assert(n > 0);

    string input("1");
    for (int loop = 1; loop < n; ++loop) {

      int count = 1;
      char c = input[0];
      stringstream output;
      for (int i = 1, size = input.length(); i < size; ++i) {
        if (c != input[i]) {
          output << count << c;
          c = input[i];
          count = 1;
        } else {
          ++count;
        }
      }
      output << count << c;
      input = output.str();
    }
    return input;
  }
};


class P038_CountAndSay_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P038_CountAndSay_Test, assert_when_input_is_not_positive_number) {
  ASSERT_DEATH(s.countAndSay(0), "");
  ASSERT_DEATH(s.countAndSay(-1), "");
}

TEST_F(P038_CountAndSay_Test, case1) {
  ASSERT_EQ("1", s.countAndSay(1));
}

TEST_F(P038_CountAndSay_Test, case2) {
  ASSERT_EQ("11", s.countAndSay(2));
}

TEST_F(P038_CountAndSay_Test, case3) {
  ASSERT_EQ("21", s.countAndSay(3));
}

TEST_F(P038_CountAndSay_Test, case4) {
  ASSERT_EQ("1211", s.countAndSay(4));
}

TEST_F(P038_CountAndSay_Test, case5) {
  ASSERT_EQ("111221", s.countAndSay(5));
}
