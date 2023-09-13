class TimeMap:
    def __init__(self):
        self.m = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.m:
            self.m[key].append((timestamp, value))
        else:
            self.m[key] = [(timestamp, value)]
        return None

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.m:
            return ""
        nums = self.m[key]
        l, r = 0, len(nums) - 1
        while l < r:
            m = (r - l) // 2 + l
            if nums[m][0] > timestamp:
                r = m
            elif nums[m][0] < timestamp:
                l = m + 1
            else:
                return nums[m][1]
        while l > 0 and nums[l][0] > timestamp:
            l -= 1
        if nums[l][0] > timestamp:
            return ""
        return nums[l][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

t = TimeMap()
# print(t.set("foo", "bar", 1))
# print(t.get("foo", 1))
# print(t.get("foo", 3))
# print(t.set("foo", "bar2", 4))
# print(t.get("foo", 4))
# print(t.get("foo", 5))

print(t.set("love", "high", 10))
print(t.set("love", "low", 20))
print(t.get("love", 5))
print(t.get("love", 10))
print(t.get("love", 15))
print(t.get("love", 20))
print(t.get("love", 25))
