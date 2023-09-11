class Solution:
    def minimizeMax(self, nums: list[int], p: int) -> int:
        if p == 0:
            return 0

        nums.sort()
        # print("sorted numbers:")
        # print(nums)
        pairs = [(nums[i + 1] - nums[i], i) for i in range(len(nums) - 1)]
        # print("difference between each adjcent pairs")
        # print(pairs)
        pairs.sort()
        # print("differences sorted, with their original position")
        # print(pairs)

        m = [0] * len(nums)
        for i, (d, loc) in enumerate(pairs):
            l, r = m[loc - 1], m[loc + 1]
            m[loc] = m[loc - l] = m[loc + r] = l + r + 1
            p -= 1 & ~(l | r)
            # print("\n",m)
            # print("diff:", d,"loc:", loc, "length of left:", l, "length of right:" ,r)
            # print("remaining pairs:", p)
            if p == 0:
                return d


Solution().minimizeMax([10, 1, 2, 7, 1, 3], 2)
