#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        return ans;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int m = nums[i] + nums[l] + nums[r];
        if (m > 0) {
          --r;
        } else if (m < 0) {
          ++l;
        } else {
          ans.push_back({nums[i], nums[l++], nums[r--]});
          while (l < nums.size() && nums[l] == nums[l - 1]) {
            ++l;
          }
        }
      }
    }
    return ans;
  }
};