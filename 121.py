class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        ans = 0
        mindex = 0
        for i in range(len(prices)):
            if prices[i] < prices[mindex]:
                mindex = i
            else:
                ans = max(ans, prices[i] - prices[mindex])
        return ans


a = Solution().maxProfit([7, 1, 5, 3, 6, 4])
print(a)
