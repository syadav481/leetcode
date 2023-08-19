#include <string>
using namespace std;
class Solution {
public:
  int minFlips(string s) {
    int n = s.size();
    int ans = INT32_MAX;
    int diff1 = 0, diff2 = 0;
    for (int i = 0; i < 2 * n; ++i) {
      // purpose of this is to convert the elts in the string to numbers 1,0
      if (i < n) {
        s[i] -= '0';
      }
      if (i % 2 != s[i % n]) {
        diff2 += 1;
      }
      if ((i + 1) % 2 != s[i % n]) {
        diff1 += 1;
      }
      // purpose of this is to check if you've wrapped around.
      if (i >= n) {
        if ((i - n) % 2 != s[i - n]) {
          diff2 -= 1;
        }
        if ((i - n + 1) % 2 != s[i - n]) {
          diff1 -= 1;
        }
      }
      if (i >= n - 1) {
        ans = min({ans, diff1, diff2});
      }
    }
    return ans;
  }
};