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
  void bt(vector<int> &candidates, vector<int> &curr, int target, int idx) {
    if (target == 0) {
      ans.push_back(curr);
      return;
    } else if (target < 0) {
      return;
    }
    for (int i = idx; i < candidates.size(); ++i) {
      curr.push_back(candidates[i]);
      bt(candidates, curr, target - candidates[i], i);
      curr.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    this->ans = {};
    vector<int> curr = {};
    bt(candidates, curr, target, 0);
    return ans;
  }
};
int main() {}