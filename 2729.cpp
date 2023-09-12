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
  bool isFascinating(int n) {
    set<int> s;
    int n_c = n;
    while (n_c != 0) {
      int digit = n_c % 10;
      n_c /= 10;
      if (digit == 0)
        return false;
      if (s.find(digit) == s.end()) {
        s.insert(digit);
      } else {
        return false;
      }
    }
    n_c = 2 * n;
    while (n_c != 0) {
      int digit = n_c % 10;
      n_c /= 10;
      if (digit == 0)
        return false;
      if (s.find(digit) == s.end()) {
        s.insert(digit);
      } else {
        return false;
      }
    }
    n_c = 3 * n;
    while (n_c != 0) {
      int digit = n_c % 10;
      n_c /= 10;
      if (digit == 0)
        return false;
      if (s.find(digit) == s.end()) {
        s.insert(digit);
      } else {
        return false;
      }
    }
    return s.size() == 9;
  }
};
int main() {}