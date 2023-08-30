class Solution:
    def arrangeCoins(self, n: int) -> int:
        rowSize = 1
        count = 0
        while n - rowSize > 0:
            n -= rowSize
            count += 1
            rowSize += 1
        return count
