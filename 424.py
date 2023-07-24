class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        l = 0
        m = {}
        for r in range(len(s)):
            m[s[r]] = 1 + m.get(s[r], 0)
            maxF = 0
            for key in m:
                maxF = max(maxF, m[key])
            while (r - l + 1) - maxF > k:
                m[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans
