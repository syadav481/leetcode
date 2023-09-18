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
    ListNode* reverseList(ListNode* head) {
 	ListNode* curr = head; 
 	ListNode* next = NULL; 
 	ListNode* next = NULL; 
	while (curr){
		next = curr->next; 
		curr->next = prev; 
		prev = curr; 
		curr = next; 
	}
	return prev; 
    }
};
int main() {}
