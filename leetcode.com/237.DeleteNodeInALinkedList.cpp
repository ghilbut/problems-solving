#include <gtest/gtest.h>



struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
 public:
  void deleteNode(ListNode* node) {

  }
};


class P237_DeleteNodeInALinkedList_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P237_DeleteNodeInALinkedList_Test, example_case) {
  ListNode n3(4);
  ListNode n2(3);
  n2.next = &n3;
  ListNode n1(2);
  n1.next = &n2;
  ListNode n0(1);
  n0.next = &n1;
  s.deleteNode(&n2);
  ASSERT_EQ(4, n2.next->val);
}