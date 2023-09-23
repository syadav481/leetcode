# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return head if n == 0 else None
        if not head.next.next:
            if n == 0:
                return head
            elif n == 1:
                head.next = None
                return head
            else:
                return head
        sz = 0
        curr = head
        while curr:
            curr = curr.next
            sz += 1
        first, second = head, head.next
        sz -= 1
        while second.next and sz > 0:
            first = first.next
            second = second.next
            sz -= 1
            print(first.val)
            print(second.val)
            print("---")
        first.next = second.next
        return head
