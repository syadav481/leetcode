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
  void printList(ListNode *curr) {
    while (curr) {
      cout << curr->val << ", ";
      curr = curr->next;
    }
    cout << endl;
  }

public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *s = new ListNode(0, head);
    ListNode *f = head;
    while (f && n) {
      f = f->next;
      n -= 1;
    }
    if (!f) {
      return head->next;
    }
    while (f) {
      f = f->next;
      s = s->next;
    }
    s->next = s->next->next;
    return head;
  }
};
int main() {}
