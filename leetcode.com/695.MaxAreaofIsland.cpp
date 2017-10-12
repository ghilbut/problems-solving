#include <algorithm>
#include <gtest/gtest.h>
#include <utils.h>


class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {

    const int row = grid.size();
    const int col = (row == 0 ? 0 : grid[0].size());

    int result = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        result = max(result, flip(grid, row, i, col, j));
      }
    }
    return result;
  }

  int flip(vector<vector<int>> & grid, const int row, int i, const int col, int j) {
        
    if (0 > i || i >= row || 0 > j || j >= col || grid[i][j] == 0) {
      return 0;
    }

    grid[i][j] = 0;
        
    int result = 1;
    result += flip(grid, row, i-1, col, j);
    result += flip(grid, row, i+1, col, j);
    result += flip(grid, row, i, col, j-1);
    result += flip(grid, row, i, col, j+1);
    return result;
  }

};


class P695_MaxAreaofIsland_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P695_MaxAreaofIsland_Test, case0) {

  auto i = MatrixFromString(""); 
  const int o = s.maxAreaOfIsland(i);
  ASSERT_EQ(0, o);
}

TEST_F(P695_MaxAreaofIsland_Test, case1) {

  auto i = MatrixFromString("[]"); 
  const int o = s.maxAreaOfIsland(i);
  ASSERT_EQ(0, o);
}

TEST_F(P695_MaxAreaofIsland_Test, case2) {

  auto i = MatrixFromString("[[]]"); 
  const int o = s.maxAreaOfIsland(i);
  ASSERT_EQ(0, o);
}

TEST_F(P695_MaxAreaofIsland_Test, case3) {

  auto i = MatrixFromString("[[0,0,0,0,0,0,0,0]]");
  const int o = s.maxAreaOfIsland(i);
  ASSERT_EQ(0, o);
}

TEST_F(P695_MaxAreaofIsland_Test, case4) {

  auto i = MatrixFromString(R"(
[[1,1,0,0,0],
 [1,1,0,0,0],
 [0,0,0,1,1],
 [0,0,0,1,1]]
  )"); 
  const int e = 4;
  const int o = s.maxAreaOfIsland(i);
  ASSERT_EQ(e, o);
}

TEST_F(P695_MaxAreaofIsland_Test, case5) {

  auto i = MatrixFromString(R"(
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
  )"); 
  const int e = 6;
  const int o = s.maxAreaOfIsland(i);
  ASSERT_EQ(e, o);
}
