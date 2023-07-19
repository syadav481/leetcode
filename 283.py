class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lastZeroIdx = 0
        i = 0
        for i in range(len(nums)):
            # if nums[lastZeroIdx] == 0 and nums[i] != 0:
            #     nums[lastZeroIdx], nums[i] = nums[i], nums[lastZeroIdx]
            #     lastZeroIdx += 1
            # elif nums[lastZeroIdx] != 0:
            #     lastZeroIdx += 1
            if nums[i] != 0:
                nums[lastZeroIdx], nums[i] = nums[i], nums[lastZeroIdx]
                lastZeroIdx += 1


nums = [1, 0, 1]
Solution().moveZeroes(nums)
print(nums)
