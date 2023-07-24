#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> k_tuple;
    kSum(ans, nums, k_tuple, 4, static_cast<long long>(target), 0);
    return ans;
  }
  void kSum(vector<vector<int>> &ans, vector<int> &nums, vector<int> &k_tuple,
            int k, long long t, int s) {
    if (k == 2) {
      int l = s;
      int r = nums.size() - 1;
      while (l < r) {
        int m = nums[l] + nums[r];
        if (m > t) {
          --r;
        } else if (m < t) {
          ++l;
        } else {
          vector<int> temp;
          for (auto x : k_tuple) {
            temp.push_back(x);
          }
          temp.push_back(nums[l]);
          temp.push_back(nums[r]);
          ans.push_back(temp);
          ++l;
          --r;
          while (l < r && nums[l] == nums[l - 1]) {
            ++l;
          }
        }
      }
    } else {
      int loopTop = nums.size() - k + 1;
      for (int i = s; i < loopTop; ++i) {
        if (i > s && nums[i] == nums[i - 1]) {
          continue;
        } else {
          k_tuple.push_back(nums[i]);
          kSum(ans, nums, k_tuple, k - 1, t - nums[i], i + 1);
          k_tuple.pop_back();
        }
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> t1_in = {2, 1, 0, -1};
  int target = 2;
  auto ans = s.fourSum(t1_in, target);
  for (auto v : ans) {
    cout << "[";
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "]" << endl;
  }
}
