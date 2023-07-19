class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m - 1
        j = n - 1
        x = len(nums1) - 1
        while i > -1 or j > -1:
            if i > -1 and j > -1:
                if nums1[i] > nums2[j]:
                    nums1[x] = nums1[i]
                    i -= 1
                else:
                    nums1[x] = nums2[j]
                    j -= 1
            elif i > -1:
                nums1[x] = nums1[i]
                i -= 1
            else:
                nums1[x] = nums2[j]
                j -= 1
            x -= 1


arr1 = [1, 2, 3, 0, 0, 0]
arr2 = [2, 5, 6]
Solution().merge(arr1, 3, arr2, 3)
soln = [1, 2, 2, 3, 5, 6]
for x, y in zip(arr1, soln):
    assert x == y
