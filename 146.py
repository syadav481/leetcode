class Node: 

    def __init__(self, key, val, left, right): 
        self.val = val 
        self.key = key
        self.left = left 
        self.right = right 
    
    def __str__(self): 
        return f'{self.key}<->{self.right}'

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {} 
        self.front = Node(float("inf"), float("inf"), None, None)
        self.back = Node(float("inf"), float("inf"), self.front, None)
        self.front.right = self.back
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache: 
            self.update(self.cache[key]) # update lru
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache: 
            self.update(self.cache[key])
            self.cache[key].val = value
        else: 
            self.cache[key] = self.insert(key, value)
            if len(self.cache) > self.capacity: 
                key_to_del = self.front.right.key
                self.erase(self.front.right)
                del self.cache[key_to_del] 

    def erase(self, node):
        node.left.right, node.right.left = node.right, node.left

    def insert(self, key, value): 
        temp = self.back.left 
        new = Node(key, value, temp, self.back)
        temp.right = new
        self.back.left = new
        return new
    
    def update(self, node): 
        key,val = node.key, node.val
        self.erase(node)
        self.cache[key] = self.insert(key, val)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)