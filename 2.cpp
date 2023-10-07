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
void print_list(const ListNode *a) {
  auto b = a;
  while (b) {
    cout << b->val << "-> ";
    b = b->next;
  }
  cout << "\n";
}
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ios_base::sync_with_stdio(false);
    if (!l1 && !l2) {
      return nullptr;
    }
    if (!l1) {
      return l2;
    } else if (!l2) {
      return l1;
    }
    ListNode *dummyHead = new ListNode();
    ListNode *curr = dummyHead;
    int carry = 0;
    while (l1 || l2 || carry != 0) {
      int sum = 0;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      sum += carry;
      carry = sum / 10;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
    }
    ListNode *ans = dummyHead->next;
    delete dummyHead;
    return ans;
  }
};

int main() {
  ListNode *l1 = new ListNode(2);
  ListNode *head1 = l1;
  l1->next = new ListNode(4);
  l1 = l1->next;
  l1->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  ListNode *head2 = l2;
  l2->next = new ListNode(6);
  l2 = l2->next;
  l2->next = new ListNode(4);

  ListNode *res = Solution().addTwoNumbers(head1, head2);
  print_list(res);
}