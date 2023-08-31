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
  bool isPerfectSquare(int num) {

    if (num <= 1) // square root of 0 is 0, square root of 1 is 1, square root
                  // of a negative is an imaginary.
      return num;

    // we use the Newton–Raphson method to find the square root

    double tolerance = 1e-7;

    double x0 = num;
    double x = x0 - (x0 * x0 - num) / (2 * x0);

    while (abs(x - x0) > tolerance) {
      x0 = x;
      x = x0 - (x0 * x0 - num) / (2 * x0);
    }

    // if the square root is an integer, newX will = x.
    // if it is not an integer, newX != x
    // if newX*newX is not roughly equal to our number, it must be because its a
    // floating point val if it's a floating point val, its not a perfect
    // square.
    int newX = x;
    if (abs(newX * newX - num) < 1e-4) {
      return true;
    }
    return false;
  }
};
int main() {}