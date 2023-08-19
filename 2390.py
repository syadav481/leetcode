class Solution:
    def removeStars(self, s: str) -> str:
        ans = ""
        stack = []
        for char in s:
            if char == "*":
                stack.pop()
            else:
                stack.append(char)
        for x in stack:
            ans += x
        return ans
