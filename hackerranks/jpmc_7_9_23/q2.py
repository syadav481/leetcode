# Given word, return the next alphabetically greater string in all permutations of that word.
# if there is no greater permutation, return the string 'no answer' instead.

# Example:
# word = "baca"

# output = "baac"


def rearrangeWord(word):
    n = len(word)
    i = n - 2
    while i >= 0 and word[i] >= word[i + 1]:
        i -= 1

    if i == -1:
        return "no answer"

    j = n - 1
    while j > 1 and word[j] <= word[i]:
        j -= 1

    word = list(word)
    word[i], word[j] = word[j], word[i]
    word[i + 1 :] = reversed(word[i + 1 :])
    return "".join(word)
