class Solution:
    def numSubseq(self, nums: list[int], target: int) -> int:
        ans = 0
        mod = 10**9 + 7
        nums.sort()
        r = len(nums) - 1
        l = 0
        while l <= r:
            if nums[r] + nums[l] > target:
                r -= 1
            else:
                ans += 1 << (r - l)
                l += 1
        return ans % mod


print(Solution().numSubseq([3, 5, 6, 7], 9))
