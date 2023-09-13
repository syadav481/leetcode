class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        if not nums:
            return [-1, -1]
        ans = [-1, -1]
        l, r = 0, len(nums) - 1
        # binary search 1, find left bound
        m = (r - l) // 2 + l
        while l <= r:
            m = (r - l) // 2 + l
            if target < nums[m]:
                r = m - 1
            elif target > nums[m]:
                l = m + 1
            # every case succeeding this one is when nums[m] == target:
            elif m == 0:
                break
            elif nums[m] != nums[m - 1]:
                break
            else:
                r = m - 1
        if nums[m] != target:
            return [-1, -1]
        ans[0] = m
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (r - l) // 2 + l
            if target < nums[m]:
                r = m - 1
            elif target > nums[m]:
                l = m + 1
            elif m == len(nums) - 1:
                break
            elif nums[m] != nums[m + 1]:
                break
            else:
                l = m + 1
        ans[1] = m
        return ans


print(Solution().searchRange([5, 7, 7, 8, 8, 10], 8))
print(Solution().searchRange([5, 7, 7, 8, 8, 10], 6))
