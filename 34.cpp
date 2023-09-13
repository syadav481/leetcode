#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
  int lower_bound(vector<int> &nums, int l, int r, int target) {
    while (l <= r) {
      int m = (r - l) / 2 + l;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return l;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int start = lower_bound(nums, l, r, target);
    int end = lower_bound(nums, l, r, target + 1) - 1;
    if (start < nums.size() && nums[start] == target) {
      return {start, end};
    }
    return {-1, -1};
  }
};
int main() {
  vector<int> t1_in = {5, 7, 7, 8, 8, 10};
  cout << Solution().searchRange(t1_in, 8)[0];
  cout << " " << Solution().searchRange(t1_in, 8)[1];
}