#include <set>
#include <string>
using namespace std;
class Solution {
private:
  bool in(char ch, set<char> &vowels) {
    return vowels.find(ch) != vowels.end();
  }

public:
  int maxVowels(string s, int k) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int ans = 0, curr = 0;
    for (int i = 0; i < k; ++i) {
      if (in(s[i], vowels)) {
        curr += 1;
      }
    }
    ans = max(ans, curr);
    for (int i = k; i < s.size(); ++i) {
      if (in(s[i - k], vowels)) {
        curr -= 1;
      }
      if (in(s[i], vowels)) {
        curr += 1;
      }
      ans = max(ans, curr);
    }
    return ans;
  }
};