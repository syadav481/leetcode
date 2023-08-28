class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        l, r = 0, len(nums)
        found = -1
        while l < r:
            m = (l + r) // 2
            if target > nums[m]:
                l = m + 1
            elif target < nums[m]:
                r = m
            else:
                found = m
                break
        if found != -1:
            return found
        return l
