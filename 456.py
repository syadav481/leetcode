class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        # pair: [num, min value to the left of that number]
        # monotonic decreasing stack.
        stack = []
        currMin = nums[0]
        for i in range(1, len(nums)):
            n = nums[i]
            while stack and n >= stack[-1][0]:
                stack.pop()
            if stack and n > stack[-1][1]:
                return True
            stack.append([n, currMin])
            currMin = min(currMin, n)
        return False


t1 = Solution().find132pattern([3, 1, 4, 2])
print(t1)
