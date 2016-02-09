#include <gtest/gtest.h>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode head(-1);
    ListNode * tail = &head;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    
    if (l1 == nullptr) {
      tail->next = l2;
    } else {
      tail->next = l1;
    }

    return head.next;
  }
};


class P021_MergeTwoSortedLists_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P021_MergeTwoSortedLists_Test, case0) {
  ASSERT_EQ(nullptr, s.mergeTwoLists(nullptr, nullptr));
}

TEST_F(P021_MergeTwoSortedLists_Test, case1) {
  ListNode l(0);

  ListNode * head = s.mergeTwoLists(&l, nullptr);
  ASSERT_NE(nullptr, head);
  ASSERT_EQ(0, head->val);
  ASSERT_EQ(nullptr, head->next);
}

TEST_F(P021_MergeTwoSortedLists_Test, case2) {
  ListNode l0(1);
  ListNode l1(2);
  l0.next = &l1;
  
  ListNode r0(3);

  ListNode * head = s.mergeTwoLists(&l0, &r0);
  ASSERT_NE(nullptr, head);
  ASSERT_EQ(1, head->val);
  ASSERT_EQ(2, (head = head->next)->val);
  ASSERT_EQ(3, (head = head->next)->val);
  ASSERT_EQ(nullptr, head->next);
}

TEST_F(P021_MergeTwoSortedLists_Test, case3) {
  ListNode l0(1);
  ListNode l1(2);
  l0.next = &l1;
  
  ListNode r0(3);

  ListNode * head = s.mergeTwoLists(&r0, &l0);
  ASSERT_NE(nullptr, head);
  ASSERT_EQ(1, head->val);
  ASSERT_EQ(2, (head = head->next)->val);
  ASSERT_EQ(3, (head = head->next)->val);
  ASSERT_EQ(nullptr, head->next);
}

TEST_F(P021_MergeTwoSortedLists_Test, case4) {
  ListNode l0(1);
  ListNode l1(3);
  l0.next = &l1;
  
  ListNode r0(2);

  ListNode * head = s.mergeTwoLists(&l0, &r0);
  ASSERT_NE(nullptr, head);
  ASSERT_EQ(1, head->val);
  ASSERT_EQ(2, (head = head->next)->val);
  ASSERT_EQ(3, (head = head->next)->val);
  ASSERT_EQ(nullptr, head->next);
}

TEST_F(P021_MergeTwoSortedLists_Test, case5) {
  ListNode l0(1);
  ListNode l1(3);
  l0.next = &l1;
  
  ListNode r0(2);

  ListNode * head = s.mergeTwoLists(&r0, &l0);
  ASSERT_NE(nullptr, head);
  ASSERT_EQ(1, head->val);
  ASSERT_EQ(2, (head = head->next)->val);
  ASSERT_EQ(3, (head = head->next)->val);
  ASSERT_EQ(nullptr, head->next);
}
