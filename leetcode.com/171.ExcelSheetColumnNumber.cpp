#include <gtest/gtest.h>
#include <string>
#include <stack>

using namespace std;


class Solution {
 public:
  int titleToNumber(string s) {
    int sum = 0;
    int base = 1;
    for (int i=0, size=s.length(); i < size; ++i) {
      sum += (base * (s[size-i-1] - 'A' + 1));
      base *= 26;
    }
    return sum;
  }
};


class P171_ExcelSheetColumnNumber_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P171_ExcelSheetColumnNumber_Test, single_character) {
  ASSERT_EQ(1, s.titleToNumber("A"));
  ASSERT_EQ(26, s.titleToNumber("Z"));
}

TEST_F(P171_ExcelSheetColumnNumber_Test, double_character) {
  ASSERT_EQ(27, s.titleToNumber("AA"));
  ASSERT_EQ(28, s.titleToNumber("AB"));
}
