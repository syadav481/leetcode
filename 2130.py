class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Cases:
# x
# 1 -> 2
# 1 -> 2 -> 3 -> 4

# reverse the 2nd half of the list and iterate forwards.


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        f = head
        s = head
        while f and f.next:
            f = f.next.next
            s = s.next
        prev = None
        next = None
        while s:
            next = s.next
            s.next = prev
            prev = s
            s = next
        head2 = prev
        ans = -float("inf")
        while head2 and head:
            ans = max(head2.val + head.val, ans)
            head2 = head2.next
            head = head.next
        return ans
