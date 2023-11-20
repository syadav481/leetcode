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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *l1 = dummy;
        ListNode *l2 = dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            l1 = l1->next;
        }
        for (int i = 0; i < right; ++i)
        {
            l2 = l2->next;
        }
        ListNode *curr = l1->next;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        // disconnect ends
        ListNode *end = curr; 
        l1->next = nullptr;
        ListNode *right_side = l2->next;
        l2->next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        }
        l1->next = prev; 
        end->next = right_side; 
        return dummy->next;
    }
};