#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
class Solution {
public:
  int guessNumber(int n) {
    if (guess(n) == 0) {
      return n;
    } else if (guess(1) == 0) {
      return 1;
    }
    int l = 0;
    while (l < n) {
      int m = (n - l) + n / 2;
      if (guess(m) == -1) {
        n = m;
      } else if (guess(m) == 1) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return n;
  }
};
int main() {}