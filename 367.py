class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l, r = 1, num
        while l <= r:
            m = (l + r) // 2
            mSquared = m * m
            if mSquared == num:
                return True
            elif mSquared > num:
                r = m - 1
            else:
                l = m + 1
        return False


Solution().isPerfectSquare(9)
