class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        if k == 0:
            return False
        s = set()
        n = min(k, len(nums))
        for i in range(n):
            if nums[i] in s:
                return True
            s.add(nums[i])
        r = n
        l = 0
        while r < len(nums):
            if nums[r] in s:
                return True
            else:
                s.remove(nums[l])
                s.add(nums[r])
            r += 1
            l += 1
        return False
