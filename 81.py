class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        l, r = 0, len(nums) - 1
        while l < r:
            while l < len(nums) - 1 and nums[l] == nums[l + 1]:
                l += 1
            while r > 0 and nums[r] == nums[r - 1]:
                r -= 1
            m = (r - l) // 2 + l
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        pivot = l
        l, r = 0, len(nums) - 1
        if nums[pivot] <= target and target <= nums[r]:
            l = pivot
        else:
            r = pivot
        while l <= r:
            m = (r - l) // 2 + l
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                return True
        return False


print(Solution().search([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1], 2))

# for i in nums:
#     print(i, end="")
# print()
# for i in range(len(nums)):
#     if i == pivot:
#         print("^", end="")
#     else:
#         print(" ", end="")
