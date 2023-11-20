# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        l1 = ListNode()
        ret1 = l1
        l2 = ListNode()
        ret2 = l2

        while head: 
            nxt = head.next
            head.next = None 
            if head.val < x: 
                l1.next = head
                l1 = l1.next
            else: 
                l2.next = head 
                l2 = l2.next
            head = nxt
        l1.next = ret2.next
        return ret1.next
