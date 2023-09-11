class Solution:
    def map1d_to_2d(self, idx, n):
        return (idx // n, idx % n)

    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        l = 0
        r = m * n
        while l < r:
            midpoint = (r - l) // 2 + l
            row, col = self.map1d_to_2d(midpoint, n)
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                r = midpoint
            else:
                l = midpoint + 1
        return False


print(Solution().searchMatrix([[1]], 2))
