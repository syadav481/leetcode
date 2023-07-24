class Solution:
    def trap(self, height: list[int]) -> int:
        maxL, maxR = height[0], height[len(height) - 1]
        l, r = 0, len(height) - 2
        ans = 0
        while l <= r:
            if maxL < maxR:
                if height[l] < maxL:
                    ans += maxL - height[l]
                else:
                    maxL = height[l]
                l += 1
            else:
                if height[r] < maxR:
                    ans += maxR - height[r]
                else:
                    maxR = height[r]
                r -= 1
        return ans
