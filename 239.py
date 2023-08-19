from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        ans = []
        q = deque()
        l = 0
        for r in range(len(nums)):
            while q and nums[q[len(q) - 1]] < nums[r]:
                q.pop()
            q.append(r)
            if l > q[0]:
                q.popleft()
            if (r + 1) >= k:
                ans.append(nums[q[0]])
                l += 1
        return ans


print(Solution().maxSlidingWindow([7, 2, 4], 2))
print(Solution().maxSlidingWindow([1, -1], 1))
print(Solution().maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))
