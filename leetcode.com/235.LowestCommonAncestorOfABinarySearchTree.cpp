#include <gtest/gtest.h>
#include <vector>

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root == p) {
      return p;
    }
    if (root == q) {
      return q;
    }
    TreeNode * left = lowestCommonAncestor(root->left, p, q);
    TreeNode * right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr && right == nullptr) {
      return nullptr;
    }
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
    return root;
  }
};


class P235_LowestCommonAncestorOfABinarySearchTree_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {
     vector<int> input {6,2,0,-1,-1,4,3,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1};
     int index = 0;
     CreateNodes(root_, input, index);
  }
  virtual void TearDown() {
    DeleteNodes(root_);
  }
  
  int CreateNodes(TreeNode * & root, const vector<int> & input, int index) {
    if (index >= input.size() || input[index] == -1) {
      root = nullptr;
    } else {
      root = new TreeNode(input[index]);
      index = CreateNodes(root->left, input, index + 1);
      index = CreateNodes(root->right, input, index + 1);
    }
    return index;
  }
  
  void DeleteNodes(TreeNode * root) {
    if (root == nullptr) {
      return;
    }
    DeleteNodes(root->left);
    DeleteNodes(root->right);
    delete root;
  }

 protected:
  TreeNode * root_;
  Solution s;
};

TEST_F(P235_LowestCommonAncestorOfABinarySearchTree_Test, pass) {
  ASSERT_EQ(root_, s.lowestCommonAncestor(root_, root_->left, root_->right));
}

TEST_F(P235_LowestCommonAncestorOfABinarySearchTree_Test, fail) {
  ASSERT_EQ(root_->left, s.lowestCommonAncestor(root_, root_->left, root_->left->right));
}
