#include <gtest/gtest.h>


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode * cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      ListNode * next = cur->next;
      if (cur->val == next->val) {
        cur->next = next->next;
        // delete next
      } else {
        cur = next;
      }
    }
    return head;
  }
};


class P83_RemoveDuplicatesFromSortedList_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P83_RemoveDuplicatesFromSortedList_Test, case0_0) {
  ListNode il0(1);
  ListNode il1(1);
  il0.next = &il1;
  ListNode il2(2);
  il1.next = &il2;
  ListNode * output = s.deleteDuplicates(&il0);
  while (output != nullptr && output->next != nullptr) {
    ASSERT_NE(output->val, output->next->val);
    output = output->next;
  }
}

TEST_F(P83_RemoveDuplicatesFromSortedList_Test, case0_1) {
  ListNode il0(1);
  ListNode il1(1);
  il0.next = &il1;
  ListNode il2(2);
  il1.next = &il2;
  ListNode * output = s.deleteDuplicates(&il0);
  ASSERT_NE(nullptr, output);
  ASSERT_EQ(1, output->val);
  output = output->next;
  ASSERT_NE(nullptr, output);
  ASSERT_EQ(2, output->val);
  output = output->next;
  ASSERT_EQ(nullptr, output);
}

TEST_F(P83_RemoveDuplicatesFromSortedList_Test, case1_0) {
  ListNode il0(1);
  ListNode il1(1);
  il0.next = &il1;
  ListNode il2(2);
  il1.next = &il2;
  ListNode il3(3);
  il2.next = &il3;
  ListNode il4(3);
  il3.next = &il4;
  ListNode * output = s.deleteDuplicates(&il0);
  while (output != nullptr && output->next != nullptr) {
    ASSERT_NE(output->val, output->next->val);
    output = output->next;
  }
}

TEST_F(P83_RemoveDuplicatesFromSortedList_Test, case1_1) {
  ListNode il0(1);
  ListNode il1(1);
  il0.next = &il1;
  ListNode il2(2);
  il1.next = &il2;
  ListNode il3(3);
  il2.next = &il3;
  ListNode il4(3);
  il3.next = &il4;
  ListNode * output = s.deleteDuplicates(&il0);
  ASSERT_NE(nullptr, output);
  ASSERT_EQ(1, output->val);
  output = output->next;
  ASSERT_NE(nullptr, output);
  ASSERT_EQ(2, output->val);
  output = output->next;
  ASSERT_NE(nullptr, output);
  ASSERT_EQ(3, output->val);
  output = output->next;
  ASSERT_EQ(nullptr, output);
}

TEST_F(P83_RemoveDuplicatesFromSortedList_Test, case2_0) {
  ListNode il0(1);
  ListNode il1(1);
  il0.next = &il1;
  ListNode il2(1);
  il1.next = &il2;
  ListNode il3(1);
  il2.next = &il3;
  ListNode il4(1);
  il3.next = &il4;
  ListNode * output = s.deleteDuplicates(&il0);
  while (output != nullptr && output->next != nullptr) {
    ASSERT_NE(output->val, output->next->val);
    output = output->next;
  }
}

TEST_F(P83_RemoveDuplicatesFromSortedList_Test, case2_1) {
  ListNode il0(1);
  ListNode il1(1);
  il0.next = &il1;
  ListNode il2(1);
  il1.next = &il2;
  ListNode il3(1);
  il2.next = &il3;
  ListNode il4(1);
  il3.next = &il4;
  ListNode * output = s.deleteDuplicates(&il0);
  ASSERT_NE(nullptr, output);
  ASSERT_EQ(1, output->val);
  output = output->next;
  ASSERT_EQ(nullptr, output);
}
