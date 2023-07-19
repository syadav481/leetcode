#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    // iterate from 0 to nums.length() - 1
    // when i is even, if nums[i] > nums[i + 1], then swap nums[i] and nums[i +
    // 1]

    // when i is odd, if nums[i] < nums[i + 1], then swap nums[i] and nums[i
    // + 1]
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (i % 2 == 0 && nums[i] > nums[i + 1]) {
        swap(nums[i], nums[i + 1]);
      }
      if (i % 2 == 1 && nums[i] < nums[i + 1]) {
        swap(nums[i], nums[i + 1]);
      }
    }
    return;
  }
};

int main() {
  vector<int> test1 = {3, 5, 2, 1, 6, 4};
  Solution s;
  s.wiggleSort(test1);
  for (auto i : test1) {
    cout << i << " ";
  }
  cout << endl;
  vector<int> test2 = {6, 6, 5, 6, 3, 8};
  for (auto i : test2) {
    cout << i << " ";
  }
  cout << endl;
}