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
  vector<vector<string>> suggestedProducts(vector<string> &p, string s) {
    sort(p.begin(), p.end()); // Sort words
    int n = p.size(), t, i = 0, j = n - 1, k = 0;
    vector<vector<string>> v(
        s.length()); // Total suggetions are same as length of word

    while (k < s.length() && i <= j) {
      while (i <= j && s[k] != p[i][k])
        i++; // Increment first pointer until first match

      while (j >= i && s[k] != p[j][k])
        j--; // decrement second pointer until first match

      for (t = i; t <= j && t <= i + 2; t++)
        v[k].push_back(p[t]); // Save words <=3
      k++;
    }
    return v;
  }
};
int main() {
  vector<string> t1_in = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
  Solution().suggestedProducts(t1_in, "mouse");
  cout << "done" << endl;
}
