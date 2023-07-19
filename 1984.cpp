#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    int minVal = __INT_MAX__;
    sort(nums.begin(), nums.end());
    for (int l = 0; l < nums.size() - k + 1; ++l) {
      minVal = min(minVal, nums[l + k - 1] - nums[l]);
    }
    return minVal;
  }
};