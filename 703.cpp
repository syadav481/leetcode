#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class KthLargest
{
    priority_queue<int> minPQ;
    priority_queue<int, vector<int>, std::greater<int>> maxPQ;

  public:
    KthLargest(int k, vector<int> &nums)
    {
        for (int i : nums)
        {
            maxPQ.push(i);
            if (maxPQ.size() > k)
            {
                maxPQ.pop();
            }
        }
    }

    int add(int val)
    {
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{
}