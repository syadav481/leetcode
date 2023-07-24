#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int ans = 0;
    int l = 0, r = people.size() - 1;
    while (l <= r) {
      if (people[l] + people[r] <= limit) {
        l += 1;
        r -= 1;
        ans += 1;
      } else {
        ans += 1;
        r -= 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> t1_in = {3, 1, 7};
  cout << s.numRescueBoats(t1_in, 3) << endl;
}