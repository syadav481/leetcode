#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int calPoints(vector<string> &operations) {
    vector<int> s;
    for (auto &operation : operations) {
      if (operation == "D") {
        s.push_back(s[s.size() - 1] * 2);
      } else if (operation == "C") {
        s.pop_back();
      } else if (operation == "+") {
        s.push_back(s[s.size() - 1] + s[s.size() - 2]);
      } else {
        s.push_back(stoi(operation));
      }
    }
    int sum = 0;
    for (int i : s) {
      sum += i;
    }
    return sum;
  }
};

int main() {
  vector<string> t1_in = {"5", "2", "C", "D", "+"};
  int ans1 = Solution().calPoints(t1_in);
}
