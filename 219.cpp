#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
        return true;
      }
      m[nums[i]] = i;
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> t1_in = {1, 2, 3, 1, 2, 3};
  bool res = s.containsNearbyDuplicate(t1_in, 2);
  cout << res << endl;
}