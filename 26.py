class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        prev = nums[0]
        left = 1
        for i in range(1, len(nums)):
            if nums[i] != prev:
                prev = nums[i]
                nums[left] = nums[i]
                left += 1
        return left
