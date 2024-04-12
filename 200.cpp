#include <vector>
using std::vector;

class Solution {

public:
  int island_count = 0;
  int numIslands(vector<vector<char>> &grid) {
    for (size_t r = 0; r < grid.size(); ++r) {
      for (size_t c = 0; c < grid[r].size(); ++c) {
        if (grid[r][c] == '1') {
          dfs(r, c, grid);
          ++island_count;
        }
      }
    }
    return island_count;
  }
  void dfs(size_t row, size_t col, vector<vector<char>> &grid) {
    if (row >= grid.size() || col >= grid[row].size()) {
      return;
    }
    if (grid[row][col] == '0') {
      return;
    }
    grid[row][col] = '0';
    dfs(row + 1, col, grid);
    dfs(row - 1, col, grid);
    dfs(row, col + 1, grid);
    dfs(row, col - 1, grid);
  }
};
