class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def get_length(self, head: ListNode):
        curr = head
        length = 0
        while curr:
            length += 1
            curr = curr.next
        return length

    def move_k_spots(self, head: ListNode, k: int):
        while head and k > 0:
            head = head.next
            k -= 1
        return head

    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        lenA = self.get_length(headA)
        lenB = self.get_length(headB)
        diff = lenA - lenB
        # false if B is bigger, true if A is bigger
        if diff > 0:
            headA = self.move_k_spots(headA, diff)
        else:
            headB = self.move_k_spots(headB, abs(diff))
        while headA and headB:
            if headA.val == headB.val:
                return headA
            headA = headA.next
            headB = headB.next
        return None
