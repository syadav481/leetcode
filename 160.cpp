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
  ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  int getLength(ListNode *head) {
    int len = 0;
    while (head) {
      head = head->next;
      len += 1;
    }
    return len;
  }
  ListNode *advanceKPositions(ListNode *head, int k) {
    while (head && k > 0) {
      head = head->next;
      k -= 1;
    }
    return head;
  }

public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int sizeA = getLength(headA);
    int sizeB = getLength(headB);
    int diff = sizeA - sizeB;
    if (diff < 0) {
      headB = advanceKPositions(headB, -diff);
    } else {
      headA = advanceKPositions(headA, diff);
    }
    while (headA && headB) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return nullptr;
  }
};
int main() {}