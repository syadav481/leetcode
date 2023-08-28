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
    int l = 0, r = nums.size();
    while (l < r) {
      int m = (r + l) / 2;
      if (target > nums[m]) {
        l = m + 1;
      } else if (target < nums[m]) {
        r = m;
      } else {
        return m;
      }
    }
    return -1;
  }
};

int main() {}