#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
  string target;

public:
  bool exist(vector<vector<char>> &board, string word) {
    target = word;
    for (size_t r = 0; r < board.size(); ++r) {
      for (size_t c = 0; c < board[r].size(); ++c) {
        if (backtrack(board, r, c, 0)) {
          return true;
        }
      }
    }
    return false;
  }
  // Index keeps track of where in the current word you are
  bool backtrack(vector<vector<char>> &board, size_t row, size_t col,
                 size_t index) {
    if (index == target.size()) {
      return true;
    }
    if (row > board.size() || col > board[row].size()) {
      return false;
    }
    char original_value = board[row][col];
    if (original_value != target[index]) {
      return false;
    }
    // mark current position as visited
    board[row][col] = '#';
    // recurse
    bool ans = backtrack(board, row + 1, col, index + 1) ||
               backtrack(board, row - 1, col, index + 1) ||
               backtrack(board, row, col + 1, index + 1) ||
               backtrack(board, row, col - 1, index + 1);
    // unmark current position
    board[row][col] = original_value;
    return ans;
  }
};
