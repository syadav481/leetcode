#include <map>
#include <vector>
using namespace std;
class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int ans = 0, curr = 0;
    // storing the last index of a fruit-type
    map<int, int> lastIndex;
    for (int i = 0; i < fruits.size(); ++i) {
      lastIndex[fruits[i]] = i;
      // if there are more than 2 distinct fruit types.
      if (lastIndex.size() > 2) {
        int out = -1;
        // look in the last indices map for the fruit type that was last.
        // this will be the fruit type that isn't the current one and isn't the
        // previous one. Hence, fruits[i] and fruits[i - 1]
        for (auto &[type, _] : lastIndex) {
          if (type != fruits[i - 1] && type != fruits[i]) {
            out = type;
            break;
          }
        }
        curr = i - lastIndex[out];
        lastIndex.erase(out);
      } else {
        ++curr;
      }
      ans = max(ans, curr);
    }
    return ans;
  }
};

int main() {}