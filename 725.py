# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = 0 
        curr = head
        while curr: 
            n += 1
            curr = curr.next
        group_size = n // k
        remainder = n % k
        curr_group_size = 0
        prev = head
        curr = head
        ans = []
        for _ in range(k): 
            if remainder > 0: 
                curr_group_size = group_size + 1
            else: 
                curr_group_size = group_size
            if curr:
                for _ in range(curr_group_size): 
                    curr = curr.next
                nxt = curr.next 
                curr.next = None
                curr = nxt
                ans.append(prev) 
                prev = curr
            else: 
                ans.append(None)
        return ans
