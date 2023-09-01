class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        l, r = 1, x
        while l <= r:
            m = (r + l) // 2
            if m * m == x:
                return m
            elif m * m < x:
                l = m + 1
            else:
                r = m - 1
        return r


Solution().mySqrt(6)
