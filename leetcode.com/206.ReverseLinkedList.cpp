#include <gtest/gtest.h>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto prev = head;
    auto cur = head->next;
    while (cur != nullptr) {
      auto next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    head->next = nullptr;
    return prev;
  }
};


class P206_ReverseLinkedList_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P206_ReverseLinkedList_Test, pass) {
  ListNode l0(0);
  ListNode l1(1);
  l0.next = &l1;
  ListNode l2(2);
  l1.next = &l2;
  ListNode l3(3);
  l2.next = &l3;
  
  ListNode * head = s.reverseList(&l0);
  ASSERT_EQ(3, head->val);
  ASSERT_EQ(2, (head = head->next)->val);
  ASSERT_EQ(1, (head = head->next)->val);
  ASSERT_EQ(0, (head = head->next)->val);
  ASSERT_EQ(nullptr, head->next);
}