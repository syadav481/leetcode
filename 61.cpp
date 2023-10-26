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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // base case:
        if (!head || !head->next || k == 0)
            return head;
        // find the size
        int n = 0;
        for (auto curr = head; curr; curr = curr->next)
            n += 1;
        // update k
        k %= n;
        if (k == 0)
            return head;
        auto s = head;
        auto f = head;
        while (f && f->next)
        {
            if (k <= 0)
            {
                s = s->next;
            }
            f = f->next;
            k -= 1;
        }
        f = s->next;
        s->next = nullptr;
        auto new_head = f;
        for (; f && f->next; f = f->next)
            ;
        f->next = head;
        return new_head;
    }
};