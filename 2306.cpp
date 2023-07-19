#include <assert.h>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  pair<char, string> split(const string &s) {
    char c = s[0];
    string temp = "";
    for (int i = 1; i < s.size(); ++i) {
      temp += s[i];
    }
    return {c, temp};
  }
  long long intersection(const set<string> &u, const set<string> &v) {
    long long res = 0;
    for (auto &s : u) {
      if (v.find(s) != v.end()) {
        ++res;
      }
    }
    return res;
  }

public:
  long long distinctNames(vector<string> &ideas) {
    long long count = 0;
    map<char, set<string>> m;
    for (auto &s : ideas) {
      auto p = split(s);
      m[p.first].insert(p.second);
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
      for (auto jt = m.begin(); jt != m.end(); ++jt) {
        if (it == jt) {
          continue;
        }
        long long ints = intersection(it->second, jt->second);
        count += (it->second.size() - ints) * (jt->second.size() - ints);
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  vector<string> t1 = {"coffee", "donuts", "time", "toffee"};
  assert(s.distinctNames(t1) == 6);
}