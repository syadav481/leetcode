#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> v(128);
    int l = 0, r = 0;
    int ans = 0;
    while (r < s.size()) {
      ++v[s[r]];
      while (v[s[r]] > 1) {
        --v[s[l++]];
      }
      ans = max(ans, r - l + 1);
      ++r;
    }
    return ans;
  }
};

int main() {
  cout << "test 1, expect 3" << endl;
  cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
}