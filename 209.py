class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        ans = 10**9 + 1
        l, r = 0, 0
        curr = 0
        for r in range(len(nums)):
            curr += nums[r]
            while curr >= target:
                curr -= nums[l]
                ans = min(r - l + 1, ans)
                l += 1
            r += 1
        if ans == 10**9 + 1:
            return 0
        return ans
