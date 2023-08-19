class StockSpanner:
    def __init__(self):
        self.vals = []
        self.spans = []

    def next(self, price: int) -> int:
        if not self.vals or self.vals[-1] > price:
            self.vals.append(price)
            self.spans.append(1)
            return 1
        i = len(self.vals) - 1
        span = 1
        while i > -1 and self.vals[i] <= price:
            span += self.spans[i]
            i -= self.spans[i]
        self.spans.append(span)
        self.vals.append(price)
        return span


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)

obj = StockSpanner()
obj.next(100)
obj.next(80)
obj.next(60)
obj.next(70)
obj.next(60)
obj.next(75)
obj.next(85)
print(obj.spans)
print("expected: ")
print([1, 1, 1, 2, 1, 4, 6])
