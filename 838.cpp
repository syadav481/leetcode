#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string pushDominoes(string dominoes) {
    queue<int> q;
    for (int i = 0; i < dominoes.size(); ++i) {
      if (dominoes[i] != '.') {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      char c = dominoes[i];
      if (c == 'L') {
        if (i > 0 && dominoes[i - 1] == '.') {
          dominoes[i - 1] = 'L';
          q.push(i - 1);
        }
      } else if (c == 'R') {
        if (i + 1 < dominoes.size() && dominoes[i + 1] == '.') {
          if (i + 2 < dominoes.size() && dominoes[i + 2] == 'L') {
            q.pop();
          } else {
            q.push(i + 1);
            dominoes[i + 1] = 'R';
          }
        }
      }
    }
    return dominoes;
  }
};

int main() {
  string test1 = "RR.L";
  string test2 = ".L.R...LR..L..";
  Solution s;
  assert(s.pushDominoes(test1) == "RR.L");
  cout << s.pushDominoes(test2) << endl;
  assert(s.pushDominoes(test2) == "LL.RR.LLRRLL..");
}