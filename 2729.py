class Solution:
    def isFascinating(self, n: int) -> bool:
        concatenated = str(n) + str(2 * n) + str(3 * n)
        digits = set()
        for char in concatenated:
            if char in digits or char == "0":
                return False
            else:
                digits.add(char)
        if len(digits) != 9:
            return False
        return True
