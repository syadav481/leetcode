# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n, curr = 0, head 
        while curr: 
            curr = curr.next 
            n += 1
        remainder = n % k 
        group_size = n // k
        # each group has n // k elements. 
        # if there is a remainder, add 1 elt to each group. 
        ans = [] 
        curr = head 
        for i in range(k): 
            head = curr 
            curr_group_size = group_size + (i < remainder) - 1
            for j in range(curr_group_size): 
                if curr: 
                    curr = curr.next 
            if curr: 
                curr.next, curr = None, curr.next 
            ans.append(head)
        return ans
            