#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int mod = 1e9 + 7;
    vector<int> p(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      p[i] = p[i - 1] * 2 % mod;
    }
    int ans = 0;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      if (nums[l] + nums[r] > target) {
        --r;
      } else {
        ans = (ans + p[r - l++]) % mod;
      }
    }
    return ans % mod;
  }
};

int main() {
  Solution s;
  vector<int> t1_in = {3, 5, 6, 7};
  int t1_o = s.numSubseq(t1_in, 9);
  cout << t1_o << endl;
}