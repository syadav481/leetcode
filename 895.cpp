#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class FreqStack {
private:
  vector<vector<int>> stacks;
  unordered_map<int, int> frequencies;

public:
  FreqStack() {}

  void push(int val) {
    ++frequencies[val];
    if (frequencies[val] <= stacks.size()) {
      stacks[frequencies[val] - 1].push_back(val);
    } else {
      stacks.push_back({val});
    }
  }

  int pop() {
    int val = stacks.back().back();
    stacks.back().pop_back();
    --frequencies[val];
    if (stacks.back().size() == 0) {
      stacks.pop_back();
    }
    return val;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
  FreqStack f;
  f.push(5);
  f.push(7);
  f.push(5);
  f.push(7);
  f.push(4);
}