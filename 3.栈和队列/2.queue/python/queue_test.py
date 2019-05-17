from queue import Queue


if __name__ == "__main__":
    # 基本FIFO队列  先进先出 FIFO即First in First Out,先进先出
    # maxsize设置队列中，数据上限，小于或等于0则不限制，容器中大于这个数则阻塞，直到队列中的数据被消掉
    q = Queue(maxsize=0)

    # 写入队列数据
    q.put(0)
    q.put(1)
    q.put(2)

    # 输出当前队列所有数据
    print(q.queue)
    # 删除队列数据，并返回该数据
    q.get()
    # 输也所有队列数据
    print(q.queue)

    # 输出:
    # deque([0, 1, 2])
    # deque([1, 2])
