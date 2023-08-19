#include <queue>

using namespace std;

class MyStack {
private:
  queue<int> q1;
  queue<int> q2;

public:
  MyStack() {}

  void push(int x) { q1.push(x); }

  int pop() {
    while (q1.size() > 1) {
      q2.push(q1.front());
      q1.pop();
    }
    int temp = q1.front();
    q1.pop();
    swap(q1, q2);
    return temp;
  }

  int top() {
    for (int n = q1.size(); n > 1; --n) {
      q1.push(q1.front());
      q1.pop();
    }
    int temp = q1.front();
    q1.pop();
    q1.push(temp);
    return temp;
  }

  bool empty() { return q1.size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */