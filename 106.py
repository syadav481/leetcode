# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]) -> Optional[TreeNode]:
        root = postorder.pop()
        mid = -1
        for i in range(len(inorder)):
            if inorder[i] == root:
                mid = i
                break
        leftIdx = -1
        rightIdx = -1
        if mid != 0:
            leftIdx = mid - 1
        if mid != len(inorder) - 1:
            rightIdx = mid + 1
