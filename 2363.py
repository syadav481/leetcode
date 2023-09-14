class Solution:
    def mergeSimilarItems(
        self, items1: list[list[int]], items2: list[list[int]]
    ) -> list[list[int]]:
        m = {}
        for item in items1 + items2:
            if item[0] in m:
                m[item[0]][1] += item[1]
            else:
                m[item[0]] = item
        ans = []
        for key in m:
            ans.append(m[key])
        ans = sorted(ans, key=lambda x: x[0])
        return ans


Solution().mergeSimilarItems([[1, 1], [4, 5], [3, 8]], [[3, 1], [1, 5]])
