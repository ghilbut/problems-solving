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
  bool isBalanced(TreeNode* root) {
    int lv;
    return isBalanced(root, lv);
  }

  bool isBalanced(TreeNode * root, int & lv) {
    if (root == nullptr) {
      lv = 0;
      return true;
    }
    int llv, rlv;
    bool left = isBalanced(root->left, llv);
    if (!left) {
      return false;
    }
    bool right = isBalanced(root->right, rlv);
    if (!right) {
      return false;
    }

    int d = llv - rlv;
    lv = (llv < rlv ? rlv : llv) + 1;
    return -2 < d && d < 2;
  }
};


class P110_BalancedBinaryTree_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P110_BalancedBinaryTree_Test, return_true_when_root_is_null) {
  ASSERT_TRUE(s.isBalanced(nullptr));
}

TEST_F(P110_BalancedBinaryTree_Test, return_true_lv1) {
  TreeNode root(0);
  ASSERT_TRUE(s.isBalanced(&root));
  
  TreeNode l(1);
  root.left = &l;
  ASSERT_TRUE(s.isBalanced(&root));
  
  TreeNode r(2);
  root.right = &r;
  ASSERT_TRUE(s.isBalanced(&root));
}

TEST_F(P110_BalancedBinaryTree_Test, return_false) {
 
  TreeNode root(0);

  TreeNode l(1);
  root.left = &l;
  TreeNode r(2);
  root.right = &r;
  
  TreeNode ll(3);
  l.left = &ll;
  TreeNode lll(4);
  ll.right = &lll;
  
  ASSERT_FALSE(s.isBalanced(&root));
}
