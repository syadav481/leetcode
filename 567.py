def debug(s1, s2, s1Counts, s2Counts, matches):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    print("................. START ..................")
    print("Printing input strings...")
    print(f"s1: {s1}")
    print(f"s2: {s2}")
    print("Printing s1Counts and s2Counts side by side...")
    for i in range(len(s1Counts)):
        print(f"{alphabet[i]}: s1Counts: {s1Counts[i]}\ts2Counts: {s2Counts[i]}")
    print(f"Total Match Count: {matches}")
    print(".................. DONE ..................")


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        def idx(inp_char):
            return ord(inp_char) - ord("a")

        if len(s1) > len(s2):
            return False
        s1Counts, s2Counts = [0] * 26, [0] * 26
        for i in range(len(s1)):
            s1Counts[idx(s1[i])] += 1
            s2Counts[idx(s2[i])] += 1
        matches = 0
        for i in range(26):
            if s1Counts[i] == s2Counts[i]:
                matches += 1
        if matches == 26:
            return True
        l = 0
        for r in range(len(s1), len(s2)):
            i = idx(s2[r])
            s2Counts[i] += 1
            if s1Counts[i] == s2Counts[i]:
                matches += 1
            elif s1Counts[i] + 1 == s2Counts[i]:
                matches -= 1
            i = idx(s2[l])
            s2Counts[i] -= 1
            if s1Counts[i] == s2Counts[i]:
                matches += 1
            elif s1Counts[i] - 1 == s2Counts[i]:
                matches -= 1
            l += 1
            if matches == 26:
                return True
            # debug(s1, s2, s1Counts, s2Counts, matches)

        return False


# print(Solution().checkInclusion("ab", "eidbaooo"))
# print(Solution().checkInclusion("ab", "eidboaoo"))
# print(Solution().checkInclusion("abc", "bbbca"))
print(Solution().checkInclusion("a", "ab"))
