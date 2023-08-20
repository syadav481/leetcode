class FreqStack:
    def __init__(self):
        self.frequencies = {}
        # 2d array
        self.stacks = []

    def push(self, val: int) -> None:
        self.frequencies[val] = self.frequencies.get(val, 0) + 1
        if not self.stacks or len(self.stacks) < self.frequencies[val]:
            self.stacks.append([val])
        else:
            self.stacks[self.frequencies[val] - 1].append(val)

    def pop(self) -> int:
        val = self.stacks[-1].pop()
        if not self.stacks[-1]:
            self.stacks.pop()
        self.frequencies[val] -= 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()

f = FreqStack()

f.push(5)
f.push(7)
f.push(5)
f.push(4)
f.push(5)
f.pop()
f.pop()
f.pop()
f.pop()
