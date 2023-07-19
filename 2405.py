class Solution:
    def partitionString(self, s: str) -> int:
        sum = 1
        uniques = set()
        for c in s:
            if c in uniques:
                uniques.clear()
                uniques.add(c)
                sum += 1
            elif c not in uniques:
                uniques.add(c)
        return sum


assert Solution().partitionString("abacaba") == 4
assert Solution().partitionString("ssssss") == 6
