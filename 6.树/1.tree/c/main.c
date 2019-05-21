#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
} BiTNode;

//先序创建二叉树
void CreateBiTree(BiTNode **T)
{
    int ch;
    scanf("%d", &ch);
    if (ch == -1)
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        printf("输入%d的左子节点：", ch);
        CreateBiTree(&((*T)->lChild));
        printf("输入%d的右子节点：", ch);
        CreateBiTree((&(*T)->rChild));
    }

    return;
}

//先序遍历二叉树
void PreOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", T->data);
        PreOrderBiTree(T->lChild);
        PreOrderBiTree(T->rChild);
    }
}

//中序遍历二叉树
void MiddleOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        printf("%d ", T->data);
        MiddleOrderBiTree(T->rChild);
    }
}

//后续遍历二叉树
void PostOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lChild);
        PostOrderBiTree(T->rChild);
        printf("%d ", T->data);
    }
}

//二叉树的深度
int TreeDeep(BiTNode *T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lChild);
        int rightdeep = TreeDeep(T->rChild);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
    }

    return deep;
}

//叶子节点个数
int LeafCount(BiTNode *T)
{
    static int count;
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
        {
            count++;
        }

        LeafCount(T->lChild);
        LeafCount(T->rChild);
    }

    return count;
}

//主函数
int main(int argc, const char *argv[])
{
    BiTNode *T;
    int depth, leafCount = 0;
    printf("请输入第一个节点的值，-1表示没有叶节点：\n");
    CreateBiTree(&T);

    printf("先序遍历二叉树：");
    PreOrderBiTree(T);
    printf("\n");

    printf("中序遍历二叉树：");
    MiddleOrderBiTree(T);
    printf("\n");

    printf("后续遍历二叉树：");
    PostOrderBiTree(T);
    printf("\n");

    depth = TreeDeep(T);
    printf("树的深度为：%d\n", depth);

    leafCount = LeafCount(T);
    printf("叶子节点个数:%d\n", leafCount);

    return 0;
}