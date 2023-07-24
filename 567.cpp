#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }
    int c1[26] = {};
    int c2[26] = {};
    for (int i = 0; i < s1.size(); ++i) {
      ++c1[idx(s1[i])];
      ++c2[idx(s2[i])];
    }
    int matches = 0;
    for (int i = 0; i < 26; ++i) {
      if (c1[i] == c2[i]) {
        ++matches;
      }
    }
    if (matches == 26) {
      return true;
    }
    for (int r = s1.size(), l = 0; r < s2.size(); ++r, ++l) {
      int index = idx(s2[r]);
      ++c2[index];
      if (c2[index] == c1[index]) {
        ++matches;
      } else if (c2[index] == c1[index] + 1) {
        --matches;
      }
      index = idx(s2[l]);
      --c2[index];
      if (c2[index] == c1[index]) {
        ++matches;
      } else if (c2[index] == c1[index] - 1) {
        --matches;
      }
      if (matches == 26) {
        return true;
      }
    }
    return false;
  }

private:
  size_t idx(char c) { return static_cast<size_t>(c - 'a'); }
};

int main() {}