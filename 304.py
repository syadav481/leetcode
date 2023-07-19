class NumMatrix:
    def __init__(self, matrix: list[list[int]]):
        self.m = [[0] * (len(matrix[0]) + 1) for i in range(len(matrix) + 1)]
        for i in range(1, len(self.m), 1):
            acc = 0
            for j in range(1, len(self.m[0]), 1):
                acc += matrix[i - 1][j - 1]
                self.m[i][j] = acc + self.m[i - 1][j]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        wholeArea = self.m[row2 + 1][col2 + 1]
        leftBox = self.m[row2 + 1][col1]
        topBox = self.m[row1][col2 + 1]
        overlap = self.m[row1][col1]
        return wholeArea - leftBox - topBox + overlap


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

nm = NumMatrix(
    [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5],
    ]
)
print(nm.m)
print(nm.sumRegion(2, 1, 4, 3))
