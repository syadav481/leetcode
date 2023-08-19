import sys

sys.set_int_max_str_digits(0)


class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for char in num:
            while stack and k > 0 and int(stack[-1]) > int(char):
                k -= 1
                stack.pop()
            if stack or char is not "0":
                stack.append(char)
        stack = stack[: len(stack) - k]
        return "".join(stack) or "0"
