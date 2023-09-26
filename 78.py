class Solution:
    def __init__(self):
        self.ans = []

    def gen_sets(self, curr, idx, nums):
        if idx == len(nums):
            self.ans.append(curr)
            return
        # either add the elt to curr and call again or don't add the elt to curr and call again
        self.gen_sets([nums[idx]] + curr, idx + 1, nums)
        self.gen_sets(curr, idx + 1, nums)

    def subsets(self, nums: list[int]) -> list[list[int]]:
        self.gen_sets([nums[0]], 1, nums)
        self.gen_sets([], 1, nums)
        return self.ans


print(Solution().subsets([1, 2, 3]))
