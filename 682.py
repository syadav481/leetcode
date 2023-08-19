class Solution:
    def calPoints(self, operations: list[str]) -> int:
        s = []
        for operation in operations:
            if operation == "D":
                s.append(2 * s[-1])
            elif operation == "C":
                s.pop()
            elif operation == "+":
                s.append(s[-1] + s[-2])
            else:
                s.append(int(operation))
        return sum(s)
