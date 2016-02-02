#include <gtest/gtest.h>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode head = ListNode(0);
    ListNode * tail = &head;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int val = carry;
      if (l1 != nullptr) {
        val += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        val += l2->val;
        l2 = l2->next;
      }
      carry = val / 10;
      tail = tail->next = new ListNode(val % 10);
    }
    return head.next;
  }
};


class P002_AddTwoNumbers_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};


TEST_F(P002_AddTwoNumbers_Test, case1) {
  ListNode l0(1);
  ListNode r0(1);
  
  ListNode * head = s.addTwoNumbers(&l0, &r0);
  ASSERT_EQ(2, head->val);
  ASSERT_EQ(nullptr, head->next);
}

TEST_F(P002_AddTwoNumbers_Test, case2) {
  ListNode l0(5);
  ListNode r0(5);
  
  ListNode * head = s.addTwoNumbers(&l0, &r0);
  ASSERT_EQ(0, head->val);
  ASSERT_EQ(1, (head = head->next)->val);
  ASSERT_EQ(nullptr, head->next);
}

TEST_F(P002_AddTwoNumbers_Test, case3) {
  ListNode l0(2);
  ListNode l1(4);
  l0.next = &l1;
  ListNode l2(3);
  l1.next = &l2;
  
  ListNode r0(5);
  ListNode r1(6);
  r0.next = &r1;
  ListNode r2(4);
  r1.next = &r2;
  
  ListNode * head = s.addTwoNumbers(&l0, &r0);
  ASSERT_EQ(7, head->val);
  ASSERT_EQ(0, (head = head->next)->val);
  ASSERT_EQ(8, (head = head->next)->val);
}

TEST_F(P002_AddTwoNumbers_Test, case4) {
  ListNode l0(2);
  ListNode l1(4);
  l0.next = &l1;
  ListNode l2(4);
  l1.next = &l2;
  
  ListNode r0(5);
  ListNode r1(6);
  r0.next = &r1;
  ListNode r2(5);
  r1.next = &r2;
  
  ListNode * head = s.addTwoNumbers(&l0, &r0);
  ASSERT_EQ(7, head->val);
  ASSERT_EQ(0, (head = head->next)->val);
  ASSERT_EQ(0, (head = head->next)->val);
  ASSERT_EQ(1, (head = head->next)->val);
}
