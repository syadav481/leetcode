class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        # open < n
        # close < n
        # close < open
        stack = []
        ans = []

        def recurse(open, close):
            if open == close and open == n:
                ans.append("".join(stack))
                return
            if open < n:
                stack.append("(")
                recurse(open + 1, close)
                stack.pop()
            if close < open:
                stack.append(")")
                recurse(open, close + 1)
                stack.pop()

        recurse(0, 0)

        return ans


Solution().generateParenthesis(2)
