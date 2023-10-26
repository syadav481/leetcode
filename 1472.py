class BrowserHistory:
    def __init__(self, homepage: str):
        self.bh = [homepage]
        self.current_page = 0

    def visit(self, url: str) -> None:
        # 0 1 2 3 4
        # a b c d e
        # if current_page is 2 and len() is 5, then len() - current_page - 1 = 5 - 2 - 1 = 2
        # we need to pop 2 times
        pop_count = len(self.bh) - self.current_page - 1
        for i in range(pop_count):
            self.bh.pop()
        self.bh.append(url)
        self.current_page = len(self.bh) - 1

    def back(self, steps: int) -> str:
        # 0 1 2 3 4
        # a b c d e
        # if current_page = 2 and we want to move back 5 steps, then we only move back to 0
        # max(current_page - steps, 0)
        self.current_page = max(self.current_page - steps, 0)
        return self.bh[self.current_page]

    def forward(self, steps: int) -> str:
        # 0 1 2 3 4
        # a b c d e
        # if current_page = 2 and we want to move forward 5 steps, we'd be at 7, but thats out of range
        # so we just do min(current_page + steps, len(arr) - 1)
        self.current_page = min(self.current_page + steps, len(self.bh) - 1)
        return self.bh[self.current_page]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
