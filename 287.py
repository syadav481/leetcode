class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        s = 0
        f = 0
        while True:
            f = nums[nums[f]]
            s = nums[s]
            if f == s:
                break
        s2 = 0
        while s != s2:
            s = nums[s]
            s2 = nums[s2]
        return s
