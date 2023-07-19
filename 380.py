from random import choice


class RandomizedSet:
    def __init__(self):
        self.v = []
        self.m = {}

    def insert(self, val: int) -> bool:
        if val in self.m:
            return False
        self.v.append(val)
        self.m[val] = len(self.v) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.m:
            return False
        # self.v [ idx of val] = self.v[idx of last element]
        # self.m [last element] = idx of val
        # self.v.pop()
        self.v[self.m[val]] = self.v[len(self.v) - 1]
        self.m[self.v[len(self.v) - 1]] = self.m[val]
        self.v.pop()
        del self.m[val]
        return True

    def getRandom(self) -> int:
        return choice(self.v)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

# ["RandomizedSet","insert","insert","remove","insert","remove","getRandom"]
# [[],[0],[1],[0],[2],[1],[]]

obj = RandomizedSet()
obj.insert(0)
obj.insert(1)
obj.remove(0)
obj.insert(2)
obj.remove(1)
assert obj.getRandom() == 2
