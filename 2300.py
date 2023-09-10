class Solution:
    def successfulPairs(
        self, spells: list[int], potions: list[int], success: int
    ) -> list[int]:
        pairs = []
        potions.sort()
        for spell in spells:
            l, r = 0, len(potions) - 1
            while l <= r:
                m = (r - l) // 2 + l
                feasible = (potions[m] * spell) >= success
                if feasible:
                    r = m - 1
                else:
                    l = m + 1
            pairs.append(len(potions) - l)
        return pairs
