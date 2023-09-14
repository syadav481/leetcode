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
  struct compare {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
      return a[0] < b[0];
    }
  };

public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {
    unordered_map<int, vector<int>> m;
    for (auto &p : items1) {
      if (m.count(p[0])) {
        m[p[0]][1] += p[1];
      } else {
        m[p[0]] = p;
      }
    }
    for (auto &p : items2) {
      if (m.count(p[0])) {
        m[p[0]][1] += p[1];
      } else {
        m[p[0]] = p;
      }
    }
    vector<vector<int>> ans;
    for (auto &p : m) {
      ans.push_back(p.second);
    }
    sort(ans.begin(), ans.end(), compare());
    return ans;
  }
};
int main() {
  vector<vector<int>> items1 = {{1, 1}, {4, 5}, {3, 8}};
  vector<vector<int>> items2 = {{3, 1}, {1, 5}};
  Solution().mergeSimilarItems(items1, items2);
}