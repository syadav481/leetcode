#include <vector>
using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int s = 0, f = 0, s2 = 0;
        do
        {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);
        while (s != s2)
        {
            s = nums[s];
            s2 = nums[s2];
        }
        return s;
    }
};