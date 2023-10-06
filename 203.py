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
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return head
        while head and head.val == val:
            head = head.next
        curr = head
        ret_val = curr
        if not curr:
            return curr
        next = curr.next
        while curr and next:
            if next.val == val:
                curr.next = next.next
                next = next.next
            else:
                curr = curr.next
                next = next.next
        return ret_val
