#include <map>
#include <string>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int l = 0, ans = 0, maxF = 0;
    map<int, int> counts;
    for (int r = 0; r < s.size(); ++r) {
      counts[s[r]] = 1 + counts[s[r]];
      maxF = max(maxF, counts[s[r]]);
      int windowLength = r - l + 1;
      if (windowLength - maxF > k) {
        counts[s[l]] -= 1;
        l += 1;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};