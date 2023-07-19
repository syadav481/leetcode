class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        spliced = ""
        for c1, c2 in zip(word1, word2):
            spliced += c1 + c2
        if len(word1) < len(word2):
            spliced += word2[len(word1) :]
        elif len(word2) < len(word1):
            spliced += word1[len(word2) :]
        return spliced
