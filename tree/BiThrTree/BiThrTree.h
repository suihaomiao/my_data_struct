#ifndef BITHRTREE_H
#define BITHRTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//线索二叉树
//在二叉树的基础上继续完善：
//普通二叉树，n个节点中，存在2n个指针域，但其中能使用的只有n+1个，剩下的n-1个均为空指针；
//线索二叉树则需要使用上这些空指针；
//首先以中序遍历整个树，然后将叶子节点的左右空指针分别指向前驱和后继；
//增加两个域，分别是ltag和rtag；
//当ltag == 0时，lchild指针指向的是左孩子，反之则指向前驱；
//当rtag == 0时，rchild指针指向的是右孩子，反之则指向后继；
typedef enum {
    Link = 0,
    Thread
}PointerTag;

typedef char ElemType;

typedef struct BITHRTREE
{   
    ElemType data;
    struct BITHRTREE *lchild;
    struct BITHRTREE *rchild;
    PointerTag LTag;
    PointerTag RTag;
}bitree_t, *pbitree_t;

//全局变量，始终指向刚刚访问过的节点
pbitree_t pre;


//创建树
void BitThrTree_creat_char(pbitree_t *t);

//中序遍历树
void BitThrTree_inorder_treverse(pbitree_t t);

//中序遍历进行线索化
void BitThrTree_inthreading(pbitree_t t);



#endif