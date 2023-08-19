#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    if (s.size() % 2 == 1) {
      return false;
    }
    unordered_map<char, char> m = {{'}', '{'}, {')', '('}, {']', '['}};
    stack<char> st;
    for (auto c : s) {
      if (m.find(c) == m.end()) {
        st.push(c);
      } else if (st.size() > 0 && m[c] == st.top()) {
        st.pop();
      } else {
        return false;
      }
    }
    return st.size() == 0;
  }
};

int main() { bool val = Solution().isValid("(("); }