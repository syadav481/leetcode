struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

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
class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        auto dummy = new ListNode(100000, head);
        auto p = dummy;
        auto c = head;
        while (c && c->next)
        {
            auto n = c->next;
            p->next = c->next;
            c->next = c->next->next;
            n->next = c;
            p = c;
            c = c->next;
        }
        return dummy->next;
    }
};