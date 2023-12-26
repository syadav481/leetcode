# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        while head: 
            node = head
            head = head.next 
            node.next = None
            # insert into correct position 
            if not dummy.next: 
                dummy.next = node 
            else: 
                curr = dummy.next 
                prev = dummy
                while curr and curr.val < node.val: 
                    curr = curr.next 
                    prev = prev.next 
                # curr points at insertion point, prev right before curr. 
                prev.next = node
                node.next = curr 
        return dummy.next