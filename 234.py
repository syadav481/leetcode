# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        s, f = head, head
        while f and f.next: 
            f = f.next.next 
            s = s.next 
        if f and not f.next: 
            s = s.next 
        prev, nxt = None, None 
        while s:
            nxt = s.next 
            s.next = prev 
            prev = s 
            s = nxt 
        if s: 
            s.next = None 
        s = prev
        f = head 
        while f and s: 
            if f.val != s.val: 
                return False 
            f = f.next
            s = s.next 
        return True

    def print_list(self, node): 
        while (node): 
            print(f'{node.val}->', end="")
            node = node.next
        print()



