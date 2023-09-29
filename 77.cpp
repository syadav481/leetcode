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
  vector<vector<int>> combs;

public:
  void bt(int n, int k, int idx, vector<int> &curr) {
    if (curr.size() == k) {
      combs.push_back(curr);
    } else {
      if (curr.size() + (n - idx) < k - 1) {
        return;
      }
      for (int i = idx; i <= n; ++i) {
        curr.push_back(i);
        bt(n, k, i + 1, curr);
        curr.pop_back();
      }
    }
  }
  vector<vector<int>> combine(int n, int k) {
    ios_base::sync_with_stdio(false);
    vector<int> curr;
    bt(n, k, 1, curr);
    return combs;
  }
};
int main() {}