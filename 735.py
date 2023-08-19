class Solution:
    def asteroidCollision(self, asteroids: list[int]) -> list[int]:
        s = []
        l = -1
        r = 1
        for a in asteroids:
            s.append(a)
            if len(s) > 1:
                r = s[-1]
                l = s[-2]
            while l > 0 and r < 0:
                if l + r > 0:
                    s.pop()
                elif l + r < 0:
                    s.pop()
                    s.pop()
                    s.append(r)
                else:
                    s.pop()
                    s.pop()
                if len(s) > 1:
                    r = s[-1]
                    l = s[-2]
                else:
                    r = 1
        return s


print(Solution().asteroidCollision([5, 10, -5]))
