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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int totalGasDifferential = 0, runningTotalGas = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      int diff = gas[i] - cost[i];
      totalGasDifferential += diff;
      runningTotalGas += diff;
      if (runningTotalGas < 0) {
        start = i + 1;
        runningTotalGas = 0;
      }
    }
    if (totalGasDifferential < 0) {
      return -1;
    }
    return start;
  }
};
int main() {}