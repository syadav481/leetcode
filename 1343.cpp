#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int l = 0, r = 0;
    int ans = 0;
    int accumulate = 0;
    while (r < arr.size()) {
      accumulate += arr[r++];
      if (r - l == k) {
        double avg = accumulate / k;
        if (avg >= threshold) {
          ans += 1;
        }
        accumulate -= arr[l++];
      }
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<int> t1_in = {2, 2, 2, 2, 5, 5, 5, 8};
  int ans = s.numOfSubarrays(t1_in, 3, 4);
  cout << ans << endl;
}