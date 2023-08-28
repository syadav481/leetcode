# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from collections import deque


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> list[list[int]]:
        ans = []
        q = deque()
        q.append(root)
        iterations = 0
        while q:
            length = len(q)
            level = []
            for i in range(length):
                curr = q[0]
                q.popleft()
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
                level.append(curr.val)
            if iterations % 2 == 0:
                ans.append(level)
            else:
                ans.append(level[::-1])
            iterations += 1
        return ans
