def findAnagrams(s, p):
    ans = []
    sm = {}
    pm = {}
    if len(p) > len(s):
        return ans
    # make the pm dictionary
    for char in p:
        if char in pm:
            pm[char] += 1
        else:
            pm[char] = 1
    for i in range(len(s)):
        leftIdx = i - len(p)
        # add ith elt to map
        if s[i] in sm:
            sm[s[i]] += 1
        else:
            sm[s[i]] = 1
        # remove ith - len(p) + 1th elt from left side
        if i >= len(p):
            sm[s[leftIdx]] -= 1
            if sm[s[leftIdx]] == 0:
                del sm[s[leftIdx]]
        # check anagram
        if i >= len(p) - 1:
            if pm == sm:
                ans.append(leftIdx + 1)
    return ans


res = findAnagrams("cbaebabacd", "abc")
print(res)
