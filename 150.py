class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        s = []
        operators = {"+", "-", "*", "/"}
        for token in tokens:
            if token not in operators:
                s.append(int(token))
            else:
                arg1 = s.pop()
                arg2 = s.pop()
                if token == "+":
                    s.append(arg2 + arg1)
                elif token == "-":
                    s.append(arg2 - arg1)
                elif token == "/":
                    s.append(int(arg2 / arg1))
                else:
                    s.append(arg2 * arg1)
        return s[0]


print(
    Solution().evalRPN(
        ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    )
)
