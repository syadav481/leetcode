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
  int longestPalindrome(string s) {
    unordered_map<char, int> freq_map;
    for (auto c : s) {
      freq_map[c] += 1;
    }
    int count = 0;
    bool oddFound = false;
    for (auto &p : freq_map) {
      if (p.second % 2 == 1) {
        oddFound = true;
        count += p.second - 1;
      } else {
        count += p.second;
      }
    }
    return oddFound ? count + 1 : count;
  }
};
int main() {}