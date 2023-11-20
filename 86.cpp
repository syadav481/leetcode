// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr)
//     {
//     }
//     ListNode(int x) : val(x), next(nullptr)
//     {
//     }
//     ListNode(int x, ListNode *next) : val(x), next(next)
//     {
//     }
// };

class Solution
{
  public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *l2 = new ListNode(0);
        ListNode *l1 = new ListNode(0);
        ListNode *ret1 = l1;
        ListNode *ret2 = l2;
        while (head)
        {
            ListNode *next = head->next;
            head->next = nullptr;
            if (head->val < x)
            {
                l1->next = head;
                l1 = l1->next;
            }
            else
            {
                l2->next = head;
                l2 = l2->next;
            }
            head = next;
        }
        l1->next = ret2->next;
        return ret1->next;
    }
};