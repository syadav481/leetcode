// Given two strings s and p, return an array of all the start indices of p's
// anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int i = 0, j = 0, n = s.size(), m = p.size();
    if (n < m) {
      return {};
    }
    int sm[26] = {0};
    int pm[26] = {0};
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
      ++pm[s[i] - 'a'];
    }
    while (i < n && j < m) {
      ++sm[s[i] - 'a'];
      ++i;
      ++j;
    }
    j = 0;
    if (check(pm, sm)) {
      ans.push_back(0);
    }
    while (i < n) {
      ++sm[s[i] - 'a'];
      --sm[s[j] - 'a'];
      if (check(sm, pm)) {
        ans.push_back(j + 1);
      }
      ++i;
    }
    return ans;
  }

  bool check(int arr[26], int brr[26]) {
    for (int i = 0; i < 26; ++i) {
      if (arr[i] != brr[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  auto res = s.findAnagrams("cbaebabacd", "abc");
  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;
}
