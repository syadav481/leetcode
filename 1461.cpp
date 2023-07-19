#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    // make an array of each possible bitstring of length k
    // make a window of length k bits.
    // as you iterate through s, check if the bitstring-window matches the
    // string.
    if (k > s.size()) {
      return false;
    }
    int numStrings = 1 << k;
    bool bitStrings[numStrings];
    for (int i = 0; i < numStrings; ++i) {
      bitStrings[i] = true;
    }
    int window = 0;
    int bitmask = (1 << k) - 1;
    int total = numStrings;
    // init window
    for (int i = 0; i < k - 1; ++i) {
      window = (window << 1) + (s[i] == '1');
    }
    // iterate through s
    for (int i = k - 1; i < s.size(); ++i) {
      window = (window << 1) + (s[i] == '1');
      window = window & bitmask;
      if (bitStrings[window]) {
        bitStrings[window] = false;
        --total;
      }
      if (total == 0) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  string test1_in = "00110110";
  int k1_in = 2;
  bool t1_o = true;
  string test2_in = "0110";
  int k2_in = 1;
  bool t2_o = true;
  string test3_in = "0110";
  int k3_in = 2;
  bool t3_o = false;
  Solution s;
  string test4_in = "00110";
  int k4_in = 2;
  bool t4_o = true;
  // write test cases:
  assert(s.hasAllCodes(test1_in, k1_in) == t1_o);
  assert(s.hasAllCodes(test2_in, k2_in) == t2_o);
  assert(s.hasAllCodes(test3_in, k3_in) == t3_o);
  assert(s.hasAllCodes(test4_in, k4_in) == t4_o);
  assert(s.hasAllCodes("0", 20) == false);
  assert(s.hasAllCodes("01100", 2) == true);
}