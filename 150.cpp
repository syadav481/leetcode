#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;
    for (auto &token : tokens) {
      if (token == "+") {
        int arg1 = s.top();
        s.pop();
        int arg2 = s.top();
        s.pop();
        s.push(arg2 + arg1);
      } else if (token == "-") {
        int arg1 = s.top();
        s.pop();
        int arg2 = s.top();
        s.pop();
        s.push(arg2 - arg1);
      } else if (token == "*") {
        int arg1 = s.top();
        s.pop();
        int arg2 = s.top();
        s.pop();
        s.push(arg1 * arg2);
      } else if (token == "/") {
        int arg1 = s.top();
        s.pop();
        int arg2 = s.top();
        s.pop();
        s.push(arg2 / arg1);
      } else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};