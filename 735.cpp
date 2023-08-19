#include <vector>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> s = {};
    int l = -1, r = 1;
    for (auto a : asteroids) {
      s.push_back(a);
      if (s.size() > 1) {
        r = s[s.size() - 1];
        l = s[s.size() - 2];
      }
      while (l > 0 && r < 0) {
        if (l + r > 0) {
          s.pop_back();
        } else if (l + r < 0) {
          s.pop_back();
          s.pop_back();
          s.push_back(r);
        } else {
          s.pop_back();
          s.pop_back();
        }
        if (s.size() > 1) {
          r = s[s.size() - 1];
          l = s[s.size() - 2];
        } else {
          r = 1;
        }
      }
    }
    return s;
  }
};
