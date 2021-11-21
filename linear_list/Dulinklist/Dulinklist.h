#ifndef DULINKLIST_H
#define DULINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Elemtype;

typedef struct DuNode{
    Elemtype data;
    struct DuNode *prev;
    struct DuNode *next;
}DuNode, *DuNodeList;

//涉及到的双向链表均是带头节点的


//初始化双向链表
DuNodeList Dulinklist_init();

//双向链表的长度
int Dulinklist_length(DuNodeList l);

//双向链表尾部添加元素
int Dulinklist_push_back(DuNodeList l, Elemtype e);

//双向链表头部添加元素
int Dulinklist_pop_front(DuNodeList l, Elemtype e);

//双向链表定位
int Dulinklist_location(DuNodeList l, Elemtype e);

//插入元素操作
bool Dulinklist_insert(DuNodeList l, int i, Elemtype e);

//删除元素
bool Dulinklist_delete_item(DuNodeList l, Elemtype e);

//取元素操作
bool Dulinklist_get_item(DuNodeList l, Elemtype e);

//尾插元素
void Dulinklist_insert_Rear(DuNodeList l, Elemtype a[], int n);

//前插元素
void Dulinklist_insert_Head(DuNodeList l, Elemtype a[], int n);

//打印链表
void Dulinklist_print(DuNodeList l);






#endif




