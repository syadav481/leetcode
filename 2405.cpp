#include <set>
#include <string>
using namespace std;
class Solution {
public:
  int partitionString(string s) {
    int uniques = 0;
    int ans = 1;
    for (char c : s) {
      if (uniques & (1 << (c - 'a'))) {
        uniques = 0;
        ans += 1;
      }
      uniques += (1 << (c - 'a'));
    }
    return ans;
  }
};