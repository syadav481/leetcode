class Solution:
    def validPalindrome(self, s: str) -> bool:
        arr = list(s)

        def helper(a, l, r):
            while l < r:
                if a[l] != a[r]:
                    return False
                l += 1
                r -= 1
            return True

        l = 0
        r = len(s) - 1
        while l < r:
            if arr[l] == arr[r]:
                l += 1
                r -= 1
                continue
            else:
                return helper(arr, l + 1, r) or helper(arr, l, r - 1)
        return True
