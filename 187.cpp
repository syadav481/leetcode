#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    set<string> ans;
    set<string> seen;
    if (s.size() < 9) {
      return {};
    }
    for (int i = 0; i < s.size() - 9; ++i) {
      string temp = "";
      for (int j = 0; j < 10; ++j) {
        temp += s[j + i];
      }
      if (seen.find(temp) != seen.end()) {
        ans.insert(temp);
      } else {
        seen.insert(temp);
      }
    }
    vector<string> result(ans.begin(), ans.end());
    return result;
  }
};

int main() {
  string test1_in = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> test1_o = {"AAAAACCCCC", "CCCCCAAAAA"};
  string test2_in = "AAAAAAAAAAAAA";
  vector<string> test2_o = {"AAAAAAAAAA"};
  Solution s;
  assert(s.findRepeatedDnaSequences(test1_in) == test1_o);
  assert(s.findRepeatedDnaSequences(test2_in) == test2_o);
  vector<string> empty = {};
  assert(s.findRepeatedDnaSequences("A") == empty);
  string test3_in = "AAAAAAAAAAA";
  vector<string> test3_o = {"AAAAAAAAAA"};
  assert(s.findRepeatedDnaSequences(test3_in) == test3_o);
}