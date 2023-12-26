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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        while (head) {
            ListNode* node = head;
            head = head->next;
            node->next = nullptr;
            // find insertion point
            if (!dummy->next) {
                dummy->next = node; 
            } else {
                ListNode* prev = dummy;
                ListNode* curr = dummy->next;
                while (curr && curr->val < node->val) {
                    curr = curr->next;
                    prev = prev->next;
                }
                // at this point, prev points right before insertion point
                prev->next = node;
                node->next = curr;
            }
        }
        return dummy->next;
    }
};
int main() {}