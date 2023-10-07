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
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummyHead = ListNode()
        curr = dummyHead
        carry = 0
        while l1 or l2 or carry != 0:
            summation = 0
            if l1:
                summation += l1.val
                l1 = l1.next
            if l2:
                summation += l2.val
                l2 = l2.next
            summation += carry
            carry = summation // 10
            curr.next = ListNode(summation % 10)
            curr = curr.next
        return dummyHead.next
