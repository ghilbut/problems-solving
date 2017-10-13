#include <gtest/gtest.h>
#include <queue>
#include <unordered_map>
#include <utils.h>


class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {

    unordered_map<string, int> check;
    for (auto && w : words) {
      ++check[w];
    }

    auto compare = [] (auto && lhs, auto && rhs) {
        if (lhs.second == rhs.second) {
          return lhs.first > rhs.first;
        } else {
          return lhs.second < rhs.second;
        }
      };
    priority_queue<pair<string, int>, std::vector<pair<string, int>>, decltype(compare)> tmp(compare);
    for (auto && p : check) {
      tmp.push(p);
    }

    vector<string> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(tmp.top().first);
      tmp.pop();
    }

    return result;
  }
};


class P692_TopKFrequentWords_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P692_TopKFrequentWords_Test, case0) {

  vector<string> i { "i", "love", "leetcode", "i", "love", "coding" };
  int k = 2;
  vector<string> e { "i", "love" };
  vector<string> o = s.topKFrequent(i, k);
  ASSERT_TRUE(equal(e.begin(), e.end(), o.begin(), o.end()));
}

TEST_F(P692_TopKFrequentWords_Test, case1) {

  vector<string> i { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
  int k = 4;
  vector<string> e { "the", "is", "sunny", "day" };
  vector<string> o = s.topKFrequent(i, k);
  ASSERT_TRUE(equal(e.begin(), e.end(), o.begin(), o.end()));
}
