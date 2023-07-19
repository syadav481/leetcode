class Solution:
    def zeroFilledSubarray(self, nums: list[int]) -> int:
        currLength = 0
        sum = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                currLength += 1
                sum += currLength
            elif nums[i] != 0 and currLength != 0:
                currLength = 0
        return sum


s = Solution()
assert s.zeroFilledSubarray([1, 3, 0, 0, 2, 0, 0, 4]) == 6
assert s.zeroFilledSubarray([0, 0, 0, 2, 0, 0]) == 9
