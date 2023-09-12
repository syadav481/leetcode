class Solution:
    def search(self, nums: list[int], target: int) -> int:
        ans = -1
        l, r = 0, len(nums) - 1
        while l < r:
            m = (r - l) // 2 + l
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        pivot = l
        l = 0
        r = len(nums) - 1
        # if the minimum elt in the left portion is still greater than target,
        # look right
        if nums[pivot] <= target and target <= nums[r]:
            l = pivot
        # otherwise, look in the left portion
        else:
            r = pivot
        while l <= r:
            m = (r - l) // 2 + l
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                return m
        return ans


Solution().search([1, 3], 3)
