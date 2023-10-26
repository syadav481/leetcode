class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        curr = head
        dict = {}
        while curr:
            dict[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        while curr:
            copy_curr = dict[curr]
            if curr.next:
                copy_curr.next = dict[curr.next]
            if curr.random:
                copy_curr.random = dict[curr.random]
            curr = curr.next
        return dict[head]


n1 = Node(7)
n2 = Node(13)
n3 = Node(11)
n4 = Node(10)
n5 = Node(1)
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n1.random = None
n2.random = n1
n3.random = n5
n4.random = n3
n5.random = n1
res = Solution().copyRandomList(n1)
print(res)
