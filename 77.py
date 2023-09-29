class Solution:
    def __init__(self):
        self.combs = []

    def gen_combs(self, n, k, idx, curr):
        if len(curr) == k:
            self.combs.append(curr)
            return
        else:
            if len(curr) + (n - idx) < k - 1:
                return
            for i in range(idx, n + 1):
                self.gen_combs(n, k, i + 1, curr + [i])
        return

    def combine(self, n: int, k: int) -> list[list[int]]:
        curr = []
        self.gen_combs(n, k, 1, curr)
        return self.combs


print(Solution().combine(4, 2))
