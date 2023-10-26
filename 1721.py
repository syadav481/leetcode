# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        a = head 
        b = head 
        for i in range(k - 1): 
            a = a.next 
        x = a 
        while a.next: 
            b = b.next 
            a = a.next 
        x.val, b.val = b.val, x.val
        return head 
        