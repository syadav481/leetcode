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
  bool isSameAfterReversals(int num) { return (num % 10 != 0 || num < 10); }
};
int main() {}