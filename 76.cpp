#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (t.size() == 0) {
      return "";
    }
    unordered_map<char, int> tm;
    unordered_map<char, int> m;
    for (auto c : t) {
      ++tm[c];
    }
    int l = 0, lenAns = 0xfffffff, matches = 0;
    pair<int, int> ans = {-1, -1};
    for (int r = 0; r < s.size(); ++r) {
      char curr = s[r];
      ++m[curr];
      if (tm.find(curr) != tm.end() && tm[curr] == m[curr]) {
        ++matches;
      }
      while (matches == tm.size()) {
        if (r - l + 1 < lenAns) {
          ans = {l, r};
          lenAns = r - l + 1;
        }
        --m[s[l]];
        if (tm.find(s[l]) != tm.end() && m[s[l]] < tm[s[l]]) {
          matches -= 1;
        }
        ++l;
      }
    }
    if (lenAns == 0xfffffff) {
      return "";
    }
    string answer;
    for (auto it = s.begin() + ans.first; it < s.begin() + ans.second + 1;
         ++it) {
      answer.push_back(*it);
    }
    return answer;
  }
};

int main() {
  auto a = Solution().minWindow("ADOBECODEBANC", "ABC");
  cout << a << endl;
}