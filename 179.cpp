#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  struct Comparator {
    bool operator()(int a, int b) const {
      string num1 = to_string(a) + to_string(b);
      string num2 = to_string(b) + to_string(a);
      long num1_i = stoul(num1);
      long num2_i = stoul(num2);
      if (num1_i > num2_i) {
        return true;
      } else {
        return false;
      }
    }
  };
  string largestNumber(vector<int> &nums) {
    bool allZeros = true;
    for (int i : nums) {
      if (i != 0) {
        allZeros = false;
      }
    }
    if (allZeros) {
      return "0";
    }
    string ans = "";
    sort(nums.begin(), nums.end(), Comparator());
    for (auto c : nums) {
      ans += to_string(c);
    }
    return ans;
  }
};

int main() {
  vector<int> test1 = {10, 2};
  vector<int> test2 = {3, 30, 34, 5, 9};
  vector<int> test3 = {999999991, 9};
  vector<int> test4 = {999999998, 999999997, 999999999};
  Solution s;
  assert(s.largestNumber(test1) == "210");
  assert(s.largestNumber(test2) == "9534330");
  assert(s.largestNumber(test3) == "9999999991");
  assert(s.largestNumber(test4) == "999999999999999998999999997");
}