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
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int max = -1;
    for (int i = 0; i < rectangles.size(); ++i) {
      max = min(rectangles[i][0], rectangles[i][1]);
    }
    int count = 0;
    for (int i = 0; i < rectangles.size(); ++i) {
      count += min(rectangles[i][0], rectangles[i][1]) == max ? 1 : 0;
    }
    return count;
  }
};
int main() {}