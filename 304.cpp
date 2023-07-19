#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

class NumMatrix {
private:
  vector<vector<int>> m;

public:
  NumMatrix(vector<vector<int>> &matrix) {
    m.resize(matrix.size() + 1);
    for (auto &v : m) {
      v.resize(matrix[0].size() + 1);
    }
    // prefix sum of the current row + the thing above it.
    for (int i = 1; i < m.size(); ++i) {
      int accumulate = 0;
      for (int j = 1; j < m[0].size(); ++j) {
        accumulate += matrix[i - 1][j - 1];
        m[i][j] = accumulate + m[i - 1][j];
      }
    }
    return;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int res = 0;
    int wholeArea = m[row2 + 1][col2 + 1];
    int leftBox = m[row2 + 1][col1];
    int upBox = m[row1][col2 + 1];
    int overlap = m[row1][col1];
    res = wholeArea - leftBox - upBox + overlap;
    return res;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
  vector<vector<int>> mat1 = {{3, 0, 1, 4, 2},
                              {5, 6, 3, 2, 1},
                              {1, 2, 0, 1, 5},
                              {4, 1, 0, 1, 7},
                              {1, 0, 3, 0, 5}};
  NumMatrix soln(mat1);
  assert(soln.sumRegion(2, 1, 4, 3) == 8);
  assert(soln.sumRegion(1, 1, 2, 2) == 11);
  assert(soln.sumRegion(1, 2, 2, 4) == 12);
}