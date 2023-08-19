class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        # stack stores:
        # tuple: 0th = value of temperatures[i], 1st: i
        s = []
        ans = [0] * len(temperatures)
        for idx, temp in enumerate(temperatures):
            while s and temp > s[-1][0]:
                ans[s[-1][1]] = idx - s[-1][1]
                s.pop()
            else:
                s.append((temp, idx))
        return ans
