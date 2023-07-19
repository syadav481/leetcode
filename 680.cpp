#include <assert.h>
#include <string>
using namespace std;

class Solution {
private:
  bool helper(const string &s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }

public:
  bool validPalindrome(string s) {
    bool del = false;
    for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
      char left = s[l], right = s[r];
      if (left == right) {
        continue;
      } else {
        // This works because only one deletion is allowed.
        // When a mismatch occurs, we can delete either l or r.
        // We can only do this once. So in the event of a mismatch.
        // we simply need to find the result of either deleting l
        // or deleting r.
        // Then we can return whether either one of those is true.
        return helper(s, l + 1, r) || helper(s, l, r - 1);
      }
    }
    return true;
  }
};

int main() {
  assert(Solution().validPalindrome("ebcbbececabbacecbbcbe") == true);
}