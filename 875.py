from math import ceil


class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        # return true if within h hours, at a rate of k bananas per hour,
        # all bananas can be consumed. False otherwise.

        def helper(piles, k, h):
            total = 0
            for pile in piles:
                total += ceil(pile / k)
                if total > h:
                    return False
            return True

        low = 1
        high = max(piles)
        lastWorkingK = -1
        while low <= high:
            currentK = (high - low) // 2 + low
            if helper(piles, currentK, h):
                high = currentK - 1
                lastWorkingK = currentK
            else:
                low = currentK + 1
        return lastWorkingK


s = Solution()
print(s.minEatingSpeed([30, 11, 23, 4, 20], 6))
print("expected 23")
