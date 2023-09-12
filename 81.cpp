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
public:
  bool search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      while (l < nums.size() - 1 && nums[l] == nums[l + 1]) {
        l += 1;
      }
      while (r > 0 && nums[r] == nums[r - 1]) {
        r -= 1;
      }
      int m = (r - l) / 2 + l;
      if (nums[m] > nums[r]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    int pivot = l;
    l = 0, r = nums.size() - 1;
    if (nums[pivot] <= target && target <= nums[r]) {
      l = pivot;
    } else {
      r = pivot;
    }
    while (l <= r) {
      int m = (r - l) / 2 + l;
      if (target < nums[m]) {
        r = m - 1;
      } else if (target > nums[m]) {
        l = m + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
int main() {
  vector<int> t1_in = {2, 5, 6, 0, 0, 1, 2};
  Solution().search(t1_in, 2);
}