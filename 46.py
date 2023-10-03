class Solution:
    def __init__(self):
        self.perms = []

    def permute(self, nums: list[int]) -> list[list[int]]:
        self.gen_perms(nums, [], 0)
        return self.perms

    def gen_perms(self, nums, curr, i):
        if len(curr) == len(nums):
            self.perms.append(curr)
        else:
            for j in range(i, len(nums)):
                self.gen_perms(nums, curr[::] + [nums[j]], j + 1)


print(Solution().permute([1, 2, 3]))
