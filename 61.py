# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# 1. Compute the size of the list
# 2. Take k modulo the size
# 3. Rotate the list by this amount
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head
        n = 0
        curr = head
        while curr:
            n += 1
            curr = curr.next
        k = k % n
        if k == 0:
            return head
        s = head
        f = head
        while f and f.next:
            if k <= 0:
                s = s.next
            f = f.next
            k -= 1
        f = s.next
        s.next = None
        new_head = f
        while f and f.next:
            f = f.next
        f.next = s
        return new_head
