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

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) {
      return head;
    }
    if (!head->next && n > 0) {
      return nullptr;
    } else {
      return head;
    }
    auto slow = head;
    auto fast = head;
    for (int i = 0; i < n && head; ++i) {
      fast = fast->next;
    }
    fast = fast->next;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};
int main() {}