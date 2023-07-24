#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    for (int x = 0, y = 1, i = 2; i < nums.size(); ++i, ++x, ++y) {
      if ((nums[y] > nums[x] && nums[i] > nums[y]) ||
          (nums[x] > nums[y] && nums[y] > nums[i])) {
        swap(nums[y], nums[i]);
      }
    }
    return nums;
  }
};