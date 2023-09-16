class Solution:
    def feasible(self, k_in, removable, s, p):
        indices = set(removable[:k_in:])
        i = 0
        for j in range(len(s)):
            if s[j] == p[i] and j not in indices:
                i += 1
            if i == len(p):
                return True
        if i == len(p):
            return True
        return False

    def maximumRemovals(self, s: str, p: str, removable: list[int]) -> int:
        l, r = 0, len(removable)
        last_valid_k = -1
        while l <= r:
            k_in = (r - l) // 2 + l
            if self.feasible(k_in, removable, s, p):
                last_valid_k = k_in
                l = k_in + 1
            else:
                r = k_in - 1
        return last_valid_k
