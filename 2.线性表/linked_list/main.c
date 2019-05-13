#include <stdio.h>
#include <stdlib.h>

#define PRINT_ printf("=====================================\n")

//节点node(两个属性，一个是内部值，另一个是保存了下一个节点的地址)
typedef struct Node
{
    int data;          //数据
    struct Node *next; //下一个节点的地址
    struct Node *pre;  //上一个节点的地址
} Node, *pNode;        //struct Node===Node ; struct Node * === pNode; pNode===Node *

// 初始化函数,获取到头结点head
pNode init()
{
    pNode head = (pNode)malloc(sizeof(Node)); //malloc手动分配内存函数, 字节大小跟Node有关系，跟pNode无关
    head->next = NULL;                        //第二个节点没有，找不到下一个节点
    //防止内存满
    if (head)
    {
        return head;
    }
    return NULL;
}

// 插入函数append,会有一个数据,插入成功返回root地址
pNode append(pNode head, int data)
{
    pNode node = (pNode)malloc(sizeof(Node)); //分配内存失败，就返回0
    if (!node)
    {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->pre = head;
    head->next = node;
    return node;
}

/**
 * 输入：       root的地址
 *             需要删除的索引
 * 输出：       root的地址
 **/
// 在这里似乎不可以使用remove作为函数名
pNode delete (pNode head, int index)
{
    if (index == 0)
    {
        printf("删除第%d个元素\n", index);
        head = head->next;
        return head;
    }
    printf("删除第%d个元素\n", index);
    index -= 1;
    int count = 0;
    // temp是第1个节点的地址
    pNode temp = head->next;
    while (temp)
    {
        if (count == index)
        {
            temp->next = temp->next->next;
            return head;
        }
        temp = temp->next;
        count += 1;
    }
}

/**
 * 输入：       root的地址
 *             index 插入的索引
 *             data  插入的数据
 * 返回：       root的地址
 **/

pNode insert(pNode head, int index, int data)
{
    printf("插入第%d个元素\n", index);
    int count = 0;
    // temp是第1个节点的地址
    pNode temp = head->next;
    while (temp)
    {
        if (count == index)
        {
            pNode tmp = temp;
            temp = append(temp->pre, data);
            temp->next = tmp;
            return head;
        }
        temp = temp->next;
        count += 1;
    }
}
//遍历
void traverse(pNode head)
{
    int count = 0;
    pNode tmp = head->next; //临时节点,保存第一个有数据的几点，首元节点
    printf("链表遍历测试\n");
    while (tmp)
    {
        printf("链表编号 %d 的值 = %d\n", count, tmp->data);
        count += 1;
        tmp = tmp->next; //指向下一个节点
    }
}

int main()
{
    pNode root = init();
    pNode node1, node2, node3, node4, node5, node6;
    node1 = append(root, 1);
    node2 = append(node1, 2);
    node3 = append(node2, 3);
    node4 = append(node3, 4);
    node5 = append(node4, 5);
    node6 = append(node5, 6);
    traverse(root);
    PRINT_;

    root = delete (root, 0);
    traverse(root);
    PRINT_;

    root = insert(root, 3, -32);
    traverse(root);
    PRINT_;

    return 0;
}