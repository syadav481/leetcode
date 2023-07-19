from copy import deepcopy


class Solution:
    def distinctNames(self, ideas: list[str]) -> int:
        count = 0
        # letter -> suffix-set
        m = {}
        for word in ideas:
            if word[:1:] not in m:
                m[word[:1:]] = set()
            m[word[:1:]].add(word[1:])
        for c1 in m:
            for c2 in m:
                if c1 == c2:
                    continue
                intersection = 0
                for word in m[c1]:
                    if word in m[c2]:
                        intersection += 1
                distinct1 = len(m[c1]) - intersection
                distinct2 = len(m[c2]) - intersection
                count += distinct1 * distinct2
        return count


assert Solution().distinctNames(["coffee", "donuts", "time", "toffee"]) == 6
assert Solution().distinctNames(["lack", "back"]) == 0
