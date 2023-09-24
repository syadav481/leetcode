class Solution:
    def climbStairs(self, n: int) -> int:
        bc = 1
        nc = 0
        for i in range(n):
            tmp = bc
            bc = nc + bc
            nc = tmp
        return bc


print(Solution().climbStairs(3))
