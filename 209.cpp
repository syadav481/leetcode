#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0, curr = 0;
    int ans = __INT_MAX__;
    while (r < nums.size()) {
      curr += nums[r];
      while (curr >= target) {
        curr -= nums[l];
        ans = min(ans, r - l + 1);
        ++l;
      }
      ++r;
    }
    if (ans == __INT_MAX__) {
      return 0;
    }
    return ans;
  }
};