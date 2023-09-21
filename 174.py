class Solution:
    def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
        dp = []
        for i in range(len(dungeon)):
            dp.append([-float("inf")] * len(dungeon[i]))
        for r in range(len(dp) - 1, -1, -1):
            for c in range(len(dp[r]) - 1, -1, -1):
                # r,c is at the princess
                drc = dungeon[r][c]
                if r == len(dp) - 1 and c == len(dp[r]) - 1:
                    dp[r][c] = min(drc, 0)
                # in range
                elif r < len(dp) - 1 and c < len(dp[r]) - 1:
                    dp[r][c] = min(0, drc + max(dp[r + 1][c], dp[r][c + 1]))
                # only one dimension in range
                elif r == len(dp) - 1:
                    dp[r][c] = min(0, drc + dp[r][c + 1])
                elif c == len(dp[r]) - 1:
                    dp[r][c] = min(0, drc + dp[r + 1][c])
        return abs(dp[0][0]) + 1


print(Solution().calculateMinimumHP([[0, 0]]))
print(Solution().calculateMinimumHP([[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]))
