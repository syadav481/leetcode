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
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size(), found = -1;
    while (l < r) {
      int m = (l + r) / 2;
      if (target > nums[m]) {
        l = m + 1;
      } else if (target < nums[m]) {
        r = m;
      } else {
        found = m;
        break;
      }
    }
    if (found != -1) {
      return found;
    }
    return l;
  }
};

int main() {}