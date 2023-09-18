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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (!list1){
		return list2; 
	}
	else if (!list2) {
		return list2; 
	}
 	ListNode* curr = NULL; 
	if (list1->val < list2->val) {
		curr = list1; 
		list1 = list1->next;
	}
	else {
		curr = list2; 
		list2 = list2->next;
	}
	ListNode* head = curr; 
	while (list1 && list2) {
		if (list1->val < list2->val) {
			curr->next = list1; 
			list1 = list1->next; 
		}
		else {
			curr->next = list2; 
			list2 = list2->next; 
		}
		curr = curr->next; 
	}
	if (list1) {
		curr->next = list1; 
	}
	else if (list2) {
		curr->next = list2; 
	}
	return head; 
    }
};
int main() {}
