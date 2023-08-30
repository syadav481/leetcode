#include <algorithm>
#include <cmath>
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
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    int lastWorkingElt = -1;
    while (l <= r) {
      int currentK = (l + r) / 2;
      int currentHours = 0;
      for (int pile : piles) {
        currentHours += ceil((double)pile / (double)currentK);
      }
      if (currentHours <= h) {
        r = currentK - 1;
        lastWorkingElt = currentK;
      } else {
        l = currentK + 1;
      }
    }
    return lastWorkingElt;
  }
};

int main() {
  vector<int> t1 = {30, 11, 23, 4, 20};
  Solution s;
  int res = s.minEatingSpeed(t1, 5);
  cout << res << endl;
  cout << "expected: " << 23 << endl;
}
