#include <gtest/gtest.h>
#include <stack>

using namespace std;


class Queue {
 public:
  // Push element x to the back of queue.
  void push(int x) {
    in.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    touch();
    if (!out.empty()) {
      out.pop();
    }
  }

  // Get the front element.
  int peek(void) {
    touch();
    return (out.empty() ? 0 : out.top());
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return (in.empty() && out.empty());
  }

 private:
  void touch() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
  }

  stack<int> in;
  stack<int> out;
};


class P232_ImplementQueueUsingStacks_Test : public ::testing::Test {
 protected:
  virtual void SetUp() {
    q = new Queue();
  }
  virtual void TearDown() {
    delete q;
  }
 protected:
  Queue * q;
};

TEST_F(P232_ImplementQueueUsingStacks_Test, empty) {
  ASSERT_TRUE(q->empty());
}

TEST_F(P232_ImplementQueueUsingStacks_Test, push_and_pop) {
  q->push(1);
  q->push(2);
  q->push(3);

  ASSERT_EQ(1, q->peek());
  ASSERT_EQ(1, q->peek());
  ASSERT_EQ(1, q->peek());
  q->pop();
  ASSERT_EQ(2, q->peek());
  q->pop();
  
  q->push(4);
  q->push(5);
  
  ASSERT_EQ(3, q->peek());
  q->pop();
  ASSERT_EQ(4, q->peek());
  q->pop();
  ASSERT_EQ(5, q->peek());
  q->pop();
  ASSERT_EQ(0, q->peek());
  q->pop();
  ASSERT_EQ(0, q->peek());
  q->pop();
  
  q->push(6);
  q->push(7);
  
  ASSERT_EQ(6, q->peek());
  q->pop();
  ASSERT_EQ(7, q->peek());
  q->pop();
}
