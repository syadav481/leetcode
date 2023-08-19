class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        m = {}
        tm = {}
        matches = 0
        ans = [-1, -1]
        lenAns = float("infinity")
        for c in t:
            tm[c] = 1 + tm.get(c, 0)
        l = 0
        for r, curr in enumerate(s):
            m[curr] = 1 + m.get(curr, 0)
            if curr in tm and m[curr] == tm[curr]:
                matches += 1
            while matches == len(tm):
                if r - l + 1 < lenAns:
                    ans = [l, r]
                    lenAns = r - l + 1
                m[s[l]] -= 1
                if s[l] in tm and m[s[l]] < tm[s[l]]:
                    matches -= 1
                l += 1
        l, r = ans
        return s[l : r + 1] if lenAns != float("infinity") else ""


print(Solution().minWindow("ADOBECODEBANC", "ABC"))
# print(Solution().minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd"))
