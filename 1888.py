class Solution:
    def debug(self, s, b1, b2, l, r):
        print("-------------------")
        print("comparing with b1...")
        print(b1)
        print(s)
        for i in range(len(s)):
            if i == l:
                print("l", end="")
            if i == r:
                print("r", end="")
            else:
                print(" ", end="")
        print()
        print("comparing with b2...")
        print(b2)
        print(s)
        for i in range(len(s)):
            if i == l:
                print("l", end="")
            if i == r:
                print("r", end="")
            else:
                print(" ", end="")
        print()

    def minFlips(self, s: str) -> int:
        ans = 0
        n = len(s)
        s = s + s
        b1, b2 = "", ""
        for i in range(len(s)):
            if i % 2 == 0:
                b1 += "1"
                b2 += "0"
            else:
                b1 += "0"
                b2 += "1"
        diff1, diff2 = 0, 0
        for i in range(n):
            if s[i] != b1[i]:
                diff1 += 1
            if s[i] != b2[i]:
                diff2 += 1
        ans = min(diff2, diff1)
        for i in range(n, len(s)):
            if s[i - n] != b1[i - n]:
                diff1 -= 1
            if s[i - n] != b2[i - n]:
                diff2 -= 1
            if s[i] != b1[i]:
                diff1 += 1
            if s[i] != b2[i]:
                diff2 += 1
            # self.debug(s, b1, b2, i - n, i)
            ans = min(diff2, diff1, ans)
        return ans


# Solution().minFlips("111000")
# Solution().minFlips("010")
# Solution().minFlips("1110")
Solution().minFlips("01001001101")
