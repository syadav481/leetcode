#include <iostream>
using std::cout;
using std::ostream;

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
ostream &operator<<(ostream &os, ListNode *l)
{
    ListNode *curr = l;
    while (curr)
    {
        os << curr->val << " ";
        curr = curr->next;
    }
    os << "\n";
    return os;
}
class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {
        return mergesort(head);
    }
    struct Pair
    {
        ListNode *u;
        ListNode *v;
    };
    ListNode *mergesort(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        cout << "presplit:\t" << head;
        Pair p = split(head);
        cout << "split l1:\t" << p.u;
        cout << "split l2:\t" << p.v;
        auto u = mergesort(p.u);
        auto v = mergesort(p.v);
        return merge(u, v);
    }
    ListNode *merge(ListNode *u, ListNode *v)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (u || v)
        {
            ListNode *temp = nullptr;
            if (u && v)
            {
                if (u->val < v->val)
                {
                    temp = u;
                    u = u->next;
                }
                else
                {
                    temp = v;
                    v = v->next;
                }
            }
            else if (u)
            {
                temp = u;
                u = u->next;
            }
            else if (v)
            {
                temp = v;
                v = v->next;
            }
            curr->next = temp;
            curr = curr->next;
        }
        return dummy->next;
    }
    Pair split(ListNode *head)
    {
        Pair p;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        auto f = dummy;
        auto s = dummy;
        while (f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        auto temp = s;
        s = s->next;
        temp->next = nullptr;
        p.u = dummy->next;
        p.v = s;
        return p;
    }
};
