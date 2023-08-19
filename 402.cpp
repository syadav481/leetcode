#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    // we can use the string itself as the monotonic stack.
    string ans;
    for (int i = 0; i < num.size(); ++i) {
      while (k > 0 && !ans.empty() && ans[ans.size() - 1] > num[i]) {
        k -= 1;
        ans.pop_back();
      }
      if (!ans.empty() || num[i] != '0') {
        ans.push_back(num[i]);
      }
    }
    while (k > 0 && !ans.empty()) {
      ans.pop_back();
      k -= 1;
    }
    if (ans.empty()) {
      return "0";
    }
    return ans;
  }
};

int main() {
  string t1 = Solution().removeKdigits("10001", 4);
  cout << t1 << endl;
}