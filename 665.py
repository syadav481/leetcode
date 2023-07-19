class Solution:
    def checkPossibility(self, nums: list[int]) -> bool:
        changed = False
        for i in range(len(nums) - 1):
            if nums[i] <= nums[i + 1]:
                continue
            else:
                if changed:
                    return False
                if i > 0 and nums[i + 1] < nums[i - 1]:
                    nums[i + 1] = nums[i]
                else:
                    nums[i] = nums[i + 1]
                changed = True
        return True


s = Solution()
assert s.checkPossibility([3, 4, 2, 3]) == False
assert s.checkPossibility([4, 2, 3]) == True
assert s.checkPossibility([4, 2, 1]) == False
assert s.checkPossibility([5, 7, 1, 8]) == True
