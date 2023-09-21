# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def split(self, head):
        """Split a list, return a tuple containing the two halves."""
        fast, slow, secondHalf = head, head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        while secondHalf.next is not slow:
            secondHalf = secondHalf.next
        temp = secondHalf.next
        secondHalf.next = None
        secondHalf = temp
        return (head, secondHalf)

    def interleave(self, l1, l2):
        """Interleave two lists."""
        ans = l1
        last = l1
        while l1 and l2:
            l1_next = l1.next
            l2_next = l2.next

            l1.next = l2
            l2.next = l1_next

            l1 = l1_next
            l2 = l2_next
        if l2:
            copy = ans
            while copy.next:
                copy = copy.next
            copy.next = l2
        return ans

    def reverse(self, lst):
        nxt, prv = None, None
        while lst:
            nxt = lst.next
            lst.next = prv
            prv = lst
            lst = nxt
        return prv

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head.next == None:
            return head
        (firstHalf, secondHalf) = self.split(head)
        return self.interleave(firstHalf, self.reverse(secondHalf))
