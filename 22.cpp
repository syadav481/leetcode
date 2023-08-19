#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  void recurse(int open, int close, vector<char> &s, vector<string> &ans,
               int n) {
    if (open == close && open == n) {
      ans.push_back(string(s.begin(), s.end()));
      return;
    }
    if (open < n) {
      s.push_back('(');
      recurse(open + 1, close, s, ans, n);
      s.pop_back();
    }
    if (close < open) {
      s.push_back(')');
      recurse(open, close + 1, s, ans, n);
      s.pop_back();
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    vector<char> s;
    recurse(0, 0, s, ans, n);
    return ans;
  }
};