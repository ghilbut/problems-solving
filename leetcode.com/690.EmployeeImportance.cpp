#include <gtest/gtest.h>
#include <queue>
#include <unordered_map>
#include <utils.h>


class Employee {
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {

    unordered_map<int, Employee*> tmp;
    for (auto * e : employees) {
      tmp[e->id] = e;
    }

    int importance = 0;
    queue<int> subordinates;
    subordinates.push(id);
    do {
      id = subordinates.front();
      subordinates.pop();
      auto * e = tmp[id];
      importance += e->importance;
      for (auto s : e->subordinates) {
        subordinates.push(s);
      }
    } while (!subordinates.empty());

    return importance;
  }
};


class P690_EmployeeImportance_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
 protected:
  Solution s;
};

TEST_F(P690_EmployeeImportance_Test, case0) {

  Employee e0 { 1, 2, {2} };
  Employee e1 { 2, 3, {} };
  vector<Employee*> i0 { &e0, &e1 };
  int i1 = 2;
  int o = s.getImportance(i0, i1);
  ASSERT_EQ(3, o);
}

TEST_F(P690_EmployeeImportance_Test, case1) {

  Employee e0 { 1, 5, {2, 3} };
  Employee e1 { 2, 3, {} };
  Employee e2 { 3, 3, {} };
  vector<Employee*> i0 { &e0, &e1, &e2 };
  int i1 = 1;
  int o = s.getImportance(i0, i1);
  ASSERT_EQ(11, o);
}
