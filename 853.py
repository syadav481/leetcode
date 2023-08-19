class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        st = []
        pairs = sorted(list(zip(position, speed)), key=lambda x: x[0])
        print(pairs)
        for i in range(len(pairs) - 1, -1, -1):
            if not st:
                st.append(
                    (pairs[i][0], pairs[i][1], (target - pairs[i][0]) / pairs[i][1])
                )
            else:
                timeTop = st[-1][2]
                timeCurr = (target - pairs[i][0]) / pairs[i][1]
                if timeTop < timeCurr:
                    st.append((pairs[i][0], pairs[i][1], timeCurr))
                else:
                    pass
        return len(st)


print(Solution().carFleet(12, [10, 8, 0, 5, 3], [2, 4, 1, 1, 3]))
