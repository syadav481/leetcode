#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  void reorderList(ListNode *head) {

    ListNode *slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = NULL, *cur = slow;
    while (cur) {
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }

    ListNode *newhead = prev;
    ListNode *head1 = head, *head2 = newhead;
    while (head2->next) {
      ListNode *temp1 = head1->next;
      head1->next = head2; // connecting

      ListNode *temp2 = head2->next;
      head2->next = temp1; // connecting

      head1 = temp1;
      head2 = temp2;
    }
  }
};
int main() {}