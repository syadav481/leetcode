class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:
        l = max(nums)
        r = sum(nums)
        ans = float("inf")
        while l < r:
            m = (r + l) // 2
            partions = 1
            curr_sum = 0
            for num in nums:
                if num + curr_sum <= m:
                    curr_sum += num
                else:
                    partions += 1
                    curr_sum = num
            if partions <= k:
                r = m
            else:
                l = m + 1
        return l


print(Solution().splitArray([7, 2, 5, 10, 8], 2))
print(Solution().splitArray([1, 2, 3, 4, 5], 2))
