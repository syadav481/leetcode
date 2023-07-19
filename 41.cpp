#include <math.h>
#include <vector>
using namespace std;

class Solution {
private:
  bool inBounds(int a, vector<int> &nums) {
    if (a < nums.size() && a > -1) {
      return true;
    }
    return false;
  }

public:
  int firstMissingPositive(vector<int> &nums) {
    for (int &i : nums) {
      if (i < 0) {
        i = 0;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      int idx = abs(nums[i]) - 1;
      if (inBounds(idx, nums)) {
        int val = nums[idx];
        if (val == 0) {
          nums[idx] = -(nums.size() + 1);
        } else {
          nums[idx] = -abs(nums[idx]);
        }
      }
    }
    for (int cand = 1; cand < nums.size() + 1; ++cand) {
      if (nums[cand - 1] >= 0) {
        return cand;
      }
    }
    return nums.size() + 1;
  }
};

int main() { Solution s; }