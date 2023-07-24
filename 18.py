class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        nums.sort()
        ans = []
        k_tuple = []

        def kSum(start, k, target):
            if k == 2:
                l = start
                r = len(nums) - 1
                while l < r:
                    m = nums[l] + nums[r]
                    if m > target:
                        r -= 1
                    elif m < target:
                        l += 1
                    else:
                        ans.append(k_tuple + [nums[l], nums[r]])
                        l += 1
                        while l < r and nums[l] == nums[l - 1]:
                            l += 1
            else:
                for i in range(start, len(nums) - k + 1):
                    if i > start and nums[i] == nums[i - 1]:
                        continue
                    else:
                        k_tuple.append(nums[i])
                        kSum(i + 1, k - 1, target - nums[i])
                        k_tuple.pop()
                return

        kSum(0, 4, target)
        return ans


print(Solution().fourSum([1, 0, -1, 0, -2, 2], 0))
