#include <gtest/gtest.h>

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q-> val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};


class P100_SameTree_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P100_SameTree_Test, return_true_when_both_of_roots_are_null) {
  ASSERT_TRUE(s.isSameTree(nullptr, nullptr));
}

TEST_F(P100_SameTree_Test, return_false_when_one_of_root_is_null_and_another_is_not_null) {
  TreeNode root(0);
  ASSERT_FALSE(s.isSameTree(&root, nullptr));
  ASSERT_FALSE(s.isSameTree(nullptr, &root));
}

TEST_F(P100_SameTree_Test, compare_values_when_both_of_roots_are_single_level) {
  TreeNode l_root(0);
  TreeNode r_root(0);
  ASSERT_TRUE(s.isSameTree(&l_root, &r_root));
  r_root.val = 1;
  ASSERT_FALSE(s.isSameTree(&l_root, &r_root));
}

TEST_F(P100_SameTree_Test, compare_values_when_any_children_has_different_values) {
  TreeNode l_root(0);
  TreeNode l_l(1);
  l_root.left = &l_l;
  TreeNode l_r(2);
  l_root.right = &l_r;
  TreeNode l_ll(3);
  l_l.left = &l_ll;
  
  TreeNode r_root(0);
  TreeNode r_l(1);
  r_root.left = &r_l;
  TreeNode r_r(2);
  r_root.right = &r_r;
  TreeNode r_ll(3);
  r_l.left = &r_ll;

  ASSERT_TRUE(s.isSameTree(&l_root, &r_root));

  r_ll.val = 4;

  ASSERT_FALSE(s.isSameTree(&l_root, &r_root));
}

TEST_F(P100_SameTree_Test, compare_values_when_any_children_has_different_node) {
  TreeNode l_root(0);
  TreeNode l_l(1);
  l_root.left = &l_l;
  TreeNode l_r(2);
  l_root.right = &l_r;
  TreeNode l_ll(3);
  l_l.left = &l_ll;
  
  TreeNode r_root(0);
  TreeNode r_l(1);
  r_root.left = &r_l;
  TreeNode r_r(2);
  r_root.right = &r_r;
  TreeNode r_ll(3);
  r_l.left = &r_ll;

  ASSERT_TRUE(s.isSameTree(&l_root, &r_root));

  r_l.left = nullptr;
  r_l.right = &r_ll;

  ASSERT_FALSE(s.isSameTree(&l_root, &r_root));
}
