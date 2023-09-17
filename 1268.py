class Solution:
    def suggestedProducts(self, products: list[str], searchWord: str) -> list[list[str]]:
        products.sort()
        ans = [] 
        for i in range(1, len(searchWord) + 1): 
            prefix = searchWord[:i:]
            suggestion = []
            for string in products: 
                if string.startswith(prefix): 
                    suggestion.append(string)
                if len(suggestion) == 3: 
                    break
            ans.append(suggestion)
        return ans 

Solution().suggestedProducts(["mobile","mouse","moneypot","monitor","mousepad"], "mouse")
