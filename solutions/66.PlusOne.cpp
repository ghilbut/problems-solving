#include <gtest/gtest.h>
#include <vector>

using namespace std;


class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> result(digits);
    int i = result.size() - 1;
    for (; i >= 0; --i) {
      if (result[i] == 9) {
        result[i] = 0;
      } else {
        ++result[i];
        break;
      }
    }
    if (i == -1 && result[0] == 0) {
      result.insert(result.begin(), 1);
    }
    return result;
  }
};


class P66_PlusOne_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P66_PlusOne_Test, return_1_when_0) {
  vector<int> input;
  input.push_back(0);
  vector<int> output;
  output.push_back(1);
  ASSERT_EQ(output, s.plusOne(input));
}

TEST_F(P66_PlusOne_Test, return_9_when_8) {
  vector<int> input;
  input.push_back(8);
  vector<int> output;
  output.push_back(9);
  ASSERT_EQ(output, s.plusOne(input));
}

TEST_F(P66_PlusOne_Test, return_10_when_9) {
  vector<int> input;
  input.push_back(9);
  vector<int> output;
  output.push_back(1);
  output.push_back(0);
  ASSERT_EQ(output, s.plusOne(input));
}

TEST_F(P66_PlusOne_Test, return_99_when_98) {
  vector<int> input;
  input.push_back(9);
  input.push_back(8);
  vector<int> output;
  output.push_back(9);
  output.push_back(9);
  ASSERT_EQ(output, s.plusOne(input));
}

TEST_F(P66_PlusOne_Test, return_100_when_99) {
  vector<int> input;
  input.push_back(9);
  input.push_back(9);
  vector<int> output;
  output.push_back(1);
  output.push_back(0);
  output.push_back(0);
  ASSERT_EQ(output, s.plusOne(input));
}
