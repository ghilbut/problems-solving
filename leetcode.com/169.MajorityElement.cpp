#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    const int size = nums.size();
    if (size == 1) {
      nums[0];
    }
    unordered_map<int, int> mem;
    const int majoritiy_count = (size + 1) / 2;
    for (int num : nums) {
      if (++mem[num] >= majoritiy_count) {
        return num;
      }
    }
    return 0;
  }
};


class P169_MajorityElement_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P169_MajorityElement_Test, case0) {
  vector<int> input {0,0,1};
  ASSERT_EQ(0, s.majorityElement(input));
}

TEST_F(P169_MajorityElement_Test, case1) {
  vector<int> input {0,1,1};
  ASSERT_EQ(1, s.majorityElement(input));
}

TEST_F(P169_MajorityElement_Test, case2) {
  vector<int> input {0,0,1,2};
  ASSERT_EQ(0, s.majorityElement(input));
}

TEST_F(P169_MajorityElement_Test, case3) {
  vector<int> input {0,0,1,2,3,4,4,4,4,4};
  ASSERT_EQ(4, s.majorityElement(input));
}
