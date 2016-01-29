#include <gtest/gtest.h>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int countA, countB;
    ListNode * lastA = GetLastNodeAndCount(headA, countA);
    ListNode * lastB = GetLastNodeAndCount(headB, countB);
    if (lastA != lastB) {
      return nullptr;
    }
    
    int diff;
    ListNode * shorter;
    ListNode * longer;
    if (countA < countB) {
      shorter = headA;
      longer = headB;
      diff = countB - countA;
    } else {
      shorter = headB;
      longer = headA;
      diff = countA - countB;
    }
    
    longer = MoveTo(longer, diff);
    while (shorter != longer) {
      shorter = shorter->next;
      longer = longer->next;
    }
    return shorter;
  }
  
  ListNode * GetLastNodeAndCount(ListNode * head, int & count) {
    count = 0;
    while (head != nullptr) {
      head = head->next;
      ++count;
    }
    return head;
  }
  
  ListNode * MoveTo(ListNode * head, int steps) {
    while (steps != 0) {
      head = head->next;
      --steps;
    }
    return head;
  }
};


class P160_IntersectionOfTwoLinkedLists_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P160_IntersectionOfTwoLinkedLists_Test, case0) {
  ListNode l(0);
  ASSERT_EQ(nullptr, s.getIntersectionNode(nullptr, nullptr));
  ASSERT_EQ(nullptr, s.getIntersectionNode(&l, nullptr));
  ASSERT_EQ(nullptr, s.getIntersectionNode(nullptr, &l));
}

TEST_F(P160_IntersectionOfTwoLinkedLists_Test, case1) {
  ListNode lA0(0);
  ListNode lA1(1);
  lA0.next = &lA1;
  ListNode lA2(2);
  lA1.next = &lA2;
  ListNode lA3(3);
  lA2.next = &lA3;
  
  ListNode lB0(0);
  ListNode lB1(1);
  lB0.next = &lB1;
  ListNode lB2(2);
  lB1.next = &lB2;
  
  ASSERT_EQ(nullptr, s.getIntersectionNode(&lA0, &lB0));
}

TEST_F(P160_IntersectionOfTwoLinkedLists_Test, case2) {
  ListNode l0(0);
  ListNode l1(1);
  l0.next = &l1;
  ListNode l2(2);
  l1.next = &l2;

  ASSERT_EQ(&l0, s.getIntersectionNode(&l0, &l0));
}

TEST_F(P160_IntersectionOfTwoLinkedLists_Test, case3) {
  ListNode lA0(0);
  ListNode lA1(1);
  lA0.next = &lA1;
  ListNode lA2(2);
  lA1.next = &lA2;
  ListNode lA3(3);
  lA2.next = &lA3;
  ListNode lA4(4);
  lA3.next = &lA4;
  
  ListNode lB0(0);
  ListNode lB1(1);
  lB0.next = &lB1;
  ListNode lB2(2);
  lB1.next = &lB2;
  
  ListNode l0(0);
  ListNode l1(1);
  l0.next = &l1;
  ListNode l2(2);
  l1.next = &l2;
  
  lA4.next = &l0;
  lB2.next = &l0;
  
  ASSERT_EQ(&l0, s.getIntersectionNode(&lA0, &lB0));
}
