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
    bool isPalindrome(ListNode* head) {
 	auto slow = head, fast = head;        
	// move slow and fast pointers
	while (fast && fast->next) {
		fast = fast->next->next; 
		slow = slow->next; 
	}
	if (fast && !fast->next) {
		slow = slow->next; 
	}

	/*
	 * 1 2 3 4 5 
	 *     s   f
	 * 1 2 3 4 
	 *     s   f
	 */
	// reverse second half of list
	ListNode* prev = nullptr; 
	ListNode* next = nullptr; 
	while (slow){
		next = slow->next; 
		slow->next = prev; 
		prev = slow;
		slow = next; 
	}
	slow = prev; 
	fast = head; 
	while (fast && slow) {
		if (fast->val != slow->val) {
			return false;
		}
		slow = slow->next; 
		fast = fast->next; 
	}
	return true; 
    }
    void print_list(ListNode* n) {
	while (n) {
		cout << n->val << "->"; 
		n = n->next;
	}
	cout << "\n"; 
    }
};
