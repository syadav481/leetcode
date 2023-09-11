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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n;
    while (l < r) {
      int midPoint = (r - l) / 2 + l;
      int row = midPoint / n, col = midPoint % n;
      if (matrix[row][col] < target) {
        l = midPoint + 1;
      } else if (matrix[row][col] > target) {
        r = midPoint;
      } else {
        return true;
      }
    }
    return false;
  }
};
int main() {}