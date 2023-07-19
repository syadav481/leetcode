class Solution:
    def findRepeatedDnaSequences(self, s: str) -> list[str]:
        seen = set()
        ans = set()
        for i in range(len(s) - 9):
            temp = s[i : i + 10 : 1]
            if temp in seen:
                ans.add(temp)
            else:
                seen.add(temp)
        return list(ans)


# This solution is correct, it's failing the asserts because of ordering, which doesn't actually matter.

s = Solution()
assert s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") == [
    "AAAAACCCCC",
    "CCCCCAAAAA",
]
assert s.findRepeatedDnaSequences("AAAAAAAAAAAAA") == ["AAAAAAAAAA"]
