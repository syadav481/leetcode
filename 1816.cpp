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
  string truncateSentence(string s, int k) {
    string ans;
    for (char c : s) {
      if (c == ' ') {
        k -= 1;
      }
      if (k == 0) {
        return ans;
      } else {
        ans.push_back(c);
      }
    }
    return ans;
  }
};
int main() {}