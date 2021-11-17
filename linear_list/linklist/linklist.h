#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// typedef struct 
// {
//     char *name;
//     unsigned int age;
// }ElemType;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}LNode, *PLNode;

//初始化一个元素列表
LNode *Linklist_init();

//尾插模式
void Linklist_L_Rear(LNode *l, ElemType a[], int n);

//创建单链表，头插模式
void Linklist_L_Head(LNode *l, ElemType a[], int n);

//返回单链表的长度
int Linklist_length(LNode *l);

//单链表定位，查找链表中第一个值与e相等的节点，如果找得到返回该节点
LNode *Linklist_location(const LNode *l, ElemType *e);

//单链表前插元素操作，在第i位前插入元素e
bool Linklist_insert_my(LNode *l, int i ,ElemType *e);

//单链表定位，查找链表中第一个值与e相等的节点，如果找得到返回该节点在整个链表顺序
int Linklist_locate_pos(const LNode *l, ElemType *e);

//单链表后插元素操作，在第i位后插入元素e
bool Linklist_push(LNode *l, int i, const ElemType *e);

//单链表删除元素操作，删除指定位置的元素
bool Linklist_delete_pos(LNode *l, int i, const ElemType *e);

//单链表删除元素操作，删除能找到的第一个指定元素
bool Linklist_delete_ElemType(LNode *l, const ElemType *e);

//单链表取元素操作，用e保存取到的元素
bool Linklist_get_item(const LNode *l, ElemType *e);

//遍历打印单链表
void Linklist_print(const LNode *l);

//销毁单链表
void Linklist_destroy(LNode *l);

//单链表尾部插入
bool Linklist_push_back(PLNode l, ElemType *e);




#endif