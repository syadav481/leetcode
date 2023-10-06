#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *f = head;
    ListNode *s = head;
    while (f && f->next) {
      s = s->next;
      f = f->next->next;
    }
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (s) {
      next = s->next;
      s->next = prev;
      prev = s;
      s = next;
    }
    int ans = INT32_MIN;
    while (prev && head) {
      ans = max(ans, prev->val + head->val);
      prev = prev->next;
      head = head->next;
    }
    return ans;
  }
};
int main() {}