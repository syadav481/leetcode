#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
	Node* curr = root; 
	Node* next = nullptr; 
	if (root){ 
		next = root->left; 	
	}
	while (curr and next){
		curr->left->next = curr->right; 
		if (curr->next){
			curr->right->next = curr->next->left; 	
		}
		curr = curr->next; 
		if (!curr){
			curr = next; 
			next = curr->left; 
		}
	}
	return root; 
    }
};
int main() {}
