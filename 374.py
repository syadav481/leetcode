# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
def guess(num: int) -> int:
    return -1


class Solution:
    def guessNumber(self, n: int) -> int:
        l = 1
        r = n
        m = n
        if guess(n) == 0:
            return n
        elif guess(1) == 0:
            return 1
        while l < r:
            m = (l + r) // 2
            if guess(m) == -1:
                r = m
            elif guess(m) == 1:
                l = m + 1
            else:
                return m
        return m
