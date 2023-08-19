#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> stack;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        continue;
      }
      string temp;
      for (; i < path.size() && path[i] != '/'; ++i) {
        temp += path[i];
      }
      if (temp == ".") {
        continue;
      } else if (temp == "..") {
        if (!stack.empty()) {
          stack.pop_back();
        }
      } else {
        stack.push_back(temp);
      }
    }
    string canonical_path;
    if (stack.empty()) {
      return "/";
    }
    for (auto &s : stack) {
      canonical_path += "/" + s;
    }
    return canonical_path;
  }
};

int main() {
  string t_1 = Solution().simplifyPath("/../.");
  cout << t_1 << endl;
}