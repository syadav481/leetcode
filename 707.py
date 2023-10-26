class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class MyLinkedList:
    def __init__(self):
        self.head = None

    def get(self, index: int) -> int:
        count = 0
        curr = self.head
        while curr:
            if count == index:
                return curr.val
            curr = curr.next
            count += 1
        return -1

    def addAtHead(self, val: int) -> None:
        new = Node(val)
        new.next = self.head
        self.head = new

    def addAtTail(self, val: int) -> None:
        new = Node(val)
        if not self.head:
            self.head = new
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new

    def addAtIndex(self, index: int, val: int) -> None:
        if index <= 0:
            self.addAtHead(val)
            return
        new = Node(val)
        count = 0
        curr = self.head
        while curr:
            if count == index - 1:
                new.next = curr.next
                curr.next = new
            curr = curr.next
            count += 1
        return

    def deleteAtIndex(self, index: int) -> None:
        if index == 0 and self.head:
            self.head = self.head.next
            return
        curr = self.head
        count = 0
        while curr:
            if count == index - 1 and curr.next:
                curr.next = curr.next.next
            curr = curr.next
            count += 1

    def print(self):
        curr = self.head
        while curr:
            print(f"{curr.val}->", end="")
            curr = curr.next
        print()
        return


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)


def test1():
    lst = MyLinkedList()
    lst.addAtHead(1)
    lst.addAtHead(2)
    lst.addAtHead(3)
    assert lst.get(0) == 3
    assert lst.get(2) == 1
    lst.addAtTail(7)
    assert lst.tail.val == 7
    assert lst.get(lst.size - 1) == 7
    lst.deleteAtIndex(lst.size - 1)
    assert lst.tail.val == 1
    lst.deleteAtIndex(0)
    assert lst.head.val == 2
    assert lst.size == 2
    lst.addAtHead(24)
    lst.deleteAtIndex(1)
    assert lst.size == 2
    lst.addAtIndex(0, 100)
    assert lst.size == 3
    assert lst.head.val == 100
    lst.addAtIndex(lst.size - 1, 300)
    assert lst.tail.val == 300
    lst.print()
    print("test1 done...")


def test2():
    lst = MyLinkedList()
    lst.addAtHead(1)
    lst.addAtTail(3)
    lst.addAtIndex(1, 2)
    assert lst.get(1) == 2
    lst.deleteAtIndex(1)
    assert lst.get(1) == 3
    print("test2 done...")


def test3():
    lst = MyLinkedList()
    lst.addAtHead(7)
    lst.addAtHead(2)
    lst.addAtHead(1)
    lst.addAtIndex(3, 0)
    lst.deleteAtIndex(2)
    lst.addAtHead(6)
    lst.addAtTail(4)
    assert lst.get(4) == 4
    lst.addAtIndex(5, 0)
    lst.addAtHead(6)
    print("test3 done...")


test1()
test2()
test3()
