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
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }
    if (nums[0] > nums[1]) {
      return 0;
    }
    for (int i = 1, j = 0; i < n; ++i, ++j) {
      if (nums[i] < nums[j]) {
        return j;
      }
    }
    return n - 1;
  }
};
int main() {}