#include <gtest/gtest.h>
#include <vector>

using namespace std;


class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int begin = 0;
    int end = 0;
    for (int i=0, size=nums.size(); i < size; ++i) {
      if (nums[i] != 0) {
        nums[begin] = nums[i];
        ++begin;
      }
      ++end;
    }
    for (int i=begin; i < end; ++i) {
      nums[i] = 0;
    }
  }
};


class SolutionTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(SolutionTest, case0) {
  vector<int> nums { 0, 1, 0, 3, 12 };
  const vector<int> expected { 1, 3, 12, 0, 0 };
  s.moveZeroes(nums);
  ASSERT_EQ(expected, nums);
}

TEST_F(SolutionTest, case1) {
  vector<int> nums { 1 };
  const vector<int> expected { 1 };
  s.moveZeroes(nums);
  ASSERT_EQ(expected, nums);
}
