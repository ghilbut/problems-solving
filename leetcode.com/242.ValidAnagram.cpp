#include <gtest/gtest.h>
#include <string>

using namespace std;


class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    int histogram[26] = { 0, };
    for (int i=0, size=s.length(); i < size; ++i) {
      ++histogram[s[i] - 'a'];
      --histogram[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (histogram[i] != 0) {
        return false;
      }
    }
    return true;
  }
};


class P242_ValidAnagram_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P242_ValidAnagram_Test, case0) {
  ASSERT_TRUE(s.isAnagram("anagram", "nagaram"));

}

TEST_F(P242_ValidAnagram_Test, case1) {
  ASSERT_FALSE(s.isAnagram("rat", "car"));
}
