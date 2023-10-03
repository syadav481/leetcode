#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return head;
    }
    ListNode *curr = head;
    ListNode *next = head->next;
    while (curr && next) {
      if (curr->val == next->val) {
        curr->next = next->next;
        next = curr->next;
      } else {
        curr = curr->next;
        if (curr) {
          next = curr->next;
        }
      }
    }
    return head;
  }
};
int main() {}