#include <assert.h>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, x = nums1.size() - 1;
    while (i > -1 || j > -1) {
      if (i > -1 && j > -1) {
        if (nums1[i] > nums2[j]) {
          nums1[x--] = nums1[i--];
        } else {
          nums1[x--] = nums2[j--];
        }
      } else if (i > -1) {
        nums1[x--] = nums1[i--];
      } else {
        nums1[x--] = nums2[j--];
      }
    }
  }
};

int main() {
  vector<int> t1_n1 = {1, 2, 3, 0, 0, 0};
  vector<int> t1_n2 = {2, 5, 6};
  Solution s;
  s.merge(t1_n1, 3, t1_n2, 3);
  vector<int> ans = {1, 2, 2, 3, 5, 6};
  for (int i = 0; i < ans.size(); ++i) {
    assert(t1_n1[i] == ans[i]);
  }
}