class Solution:
    def numOfSubarrays(self, arr: list[int], k: int, threshold: int) -> int:
        for i in range(1, len(arr)):
            arr[i] += arr[i - 1]
        l, r = -1, k - 1
        ans = 0
        for i in range(len(arr) - k + 1):
            avg = 0
            if l != -1:
                avg -= arr[l]
            avg += arr[r]
            avg /= k
            if avg >= threshold:
                ans += 1
            l += 1
            r += 1
        return ans


print(Solution().numOfSubarrays([2, 2, 2, 2, 5, 5, 5, 8], 3, 4))
