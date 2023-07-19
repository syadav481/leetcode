#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long curr = 0;
    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        ++curr;
        sum += curr;
      } else {
        curr = 0;
      }
    }
    return sum;
  }
};

int main() {
  vector<int> t1 = {1, 3, 0, 0, 2, 0, 0, 4};
  assert(Solution().zeroFilledSubarray(t1) == 6);
  vector<int> t2 = {0, 0, 0, 2, 0, 0};
  assert(Solution().zeroFilledSubarray(t2) == 9);
}