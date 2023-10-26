#include <utility>
using std::pair;

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
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        auto dummy = new ListNode(0);
        auto head = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1)
        {
            head->next = l1;
        }
        else if (l2)
        {
            head->next = l2;
        }
        return dummy->next;
    }
    pair<ListNode *, ListNode *> split(ListNode *head)
    {
        auto f = head;
        auto s = head;
        while (f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        auto otherHalf = s->next;
        s->next = nullptr;
        return {head, otherHalf};
    }

    ListNode *mergeSort(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        auto pair = split(head);
        auto l1 = mergeSort(pair.first);
        auto l2 = mergeSort(pair.second);
        return merge(pair.first, pair.second);
    }

  public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};