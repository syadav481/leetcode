from itertools import accumulate


class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        prefixes = list(accumulate(nums))
        prefixes = [x % k for x in prefixes]
        m = {0: -1}
        for i, n in enumerate(prefixes):
            if n not in m:
                m[n] = i
            elif i - m[n] >= 2:
                return True
        return False


s = Solution()

assert s.checkSubarraySum([23, 2, 4, 6, 7], 6) == True
assert s.checkSubarraySum([23, 2, 6, 4, 7], 6) == True
