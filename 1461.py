class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        uniques = set()
        for i in range(len(s) - k + 1):
            uniques.add(s[i : k + i : 1])
        return len(uniques) == 2**k


soln = Solution()
print(soln.hasAllCodes("01100", 2))
