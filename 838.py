from collections import deque


class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        d = list(dominoes)
        q = deque()
        for i in range(len(d)):
            if d[i] != ".":
                q.append(i)
        while q:
            i = q.popleft()
            c = d[i]
            if c == "L":
                if i - 1 > -1 and d[i - 1] == ".":
                    d[i - 1] = "L"
                    q.append(i - 1)
            elif c == "R":
                if i + 1 < len(d) and d[i + 1] == ".":
                    if i + 2 < len(d) and d[i + 2] == "L":
                        q.popleft()
                    else:
                        q.append(i + 1)
                        d[i + 1] = "R"
        return "".join(d)


# write some tests
s = Solution()
print(s.pushDominoes(".L.R...LR..L.."))
assert s.pushDominoes(".L.R...LR..L..") == "LL.RR.LLRRLL.."
print("passed")
print(s.pushDominoes("RR.L"))
assert s.pushDominoes("RR.L") == "RR.L"
print("passed")
