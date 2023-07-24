class Solution:
    def maxFrequency(self, nums: list[int], k: int) -> int:
        nums.sort()
        ans = 1
        l, r = 0, 0
        total = 0
        while r < len(nums) and l < len(nums):
            total += nums[r]
            while nums[r] * (r - l + 1) > total + k:
                total -= nums[l]
                l += 1
            ans = max(ans, r - l + 1)
            r += 1
        return ans


assert Solution().maxFrequency([5, 3, 5], 2) == 3
assert Solution().maxFrequency([1, 2, 4], 5) == 3
assert Solution().maxFrequency([1, 4, 8, 13], 5) == 2
assert Solution().maxFrequency([3, 9, 6], 2) == 1
