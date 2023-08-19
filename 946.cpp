#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int i = 0;
    stack<int> s;
    for (int elt : pushed) {
      s.push(elt);
      while (s.size() != 0 && i < popped.size() && s.top() == popped[i]) {
        s.pop();
        ++i;
      }
    }
    return s.size() == 0;
  }
};