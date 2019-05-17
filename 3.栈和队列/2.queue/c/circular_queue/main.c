/**
 * @auther: lcs
 * @data: 2019-5-17
 **/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int DataType;
#define LEN 5
#define QUEUE_NULL -65535

typedef struct Queue
{
    DataType data[LEN];
    int front;
    int rear;
} Queue;

void init(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

bool isFull(Queue *queue)
{
    // 此时
    return (queue->rear + 1) % LEN == queue->front ? true : false;
}

bool isEmpty(Queue *queue)
{
    return queue->front == queue->rear ? true : false;
}

// 入队是尾部后移
void enQueue(Queue *queue, DataType data)
{
#if DEBUG
    printf("[DEBUG] enQueue  ->\t");
#endif
    if (!isFull(queue))
    {
        queue->data[queue->rear] = data;
        queue->rear = (queue->rear + 1) % LEN;
#if DEBUG
        printf("Add data %d to the queue\n", data);
#endif
    }
    else
    {
        printf("The queue is full, we can\'t enQueue.\n");
    }
}

// 出队是首部后移
void deQueue(Queue *queue)
{
#if DEBUG
    printf("[DEBUG] deQueue  ->\t");
#endif
    if (!isEmpty(queue))
    {
        queue->front = (queue->front + 1) % LEN;
#if DEBUG
        printf("now front = %d, rear = %d\n", queue->front, queue->rear);
#endif
    }
    else
    {
        printf("The queue is empty, we can\'t deQueue.\n");
    }
}

DataType getFront(Queue *queue)
{
    if (!isEmpty(queue))
        return queue->data[queue->front];
    else
        return QUEUE_NULL;
}

DataType getRear(Queue *queue)
{
    if (!isFull(queue))
        return queue->data[queue->rear - 1];
    else
        return QUEUE_NULL;
}

void printFront(Queue *queue)
{
#if DEBUG
    printf("[DEBUG] getFront ->\t");
#endif
    DataType temp_front = getFront(queue);
    if (temp_front != QUEUE_NULL)
        printf("Front element is %d\n", temp_front);
    else
        printf("The queue is empty, we can\'t get front element.\n");
}

void printRear(Queue *queue)
{
#if DEBUG
    printf("[DEBUG] getRear  ->\t");
#endif
    DataType temp_rear = getRear(queue);
    if (temp_rear != QUEUE_NULL)
        printf("Rear element is %d\n", temp_rear);
    else
        printf("The queue is full, we can\'t get rear element\n");
}

void test(Queue *queue)
{
    printf("front = %d, rear = %d\n", queue->front, queue->rear);
}

int main()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    int i = 0;
    init(queue);
    for (; i < 30; i++)
    {
        enQueue(queue, i + 1);
        if (i >= 1)
            deQueue(queue);
        printFront(queue);
        printRear(queue);
        // test(queue);
    }

    // for (; i > 0; i--)
    // {
    //     deQueue(queue);
    //     printFront(queue);
    //     printRear(queue);
    // }
    return 0;
}