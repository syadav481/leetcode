class Solution:
    def numRescueBoats(self, people: list[int], limit: int) -> int:
        l, r, ans = 0, len(people) - 1, 0
        people.sort()
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            ans += 1
            r -= 1
        return ans
