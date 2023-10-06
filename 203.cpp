#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
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
  ListNode *removeElements(ListNode *head, int val) {
    if (!head) {
      return head;
    }
    while (head && head->val == val) {
      head = head->next;
    }
    ListNode *ans = head;
    ListNode *curr = head;
    if (!curr) {
      return curr;
    }
    ListNode *next = curr->next;
    while (curr && next) {
      if (next->val == val) {
        curr->next = next->next;
        next = next->next;
      } else {
        curr = curr->next;
        next = next->next;
      }
    }
    return ans;
  }
};
int main() {}