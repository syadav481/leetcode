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
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (r - l) / 2 + l;
      if (nums[m] > nums[r]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return nums[l];
  }
};
int main() {}