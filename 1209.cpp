#include <string>
#include <vector>

using namespace std;
class Solution {
private:
  struct Datum {
    char character;
    int frequency;
  };

public:
  string removeDuplicates(string s, int k) {
    vector<Datum> v;
    string ans;
    for (auto c : s) {
      if (!v.empty() && v[v.size() - 1].character == c) {
        v[v.size() - 1].frequency += 1;
      } else {
        v.push_back({c, 1});
      }

      if (v[v.size() - 1].frequency == k) {
        v.pop_back();
      }
    }
    for (auto &d : v) {
      ans += string(d.frequency, d.character);
    }
    return ans;
  }
};