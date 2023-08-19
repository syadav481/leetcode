class Solution:
    def simplifyPath(self, path: str) -> str:
        s = []
        path = path.split("/")
        ans = ""
        for string in path:
            if string == "." or string == "":
                continue
            elif string == "..":
                if s:
                    s.pop()
            else:
                s.append(string)
        for string in s:
            ans += "/"
            ans += string
        if not s:
            return "/"
        return ans


Solution().simplifyPath("/../")
