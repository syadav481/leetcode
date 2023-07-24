#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0, mindex = 0;
    for (int i = 0; i < prices.size(); ++i) {
      if (prices[mindex] > prices[i]) {
        mindex = i;
      } else {
        ans = max(ans, prices[i] - prices[mindex]);
      }
    }
    return ans;
  }
};