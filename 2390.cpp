#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  string removeStars(string s) {
    vector<char> st;
    for (auto c : s) {
      if (c == '*') {
        st.pop_back();
      } else {
        st.push_back(c);
      }
    }
    string ans(st.begin(), st.end());
    return ans;
  }
};