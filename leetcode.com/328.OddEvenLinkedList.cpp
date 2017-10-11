#include <gtest/gtest.h>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {

    ListNode oddprev(-1);
    oddprev.next = head;

    ListNode * prev = &oddprev;
    ListNode * cur = head;

    ListNode * even_head = nullptr;
    ListNode * even_tail = nullptr;
    while (cur != nullptr) {

      if (cur->val % 2 == 1) {
        prev = cur;
        cur = cur->next;
        continue;
      }

      if (even_tail == nullptr) {
        even_head = cur;
        even_tail = cur;
      } else {
        even_tail->next = cur;
        even_tail = cur;
      }
      prev->next = cur->next;
      cur = cur->next;
      even_tail->next = nullptr;
    }
    
    if (oddprev.next == nullptr) {
      oddprev.next = even_head;
    } else {
      prev->next = even_head;
    }

    return oddprev.next;
  }
};


class P328_OddEvenLinkedList_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P328_OddEvenLinkedList_Test, case0) {
  ListNode l1(1);
  ListNode l2(3);
  l1.next = &l2;
  ListNode l3(5);
  l2.next = &l3;
  ListNode l4(7);
  l3.next = &l4;
  ListNode l5(9);
  l4.next = &l5;

  ListNode * head = s.oddEvenList(&l1);
  ASSERT_EQ(1, head->val);
  ASSERT_EQ(3, (head = head->next)->val);
  ASSERT_EQ(5, (head = head->next)->val);
  ASSERT_EQ(7, (head = head->next)->val);
  ASSERT_EQ(9, (head = head->next)->val);
}

TEST_F(P328_OddEvenLinkedList_Test, case1) {
  ListNode l1(2);
  ListNode l2(4);
  l1.next = &l2;
  ListNode l3(6);
  l2.next = &l3;
  ListNode l4(8);
  l3.next = &l4;
  ListNode l5(10);
  l4.next = &l5;

  ListNode * head = s.oddEvenList(&l1);
  ASSERT_EQ(2, head->val);
  ASSERT_EQ(4, (head = head->next)->val);
  ASSERT_EQ(6, (head = head->next)->val);
  ASSERT_EQ(8, (head = head->next)->val);
  ASSERT_EQ(10, (head = head->next)->val);
}

TEST_F(P328_OddEvenLinkedList_Test, case2) {
  ListNode l1(1);
  ListNode l2(2);
  l1.next = &l2;
  ListNode l3(3);
  l2.next = &l3;
  ListNode l4(4);
  l3.next = &l4;
  ListNode l5(5);
  l4.next = &l5;

  ListNode * head = s.oddEvenList(&l1);
  ASSERT_EQ(1, head->val);
  ASSERT_EQ(3, (head = head->next)->val);
  ASSERT_EQ(5, (head = head->next)->val);
  ASSERT_EQ(2, (head = head->next)->val);
  ASSERT_EQ(4, (head = head->next)->val);
}
