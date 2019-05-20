# 循环队列的readme

我分成了两个版本，一个使用`make debug`，一个使用`make release`。

实例化的测试是有12个测试

* 在i < 3的时候，我们对入队、获取队头及队尾元素做了测试。
* 在i >= 3的时候。也就是Test 3之后我们添加了对于出队的测试。

DEBUG和Release版本不同之处在于，DEBUG清晰得看到了当前使用的是什么函数，而且在出队的时候会打印当前的front和rear的值。

DEBUG版本的程序运行

```shell
gcc -DDEBUG main.c -o main
./main
Test 0:
[DEBUG] enQueue  ->     Add data 1 to the queue
[DEBUG] getFront ->     Front element is 1
[DEBUG] getRear  ->     Rear element is 1
===============================================
Test 1:
[DEBUG] enQueue  ->     Add data 2 to the queue
[DEBUG] getFront ->     Front element is 1
[DEBUG] getRear  ->     Rear element is 2
===============================================
Test 2:
[DEBUG] enQueue  ->     Add data 3 to the queue
[DEBUG] getFront ->     Front element is 1
[DEBUG] getRear  ->     Rear element is 3
===============================================
Test 3:
[DEBUG] enQueue  ->     Add data 4 to the queue
[DEBUG] deQueue  ->     now front = 1, rear = 4
[DEBUG] getFront ->     Front element is 2
[DEBUG] getRear  ->     Rear element is 4
===============================================
Test 4:
[DEBUG] enQueue  ->     Add data 5 to the queue
[DEBUG] deQueue  ->     now front = 2, rear = 0
[DEBUG] getFront ->     Front element is 3
[DEBUG] getRear  ->     Rear element is 5
===============================================
Test 5:
[DEBUG] enQueue  ->     Add data 6 to the queue
[DEBUG] deQueue  ->     now front = 3, rear = 1
[DEBUG] getFront ->     Front element is 4
[DEBUG] getRear  ->     Rear element is 6
===============================================
Test 6:
[DEBUG] enQueue  ->     Add data 7 to the queue
[DEBUG] deQueue  ->     now front = 4, rear = 2
[DEBUG] getFront ->     Front element is 5
[DEBUG] getRear  ->     Rear element is 7
===============================================
Test 7:
[DEBUG] enQueue  ->     Add data 8 to the queue
[DEBUG] deQueue  ->     now front = 0, rear = 3
[DEBUG] getFront ->     Front element is 6
[DEBUG] getRear  ->     Rear element is 8
===============================================
Test 8:
[DEBUG] enQueue  ->     Add data 9 to the queue
[DEBUG] deQueue  ->     now front = 1, rear = 4
[DEBUG] getFront ->     Front element is 7
[DEBUG] getRear  ->     Rear element is 9
===============================================
Test 9:
[DEBUG] enQueue  ->     Add data 10 to the queue
[DEBUG] deQueue  ->     now front = 2, rear = 0
[DEBUG] getFront ->     Front element is 8
[DEBUG] getRear  ->     Rear element is 10
===============================================
Test 10:
[DEBUG] enQueue  ->     Add data 11 to the queue
[DEBUG] deQueue  ->     now front = 3, rear = 1
[DEBUG] getFront ->     Front element is 9
[DEBUG] getRear  ->     Rear element is 11
===============================================
Test 11:
[DEBUG] enQueue  ->     Add data 12 to the queue
[DEBUG] deQueue  ->     now front = 4, rear = 2
[DEBUG] getFront ->     Front element is 10
[DEBUG] getRear  ->     Rear element is 12
===============================================
```

Release版本的运行

```shell
gcc -O3 main.c -o main
./main
Test 0:
Front element is 1
Rear element is 1
===============================================
Test 1:
Front element is 1
Rear element is 2
===============================================
Test 2:
Front element is 1
Rear element is 3
===============================================
Test 3:
Front element is 2
Rear element is 4
===============================================
Test 4:
Front element is 3
Rear element is 5
===============================================
Test 5:
Front element is 4
Rear element is 6
===============================================
Test 6:
Front element is 5
Rear element is 7
===============================================
Test 7:
Front element is 6
Rear element is 8
===============================================
Test 8:
Front element is 7
Rear element is 9
===============================================
Test 9:
Front element is 8
Rear element is 10
===============================================
Test 10:
Front element is 9
Rear element is 11
===============================================
Test 11:
Front element is 10
Rear element is 12
===============================================
```