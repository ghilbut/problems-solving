#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;


class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> mem;
    for (int num : nums) {
      if (mem.find(num) != mem.end()) {
        return true;
      }
      mem.insert(num);
    }
    return false;
  }
};


class P217_ContainsDuplicate_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}

 protected:
  Solution s;
};

TEST_F(P217_ContainsDuplicate_Test, return_false) {
  vector<int> input { 0,1,2,3,4,5,6,7,8,9 };
  ASSERT_FALSE(s.containsDuplicate(input));
}

TEST_F(P217_ContainsDuplicate_Test, return_true) {
  vector<int> input { 0,1,2,3,1,5,6,7,8,9 };
  ASSERT_TRUE(s.containsDuplicate(input));
}
