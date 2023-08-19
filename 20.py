class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        if len(s) % 2 != 0:
            return False
        m = {"}": "{", ")": "(", "]": "["}
        for char in s:
            if char not in m:
                stack.append(char)
            if char in m:
                if len(stack) > 0 and m[char] == stack[-1]:
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
