class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = []
        i = 0
        for i, a in enumerate(nums):
            if a > 0:
                return ans
            if i > 0 and a == nums[i - 1]:
                continue
            l = i + 1
            r = len(nums) - 1
            while l < r:
                m = a + nums[l] + nums[r]
                if m > 0:
                    r -= 1
                elif m < 0:
                    l += 1
                else:
                    ans.append([a, nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < len(nums) - 1 and nums[l] == nums[l - 1]:
                        l += 1
        return ans


s = Solution()
print(s.threeSum([-1, 0, 1, 2, -1, -4]))
print(s.threeSum([0, 0, 0, 0]))
