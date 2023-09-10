class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        l, r = -1, 0
        for weight in weights:
            if weight > l:
                l = weight
            r += weight

        def feasible(weights, capacity, days):
            days_taken = 1
            current_load = capacity
            for weight in weights:
                current_load -= weight
                if current_load < 0:
                    current_load = capacity - weight
                    days_taken += 1
            return days_taken <= days

        while l < r:
            m = (l + r) // 2
            if feasible(weights, m, days):
                r = m
            else:
                l = m + 1
        return l


print(Solution().shipWithinDays([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5))
assert Solution().shipWithinDays([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5) == 15
