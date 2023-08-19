#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool isNumeric(const std::string &str) {
    for (char c : str) {
      if (!std::isdigit(c)) {
        return false;
      }
    }
    return true;
  }

public:
  string decodeString(string s) {
    vector<string> stack;
    for (auto c : s) {
      if (c == ']') {
        string temp;
        while (!stack.empty() && *stack.rbegin() != "[") {
          if (*stack.rbegin() != "[") {
            string backOfStack = *stack.rbegin();
            reverse(backOfStack.begin(), backOfStack.end());
            temp += backOfStack;
            stack.pop_back();
          } else {
            stack.pop_back();
          }
        }
        stack.pop_back();
        reverse(temp.begin(), temp.end());
        string num;
        while (!stack.empty() && isNumeric(*stack.rbegin())) {
          num += *stack.rbegin();
          stack.pop_back();
        }
        reverse(num.begin(), num.end());
        int multiplier = stoi(num);
        string multipliedString;
        for (int i = 0; i < multiplier; ++i) {
          multipliedString += temp;
        }
        stack.push_back(multipliedString);
      } else {
        stack.push_back(string(1, c));
      }
    }
    string res;
    for (auto &elt : stack) {
      res += elt;
    }
    return res;
  }
};

int main() {
  string res1 = Solution().decodeString("3[a]2[bc]");
  cout << res1 << endl;
}