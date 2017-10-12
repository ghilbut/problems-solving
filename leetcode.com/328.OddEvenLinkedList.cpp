#include <gtest/gtest.h>
#include <utils.h>

#include <iostream>

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {

    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode * oddhead = head, * oddtail = head;
    ListNode * evenhead = head->next, * eventail = head->next;
    for (;;) {

      if (eventail->next == nullptr) {
        break;
      }

      oddtail = oddtail->next = eventail->next;

      if (oddtail->next == nullptr) {
        break;
      }

      eventail = eventail->next = oddtail->next;
    }

    oddtail->next = evenhead;
    eventail->next = nullptr;
    return oddhead;
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
  auto * i = MakeListFromString("[]");
  auto * o = s.oddEvenList(i);
  ASSERT_TRUE(IsListEqual(nullptr, o));
}

TEST_F(P328_OddEvenLinkedList_Test, case1) {
  auto * i = MakeListFromString("[ 1 ]");
  auto * e = MakeListFromString("[ 1 ]");
  auto * o = s.oddEvenList(i);
  ASSERT_TRUE(IsListEqual(e, o));
}

TEST_F(P328_OddEvenLinkedList_Test, case2) {
  auto * i = MakeListFromString("[ 1, 2, 3, 4, 5 ]");
  auto * e = MakeListFromString("[ 1, 3, 5, 2, 4 ]");
  auto * o = s.oddEvenList(i);
  ASSERT_TRUE(IsListEqual(e, o));
}

TEST_F(P328_OddEvenLinkedList_Test, case3) {
  auto * i = MakeListFromString("[ 1, 2, 3, 4, 5, 6, 7, 8 ]");
  auto * e = MakeListFromString("[ 1, 3, 5, 7, 2, 4, 6, 8 ]");
  auto * o = s.oddEvenList(i);
  ASSERT_TRUE(IsListEqual(e, o));
}
