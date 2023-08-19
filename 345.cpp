#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    // v stores indices.
    vector<int> v;
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < s.size(); ++i) {
      if (vowels.find(s[i]) != string::npos) {
        v.push_back(i);
      }
    }
    for (int l = 0, r = v.size() - 1; l <= r; l++, r--) {
      swap(s[v[l]], s[v[r]]);
    }
    return s;
  }
};

int main() {
  // string t1 = Solution().reverseVowels("ai");
  // cout << t1 << endl;
  string t2 = Solution().reverseVowels(
      "QZrD2 7UL91z,i`O2ef:6e'2\"yP !:,U.:pX90PU3CXo'i!;3 `j 0?\"'hK8 ? "
      "BAjM2\"DBw?7!4R3?U2E8F2y!?3 R2!fw 6e!:0  ErCi98KM`,8`8648,mi3P0`,!5 "
      "E.?00J3A 52\"x8,tHy!'2!DLBbK'j!tt1C' "
      "7`JPulW\"\"uRTbr\"',\",U`ZOW5'\"LMDQDMJ\"'5WOZ`U,\",'\"rbTRu\"\"WluPJ`7 "
      "'C1tt!j'KbBJD!2'!yHt,8x\"25 A3J00?.E 5!,`0P3im,8468`8,`MK89iCrE  0:!e6 "
      "wf!2R 3?!y2F8E2U?3R4!7?wBD\"2MjAB ? 8Kh'\"?0 j` 3;!i'oXC3UP09Xp:.U,:! "
      "Py\"2'e6:fe2O`i,z19LU7 2DrZQ");
}