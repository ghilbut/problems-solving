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
  int maxDepth(TreeNode * root) {
    if (root == nullptr) {
      return 0;
    }
    const int left = maxDepth(root->left);
    const int right = maxDepth(root->right);
    return 1 + max(left, right);
  }
};


class MaximumDepthOfBinaryTreeTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(MaximumDepthOfBinaryTreeTest, return_0_when_input_is_null) {
  ASSERT_EQ(0, s.maxDepth(nullptr));
}

TEST_F(MaximumDepthOfBinaryTreeTest, return_1_when_root_only) {
  TreeNode root(0);
  ASSERT_EQ(1, s.maxDepth(&root));
}

TEST_F(MaximumDepthOfBinaryTreeTest, return_4) {
  // lv4
  TreeNode rootlll(0);
  // lv3
  TreeNode rootrr(0);
  TreeNode rootlr(0);
  TreeNode rootll(0);
  rootll.left = &rootlll;
  // lv2
  TreeNode rootr(0);
  rootr.left = &rootrr;
  TreeNode rootl(0);
  rootl.left = &rootll;
  rootl.right = &rootlr;
  // lv1
  TreeNode root(0);
  root.left = &rootl;
  root.right = &rootr;

  ASSERT_EQ(4, s.maxDepth(&root));
}
