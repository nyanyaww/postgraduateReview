#include <stdio.h>

//节点node(两个属性，一个是内部值，另一个是保存了下一个节点的地址)
typedef struct Node
{
    int data;          //数据
    struct Node *next; //下一个节点的地址
} Node, *pNode;        //struct Node===Node ; struct Node * === pNode; pNode===Node *

//初始化函数,获取到头结点head
pNode init()
{
    pNode head = malloc(sizeof(Node)); //malloc手动分配内存函数, 字节大小跟Node有关系，跟pNode无关
    head->next = NULL;                 //第二个节点没有，找不到下一个节点
    //防止内存满
    if (head)
    {
        return head;
    }
    return NULL;
}

//插入函数insert,会有一个数据,插入成功返回1
int insert(pNode head, int data)
{
    pNode node = malloc(sizeof(Node)); //分配内存失败，就返回0
    if (!node)
    {
        return 0;
    }
    node->data = data;
    node->next = NULL;
    head->next = node;
    return 1;
}

//remove(index)
//遍历
void traverse(pNode head)
{
    pNode tmp = head->next; //临时节点,保存第一个有数据的几点，首元节点
    while (tmp)
    {
        printf("值=%d\n", tmp->data);
        tmp = tmp->next; //指向下一个节点
    }
}

delete ()
{
    
}

int main()
{
    pNode node1, node2, node3, node4, node5, node6; //定义
    return 0;
}