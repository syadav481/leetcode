#include <vector>
using namespace std;

class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    bool changed = false;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (i == nums.size() - 1 || num <= nums[i + 1]) {
        continue;
      }
      if (changed) {
        return false;
      }
      changed = true;
      if (i == 0 || nums[i - 1] <= nums[i + 1]) {
        nums[i] = nums[i + 1];
      } else {
        nums[i + 1] = nums[i];
      }
    }
    return true;
  }
};
