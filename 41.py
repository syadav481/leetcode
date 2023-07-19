class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        for i in range(len(nums)):
            if nums[i] < 0:
                nums[i] = 0
        for i in range(len(nums)):
            idx = abs(nums[i]) - 1
            if idx > -1 and idx < len(nums):
                if nums[idx] != 0:
                    nums[idx] = -abs(nums[idx])
                else:
                    nums[idx] = -abs(len(nums) + 1)
        for i in range(1, len(nums) + 1, 1):
            if nums[i - 1] >= 0:
                return i
        return len(nums) + 1


assert Solution().firstMissingPositive([1, 2, 0]) == 3
assert Solution().firstMissingPositive([3, 4, -1, 1]) == 2
assert Solution().firstMissingPositive([7, 8, 9, 11, 12]) == 1
