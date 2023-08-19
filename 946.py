class Solution:
    def validateStackSequences(self, pushed: list[int], popped: list[int]) -> bool:
        st = []
        i = 0
        for elt in pushed:
            st.append(elt)
            while i < len(popped) and st and st[-1] == popped[i]:
                st.pop()
                i += 1
        return len(st) == 0


Solution().validateStackSequences([1, 0], [1, 0])
