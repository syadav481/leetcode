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
private:
  struct Datum {
    size_t startIndex;
    int height;
  };

public:
  int largestRectangleArea(vector<int> &heights) {
    vector<Datum> stack;
    int maxArea = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
      size_t start = i;
      while (!stack.empty() && stack.back().height > heights[i]) {
        size_t startIndex = stack.back().startIndex;
        int height = stack.back().height;
        stack.pop_back();
        maxArea = max(maxArea, (int)(i - startIndex) * height);
        start = startIndex;
      }
      stack.push_back({start, heights[i]});
    }
    for (int i = 0; i < stack.size(); ++i) {
      size_t index = stack[i].startIndex;
      int height = stack[i].height;
      maxArea = max(maxArea, (int)(heights.size() - index) * height);
    }
    return maxArea;
  }
};
int main() {
  vector<int> t1_in = {2, 1, 5, 6, 2, 3};
  int t1_res = Solution().largestRectangleArea(t1_in);
  cout << t1_res << endl;
  cout << "expected 10" << endl;
}