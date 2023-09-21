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
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int r = m - 1; r > -1; --r) {
      for (int c = n - 1; c > -1; --c) {
        int current = dungeon[r][c];
        if (r == m - 1 && c == n - 1) {
          dp[r][c] = min(current, 0);
        } else if (r < m - 1 && c < n - 1) {
          dp[r][c] = min(0, current + max(dp[r + 1][c], dp[r][c + 1]));
        } else if (r == m - 1) {
          dp[r][c] = min(0, current + dp[r][c + 1]);
        } else if (c == n - 1) {
          dp[r][c] = min(0, current + dp[r + 1][c]);
        }
      }
    }
    return abs(dp[0][0]) + 1;
  }
};
int main() {
  vector<vector<int>> t1_in = {{-3}, {-7}};
  int a = Solution().calculateMinimumHP(t1_in);
  cout << a << endl;
}