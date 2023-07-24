class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        ans, curr = 0, 0
        lastIndex = {}
        for i in range(len(fruits)):
            lastIndex[fruits[i]] = i
            if len(lastIndex) > 2:
                out = -1
                for key in lastIndex:
                    if key != fruits[i] and key != fruits[i - 1]:
                        out = lastIndex[key]
                        break
                curr = i - out
                lastIndex.pop(fruits[out])
            else:
                curr += 1
            ans = max(ans, curr)
        return ans


assert Solution().totalFruit([1, 2, 1]) == 3
assert Solution().totalFruit([0, 1, 2, 2]) == 3
assert Solution().totalFruit([3, 2, 7, 6]) == 2
assert Solution().totalFruit([]) == 0
assert Solution().totalFruit([1, 2, 2, 2, 3, 3, 3, 3]) == 7
assert Solution().totalFruit([1, 2, 3, 1, 2, 3]) == 2
assert Solution().totalFruit([1, 1, 2, 2, 3, 3, 3, 5, 5]) == 5
