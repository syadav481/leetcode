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
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    vector<int> pairs;
    sort(potions.begin(), potions.end());
    for (int spell : spells) {
      int l = 0, r = potions.size() - 1;
      while (l <= r) {
        int m = (r - l) / 2 + l;
        bool feasible = (long long)potions[m] * spell >= success;
        if (feasible) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      pairs.push_back(potions.size() - l);
    }
    return pairs;
  }
};
int main() {}