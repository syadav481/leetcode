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
  int climbStairs(int n) {
    int bc = 1, nc = 0;
    for (int i = 0; i < n; ++i) {
      int temp = bc;
      bc += nc;
      nc = temp;
    }
    return bc;
  }
};
int main() {}