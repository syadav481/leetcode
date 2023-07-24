#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = 0;
    int ans = 1, total = 0;
    while (r < nums.size()) {
      total += nums[r];
      while (nums[r] * (r - l + 1) > total + k) {
        total -= nums[l];
        ++l;
      }
      ans = max(ans, r - l + 1);
      ++r;
    }
    return ans;
  }
};