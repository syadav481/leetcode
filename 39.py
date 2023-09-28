class Solution:
    def __init__(self):
        # map dict sum of array to array
        self.ans = []

    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        self.gen_combs(candidates, target, [], 0)
        return self.ans

    def gen_combs(self, candidates, target, curr, idx):
        if target == 0:
            self.ans.append(curr)
            return
        elif target < 0:
            return
        for i in range(idx, len(candidates)):
            elt = candidates[i]
            self.gen_combs(candidates, target - elt, curr + [elt], i)
        return


print(Solution().combinationSum([2, 3, 5], 8))
