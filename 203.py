# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head: 
            return head
        if not head.next: 
            return head if head.val != val else None
        ans = head 
        prev = head 
        nxt = head.next 
        while nxt: 
            if nxt.val == val: 
                prev.next = nxt.next 
                if prev.next: 
                    nxt = prev.next.next 
            prev = prev.next
            nxt = nxt.next
        return ans 
