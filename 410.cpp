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
  int splitArray(vector<int> &nums, int k) {
    int l = 0;
    int r = 0;
    for (int i : nums) {
      l = max(i, l);
      r += i;
    }
    while (l < r) {
      int m = (r - l) / 2 + l;
      int partitions = 1;
      int curr_sum = 0;
      for (int num : nums) {
        if (num + curr_sum <= m) {
          curr_sum += num;
        } else {
          curr_sum = num;
          partitions += 1;
        }
      }
      if (partitions <= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
int main() {}