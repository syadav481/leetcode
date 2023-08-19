#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int l = 0;
    deque<Datum> q; // indices
    vector<int> ans;
    for (int r = 0; r < nums.size(); ++r) {
      // if the number on the right is greater than the one at the back of the
      // deque, remove it. do this until the deque is either empty, or the
      // number of the right is not greater than the one on the back.
      while (q.size() != 0 && q.back().val < nums[r]) {
        q.pop_back();
      }
      // add the right element index
      q.push_back({r, nums[r]});
      // if the index of the element at the left / front of the dequeu is behind
      // the left index, pop it.
      if (l > q.front().index) {
        q.pop_front();
      }
      // add the element at the left to the answer.
      if (r + 1 >= k) {
        ans.push_back(q.front().val);
        ++l;
      }
    }
    return ans;
  }

private:
  struct Datum {
    int index;
    int val;
  };
};

int main() {
  vector<int> t2_in = {1, 3, 1, 2, 0, 5};
  auto val2 = Solution().maxSlidingWindow(t2_in, 3);
  vector<int> t1_in = {7, 2, 4};
  auto val = Solution().maxSlidingWindow(t1_in, 2);
}