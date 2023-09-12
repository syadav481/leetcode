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
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
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
      if (nums[m] > target) {
        r = m - 1;
      } else if (nums[m] < target) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return -1;
  }
};
int main() {
  vector<int> t_in = {1, 3};
  auto res = Solution().search(t_in, 3);
  cout << res << endl;
}