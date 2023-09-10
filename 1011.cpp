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
  bool feasible(vector<int> &weights, int capacity, int days) {
    int current_load = capacity, days_taken = 1;
    for (auto weight : weights) {
      current_load -= weight;
      if (current_load < 0) {
        current_load = capacity - weight;
        days_taken += 1;
      }
    }
    return days_taken <= days;
  }

public:
  int shipWithinDays(vector<int> &weights, int days) {
    int l = -1, r = 0;
    for (auto weight : weights) {
      if (l < weight) {
        l = weight;
      }
      r += weight;
    }
    while (l < r) {
      int m = (r + l) / 2;
      if (feasible(weights, m, days)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};

int main() {}