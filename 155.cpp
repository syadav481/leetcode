#include <stack>
using namespace std;

class MinStack {
  struct Datum {
    int val;
    int currMin;
  };
  stack<Datum> s;

public:
  MinStack() {}

  void push(int val) {
    if (s.empty()) {
      s.push({val, val});
    } else {
      s.push({val, min(val, s.top().currMin)});
    }
  }

  void pop() { s.pop(); }

  int top() { return s.top().val; }

  int getMin() { return s.top().currMin; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */