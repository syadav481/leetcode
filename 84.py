class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        maxArea = -1
        n = len(heights)
        left = [0] * n
        right = [0] * n
        stack = []
        for i in range(len(heights)):
            if not stack:
                stack.append(i)
                left[i] = 0
            else:
                while stack and heights[stack[-1]] >= heights[i]:
                    stack.pop()
                if not stack:
                    left[i] = 0
                else:
                    left[i] = stack[-1] + 1
                stack.append(i)
        stack.clear()
        for i in range(len(heights) - 1, -1, -1):
            if not stack:
                stack.append(i)
                right[i] = n - 1
            else:
                while stack and heights[stack[-1]] >= heights[i]:
                    stack.pop()
                if not stack:
                    right[i] = n - 1
                else:
                    right[i] = stack[-1] - 1
                stack.append(i)
        for i in range(n):
            maxArea = max(maxArea, (right[i] - left[i] + 1) * heights[i])
        return maxArea


print(Solution().largestRectangleArea([2, 1, 5, 6, 2, 3]))
print("expected 10")

# brute force
# def largestRectangleArea(self, heights: list[int]) -> int:
#     maxArea = -1
#     for idx, height in enumerate(heights):
#         l = r = idx
#         while l - 1 > -1 and heights[l - 1] >= height:
#             l -= 1
#         while r + 1 < len(heights) and heights[r + 1] >= height:
#             r += 1
#         maxArea = max(maxArea, (r - l + 1) * height)
#     return maxArea
