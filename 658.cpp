#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
private:
  struct p {
    int val;
    bool valid;
  };

public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    if (k == arr.size()) {
      return arr;
    }
    vector<int> ans;
    int idxOfMidpoint = -1;
    int bestValSoFar = 10e5 + 1;
    for (int i = arr.size() - 1; i > -1; --i) {
      if (abs(arr[i] - x) <= bestValSoFar) {
        bestValSoFar = abs(arr[i] - x);
        idxOfMidpoint = i;
      }
    }
    --k;
    ans.push_back(arr[idxOfMidpoint]);
    int l = idxOfMidpoint - 1, r = idxOfMidpoint + 1;
    while ((l > -1 || r < arr.size()) && k != 0) {
      p lp = {-1, false};
      p rp = {-1, false};
      if (l > -1) {
        lp.valid = true;
        lp.val = abs(arr[l] - x);
      }
      if (r < arr.size()) {
        rp.valid = true;
        rp.val = abs(arr[r] - x);
      }
      if (!lp.valid) {
        ans.push_back(arr[r]);
        ++r;
      } else if (!rp.valid) {
        ans.push_back(arr[l]);
        --l;
      } else if (rp.val < lp.val) {
        ans.push_back(arr[r]);
        ++r;
      } else {
        ans.push_back(arr[l]);
        --l;
      }
      --k;
    }
    sort(ans.begin(), ans.end());
    // for (auto i : ans) {
    //   cout << i << " ";
    // }
    // cout << "\n";
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> t1_in = {1, 3};
  s.findClosestElements(t1_in, 1, 2);
}