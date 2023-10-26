# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # this solution is lame, my cpp one is a genuine mergesort impl with O(nlogn) time and O(1) mem
        curr = head 
        arr = [] 
        while (curr): 
            arr.append(curr.val) 
            curr = curr.next 
        arr.sort() 
        dummy = ListNode()
        curr = dummy
        for i in arr: 
            curr.next = ListNode(i) 
            curr = curr.next 
        return dummy.next