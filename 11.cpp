#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1, maxWater = 0;
    for (; l < r;) {
      int prod = min(height[l], height[r]) * (r - l);
      maxWater = max(maxWater, prod);
      height[l] > height[r] ? --r : ++l;
    }
    return maxWater;
  }
};