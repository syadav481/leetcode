from sys import maxsize


class Solution:
    def minimumDifference(self, nums: list[int], k: int) -> int:
        nums.sort()
        minDiff = maxsize
        for l in range(len(nums) - k + 1):
            minDiff = min(nums[l + k - 1] - nums[l], minDiff)
        return minDiff


assert Solution().minimumDifference([9, 4, 1, 7], 2) == 2
