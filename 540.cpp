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
  int singleNonDuplicate(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (r + l) / 2;
      if (m % 2 == 1) {
        m -= 1;
      }
      if (nums[m] != nums[m + 1]) {
        r = m;
      } else {
        l = m + 2;
      }
    }
    return nums[l];
  }
};
int main() {}