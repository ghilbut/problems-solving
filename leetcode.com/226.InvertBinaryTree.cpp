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
  TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) {
      TreeNode * tmp = invertTree(root->left);
      root->left = invertTree(root->right);
      root->right = tmp;
    }
    return root;
  }
};


class P226_InvertBinaryTree_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P226_InvertBinaryTree_Test, case0) {
  TreeNode root(4);
  TreeNode l(2);
  root.left = &l;
  TreeNode r(7);
  root.right = &r;
  TreeNode ll(1);
  l.left = &ll;
  TreeNode lr(3);
  l.right = &lr;
  TreeNode rl(6);
  r.left = &rl;
  TreeNode rr(9);
  r.right = &rr;
  TreeNode * result = s.invertTree(&root);
  ASSERT_EQ(4, result->val);
  ASSERT_EQ(7, result->left->val);
  ASSERT_EQ(2, result->right->val);
  ASSERT_EQ(9, result->left->left->val);
  ASSERT_EQ(6, result->left->right->val);
  ASSERT_EQ(3, result->right->left->val);
  ASSERT_EQ(1, result->right->right->val);
}