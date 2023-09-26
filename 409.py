class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq_map = {}
        for char in s:
            freq_map[char] = 1 + freq_map.get(char, 0)
        count = 0
        odd_present = False
        for key in freq_map:
            if freq_map[key] % 2 == 1:
                odd_present = True
                count += freq_map[key] - 1
            else:
                count += freq_map[key]
        if odd_present:
            count += 1
        return count
