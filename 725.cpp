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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans; 
        int N = 0;
        for (auto curr = head; curr; curr = curr->next)
            N += 1; 
        int remainder = N % k; 
        int group_size = N / k; 
        auto curr = head; 
        for (int i = 0; i < k; ++i) {
            auto head = curr;
            int iter = group_size + (i < remainder) - 1; 
            for (int j = 0; j < iter; ++j) {
                if (curr)
                    curr = curr->next; 
            }
            if (curr) {
                auto temp = curr->next; 
                curr->next = nullptr; 
                curr = temp;
            }
            ans.push_back(head); 
        }
        return ans; 
    }
};
int main() {}