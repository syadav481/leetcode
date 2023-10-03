# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        curr = head
        next = curr.next
        while next and curr:
            if curr.val == next.val:
                curr.next = next.next
                next = curr.next
            else:
                curr = curr.next
                if curr:
                    next = curr.next
        return head
