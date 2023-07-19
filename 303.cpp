#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

class NumArray {
public:
  vector<int> prefix;
  NumArray(vector<int> &nums) {
    int acc = 0;
    for (int i = 0; i < nums.size(); ++i) {
      acc += nums[i];
      prefix.push_back(acc);
    }
  }

  int sumRange(int left, int right) {
    int res = 0;
    if (left == 0) {
      return prefix[right];
    }
    return prefix[right] - prefix[left - 1];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
  vector<int> t1 = {-2, 0, 3, -5, 2, -1};
  NumArray n(t1);
  assert(n.sumRange(0, 2) == 1);
  assert(n.sumRange(2, 5) == -1);
  assert(n.sumRange(0, 5) == -3);
}