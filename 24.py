class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        dummy = ListNode(-float("inf"), head)
        p = dummy
        c = head
        while c and c.next:
            n = c.next
            p.next = c.next
            c.next = c.next.next
            n.next = c
            p = c
            c = c.next
        return dummy.next
