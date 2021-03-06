# 队列简介

队列是一种先进先出的数据结构。

它需要定义存储的对象(data)、队头(front)、队尾(rear)三个属性。

## 数组实现的队列

数组实现的时候需要知道数组长度LEN

### 顺序队列

要点

* `init`的时候`front` = 0, `rear` = 0。
* `enQueue`的时候是先判断队列是否为满，若队列不满那么`rear + 1`。
* `deQueue`的时候是先判断队列是否为空，若队列不空那么`front + 1`。
* `isFull`是判断`rear`是否等于`LEN`，等于`LEN`那么说明队列已经满了，否则说明队列不满。
* `isEmpty`是判断`front`是否等于`rear`，如果等于说明为空，否则队列不空。
* 在获取`front`元素的时候，也需要判断队列是否为空，只有队列不为空的时候才可以取得`front`元素。
* 在获取`rear`元素的时候，也需要判断队列是否为满，只有队列不满的时候才能取得`rear`元素。

### 循环队列

要点

* `init`的时候`front = 0`, `rear = 0`。
* `enQueue`的时候是先判断队列是否为满，若队列不满那么`rear = (rear + 1) % LEN`。
* `deQueue`的时候是先判断队列是否为空，若队列不空那么`front = (front + 1) % LEN`。
* `isFull`是判断`(rear + 1) % LEN`是否等于`front`，等于`front`那么说明队列已经满了，否则说明队列不满。
* `isEmpty`是判断`front`是否等于`rear`，如果等于说明为空，否则队列不空。
* 在获取`front`元素的时候，也需要判断队列是否为空，只有队列不为空的时候才可以取得`front`元素。
* 在获取`rear`元素的时候，也需要判断队列是否为满，只有队列不满的时候才能取得`rear`元素。