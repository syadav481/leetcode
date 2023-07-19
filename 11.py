class Solution:
    def maxArea(self, height: list[int]) -> int:
        l, r = 0, len(height) - 1
        maxWater = -1
        while l < r:
            prod = min(height[l], height[r]) * (r - l)
            maxWater = max(maxWater, prod)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return maxWater
