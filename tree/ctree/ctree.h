#ifndef CTREE_H
#define CTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SON 3
#define MAX_TREE 100

//采用双亲双子表示法
//在定义的数据结构中既存放parent又存放child节点
//这个定义算是链式存储，因为各个节点在内存中的顺序不一定连续
typedef char TElemType;

typedef struct CTREE
{
    TElemType data;
    struct CTREE *parent;
    struct CTREE *son[MAX_SON];
} ctree_t;

//简单树
//树的初始化
void Ctree_init(ctree_t *t);

//创建一个树
//S是广义表形式表示的树，如：(A(B(E(J),F),C(G(K,L)),D(H,I)))
ctree_t *Ctree_creat(TElemType *s);

//访问树的元素
//在树t中寻找元素e，找到返回0，反之返回-1
int Ctree_search(ctree_t *t, TElemType *e);

//遍历打印树
void Ctree_print(ctree_t *t);

//树的深度
int Ctree_deepth(ctree_t *t);

//销毁树
void Ctree_destroy(ctree_t *t);

//判断为空树
int Ctree_empty(ctree_t *t);

//返回树的根
ctree_t *Ctree_root(ctree_t *t);

//在某个节点处插入孩子
int Ctree_insert_node(ctree_t *t, TElemType *e);

//在某个节点处插入树
int Ctree_insert_tree(ctree_t *t, ctree_t *child);

//寻找树中的节点
ctree_t *Ctree_search_node(ctree_t *t, ctree_t *node);

//给某节点赋值
int Ctree_assign(ctree_t *t, ctree_t *e,TElemType value);

#endif
