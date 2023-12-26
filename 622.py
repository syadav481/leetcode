class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [None] * k
        self.f_ptr = 0
        self.b_ptr = 0
        self.count = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull(): 
            return False 
        else: 
            self.q[self.b_ptr] = value 
            self.b_ptr = (self.b_ptr + 1) % len(self.q)
            self.count += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty(): 
            return False 
        else: 
            self.f_ptr = (self.f_ptr + 1) % len(self.q)
            self.count -= 1 
        return True

    def Front(self) -> int:
        if self.isEmpty(): 
            return -1 
        return self.q[self.f_ptr]

    def Rear(self) -> int:
        if self.isEmpty(): 
            return -1
        idx = (self.b_ptr + len(self.q) - 1) % len(self.q)
        return self.q[idx]

    def isEmpty(self) -> bool:
        return self.count == 0

    def isFull(self) -> bool:
        return self.count == len(self.q)


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()