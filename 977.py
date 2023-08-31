class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        g = [x * x for x in nums]
        g.sort()
        return g


# this is not a good solution but it does beat 98% through optimizations i guess
