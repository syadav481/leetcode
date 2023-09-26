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
  vector<vector<int>> ans;

public:
  void gen_subsets(vector<int> &nums, vector<int> &curr, int idx) {
    if (idx == nums.size()) {
      ans.push_back(curr);
      return;
    }
    curr.push_back(nums[idx]);
    gen_subsets(nums, curr, idx + 1);
    curr.pop_back();
    gen_subsets(nums, curr, idx + 1);
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    this->ans = {};
    vector<int> curr = {nums[0]};
    gen_subsets(nums, curr, 1);
    curr.pop_back();
    gen_subsets(nums, curr, 1);
    return ans;
  }
};
int main() {}