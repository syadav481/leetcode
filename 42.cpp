#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int l = 1, r = height.size() - 2;
    int mr = height[height.size() - 1], ml = height[0];
    int ans = 0;
    while (l <= r) {
      if (ml < mr) {
        if (ml < height[l]) {
          ml = height[l];
        } else {
          ans += ml - height[l];
        }
        ++l;
      } else {
        if (mr < height[r]) {
          mr = height[r];
        } else {
          ans += mr - height[r];
        }
        --r;
      }
    }
    return ans;
  }
};