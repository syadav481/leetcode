# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right: 
            return head 
        dummy = ListNode(0, head)
        l, r = dummy, dummy
        for i in range(left - 1): 
            l = l.next 
        for i in range(right): 
            r = r.next
        # reverse
        curr = l.next 
        end = curr
        prev = None 
        nxt = None 
        # disconnect
        l.next = None
        right_side = r.next
        r.next = None
        # 
        while curr: 
            nxt = curr.next
            curr.next = prev 
            prev = curr 
            curr = nxt
        l.next = prev
        end.next = right_side
        return dummy.next
