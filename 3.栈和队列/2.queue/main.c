// 1.init()
// int data[len];//连续内存，用来存放内容，长度为len
// int front = 0;//队头，数组的下标
// int rear = 0;//队尾，数组的下标
// 2.isFull()
// return rear==len?True:False;//rear==front
// 3.push(int a)
// //插入数据，只跟rear相关
// if(!isFull){
// data[rear++] = a;}// data[(rear++)%len] = a;}
// 4.isEmpty()
// return front==rear?True:False;//
// 5.pop()
// //删除数据，只跟front相关
// If(!isEmpty()){
// front++;}
// 6.getFront()
// if(isEmpty())
// 		printf(“队列为空”)
// else
// 		return data[front]
// 7.getRear()
// if(isEmpty())
// 	printf(“队列为空”)
// else
// 	return data[rear-1];

/**
 * @auther: lcs
 * @data: 2019-5-16
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
    return queue->rear == LEN ? true : false;
}

bool isEmpty(Queue *queue)
{
    return queue->front == queue->rear ? true : false;
}

// 入队是尾部后移
void enQueue(Queue *queue, DataType data)
{
    if (!isFull(queue))
    {
        queue->data[queue->rear++] = data;
    }
    else
    {
        printf("The queue is full, we can\'t enQueue.\n");
    }
}

// 出队是首部后移
void deQueue(Queue *queue)
{
    if (!isEmpty(queue))
    {
        queue->front++;
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
    printf("...\n");
}

DataType getRear(Queue *queue)
{
    if (!isFull(queue))
        return queue->data[queue->rear - 1];
    else
        return QUEUE_NULL;
    printf("The queue is full, we can\'t get rear element.\n");
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
    for (; i < 7; i++)
    {
        enQueue(queue, i);
        if(i>=1)
        deQueue(queue);
        // printf("%d\n", getRear(queue));
        printf("%d\n", getFront(queue));
    }
    return 0;
}