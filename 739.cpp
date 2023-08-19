#include <vector>
using namespace std;

class Solution {
private:
  struct Datum {
    int val;
    int index;
  };

public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<Datum> s;
    vector<int> ans(temperatures.size());
    int i = 0;
    for (auto temp : temperatures) {
      while (!s.empty() && s.back().val < temp) {
        ans[s.back().index] = i - s.back().index;
        s.pop_back();
      }
      s.push_back({temp, i});
      ++i;
    }
    return ans;
  }
};