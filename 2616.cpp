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
  bool feasible(vector<int> &nums, int p, int max_acceptable_difference) {
    int countOfPairs = 0;
    for (int i = 0; i < nums.size() - 1;) {
      if (nums[i + 1] - nums[i] <= max_acceptable_difference) {
        countOfPairs += 1;
        i += 2;
        if (countOfPairs >= p) {
          return true;
        }
      } else {
        i += 1;
      }
    }
    return false;
  }

public:
  int minimizeMax(vector<int> &nums, int p) {
    if (p == 0) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = nums[nums.size() - 1] - nums[0];
    while (l < r) {
      int m = (r - l) / 2 + l;
      if (feasible(nums, p, m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
int main() {
  vector<int> t1_in = {0, 5, 3, 4};
  Solution().minimizeMax(t1_in, 0);
}