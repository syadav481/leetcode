#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  struct Datum {
    int pos;
    int speed;
    double time;
  };
  struct Compare {
    bool operator()(const Datum &a, const Datum &b) const {
      if (a.pos == b.pos) {
        return a.time > b.time;
      }
      return a.pos < b.pos;
    }
  };

public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<Datum> v;
    for (int i = 0; i < position.size(); ++i) {
      double t = (target - position[i]) / (double)speed[i];
      v.push_back({position[i], speed[i], t});
    }
    sort(v.begin(), v.end(), Compare());
    vector<Datum *> stack;
    for (int i = v.size() - 1; i > -1; --i) {
      if (stack.empty() || stack.back()->time < v[i].time) {
        stack.push_back(&v[i]);
      }
    }
    return stack.size();
  }
};

int main() {
  vector<int> t1_p_in = {10, 8, 0, 5, 3};
  vector<int> t1_s_in = {2, 4, 1, 1, 3};
  int i = Solution().carFleet(12, t1_p_in, t1_s_in);
  cout << i << endl;
}