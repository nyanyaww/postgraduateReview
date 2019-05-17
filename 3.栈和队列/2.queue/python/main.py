from queue import Queue


class MyQueue(Queue):
    """
    @author:lcs
    @data:2019-5-17
    """

    front = 0
    rear = 0

    def __init__(self, maxsize):
        return super().__init__(maxsize)

    def enQueue(self, data):
        self.put(data)

    def deQueue(self):
        self.get()

    def getFront(self):
        if self.qsize() != 0:
            print(self.queue[0])
        else:
            print('None')

    def getRear():
        print(self.queue[self.qsize() - 1])


if __name__ == "__main__":
    test_queue = MyQueue(maxsize=5)

    test_queue.enQueue(0)
    test_queue.enQueue(1)
    test_queue.enQueue(2)

    test_queue.getFront()
    test_queue.deQueue()

    test_queue.getFront()
    test_queue.deQueue()

    test_queue.getFront()
    test_queue.deQueue()

    test_queue.getFront()
    test_queue.deQueue()
