class Solution:
    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        if k == len(arr):
            return arr
        ans = []
        # step 1: find the "closest" elt
        idxOfClosest = -1
        valOfClosest = 10**5
        for i in range(len(arr)):
            if valOfClosest > abs(arr[i] - x):
                valOfClosest = abs(arr[i] - x)
                idxOfClosest = i
        l, r = idxOfClosest - 1, idxOfClosest + 1
        ans.append(arr[idxOfClosest])
        k -= 1
        while (l > -1 or r < len(arr)) and k != 0:
            lVal = False
            rVal = False
            if l > -1:
                lVal = abs(arr[l] - x)
            if r < len(arr):
                rVal = abs(arr[r] - x)
            # find which one of l,r is "closer" and add that one to ans
            if lVal is False:
                ans.append(arr[r])
                r += 1
            elif rVal is False:
                ans.append(arr[l])
                l -= 1
            elif rVal < lVal:
                ans.append(arr[r])
                r += 1
            else:
                ans.append(arr[l])
                l -= 1
            k -= 1
        ans.sort()
        print(ans)
        return ans


# Solution().findClosestElements([1, 2, 3, 4, 5], 4, 3)
Solution().findClosestElements([1, 2, 3, 4, 5], 4, -1)
# Solution().findClosestElements([1, 1, 1, 1, 2], 4, 3)
# Solution().findClosestElements([0, 0, 0, 1, 3, 5, 6, 7, 8, 8], 2, 2)
