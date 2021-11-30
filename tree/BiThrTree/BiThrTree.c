#include "BiThrTree.h"


//创建树
void BitThrTree_creat_char(pbitree_t *t)
{
    ElemType ch;
    scanf("%c", &ch);

        if(ch == '#') *t = NULL;
        else
        {
            //前序字符串初始化
            *t = (bitree_t *)malloc(sizeof(bitree_t));
            if(!*t) return;
            //memcpy(&(*t)->data, &ch, sizeof(ElemType));
            (*t)->data = ch;
            (*t)->LTag = Link;
            (*t)->RTag = Link;
            BitThrTree_creat_char(&(*t)->lchild);
            BitThrTree_creat_char(&(*t)->rchild);
        }
}

//中序遍历树
void BitThrTree_inorder_treverse(pbitree_t t)
{
    if(!t)
    {
        printf("空指针！\n");
        return;
    }
    while(t)
    {
        //因为是中序线索化，所以遍历打印时，也需要遵循中序遍历原则
        //先找到最左侧节点，从这开始打印
        while(t->LTag == Link)
        {
            t = t->lchild;
        }
        //开始打印
        printf("%c ",t->data);
        //寻找右子节点
        while(t->RTag == Thread && t->rchild != NULL)
        {
            t = t->rchild;
            printf("%c ",t->data);
        }
        //按照中序遍历的规律，寻找右子树最左下的节点；
        t = t->rchild;
    }
}

//中序遍历进行线索化，线索化处理在左右递归中间；
void BitThrTree_inthreading(pbitree_t t)
{
    if(t)
    {
        BitThrTree_inthreading(t->lchild);
        //如果t的左孩子是空，让t的lchild指向pre（上一个节点，即为前驱）
        if(!t->lchild)  //如果t的左孩子是NULL
        {
            t->lchild = pre;
            t->LTag = Thread;
        }
        //考虑第一次进函数时，pre是个空指针；
        //给pre赋值后，则判断pre的右孩子是否为空，如果是空，则pre的后继指向当前的节点t，同时更新RTag
        //此处《大话数据结构》写错了，缺少对pre为空的判断
        if(pre && !pre->rchild)  //如果pre的右节点是NULL，则前驱的右孩子指针指向后继（当前节点t）
        {
            pre->rchild = t;
            pre->RTag = Thread;
        }
        pre = t;
        BitThrTree_inthreading(t->rchild);
    }
}