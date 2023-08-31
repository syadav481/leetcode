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
  vector<int> sortedSquares(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, i = nums.size() - 1;
    vector<int> ans(nums.size());
    while (l <= r) {
      if (abs(nums[l]) > abs(nums[r])) {
        ans[i--] = nums[l] * nums[l++];
      } else {
        ans[i--] = nums[r] * nums[r--];
      }
    }
    return ans;
  }
};
int main() {
  vector<int> t1_in = {-4, -1, 0, 3, 10};
  auto t1_o = Solution().sortedSquares(t1_in);
}