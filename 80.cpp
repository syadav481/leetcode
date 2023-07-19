#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int l = 0, r = 0;
    for (; r < nums.size(); ++r) {
      int count = 1;
      while (r + 1 < nums.size() && nums[r] == nums[r + 1]) {
        ++count;
        ++r;
      }
      for (int i = 0; i < min(2, count); ++i) {
        nums[l] = nums[r];
        l += 1;
      }
    }
    return l;
  }
};

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  Solution s;
  s.removeDuplicates(nums);
  for (auto i : nums) {
    cout << i << " ";
  }
}