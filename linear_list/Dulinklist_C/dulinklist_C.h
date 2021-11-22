#ifndef DULINKLIST_C_H
#define DULINKLIST_C_H
//双向循环链表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Linknode{
    ElemType data;
    struct Linknode *next;
    struct Linknode *prev;
}DuLinkNode;

//初始化一个双向链表
DuLinkNode *Dulinklist_init();

//返回双向链表的长度
int Dulinklist_length(DuLinkNode *l);

//双向链表定位操作
//在l链表中查找第一个值和e相等的节点，若存在返回指向该节点的指针
void *Dulinklist_location(DuLinkNode *l, ElemType *e);

//双向链表尾插元素
void Dulinklist_Rear(DuLinkNode *l, ElemType a[], unsigned int  n);

//双向链表头插元素
void Dulinklist_Head(DuLinkNode *l, ElemType b[], unsigned int n);

//双向链表插入元素
//在第i位之后插入元素e
bool Dulinklist_insert(DuLinkNode *l, int i, ElemType *e);

//双向链表删除元素
//删除第i位的元素，用e保存该元素节点
bool Dulinklist_delete_item(DuLinkNode *l, int i, ElemType *e);

//双向链表取元素
//取出链表的第i个元素节点，用e拿到返回值
bool Dulinklist_get_item(DuLinkNode *l, int i, ElemType *e);

//遍历链表
void Dulinklist_print(DuLinkNode *l);

//销毁链表
void Dulinklist_destroy(DuLinkNode *l);

#endif


