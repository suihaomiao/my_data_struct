#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//动态顺序表
typedef int ElemType;
typedef struct{
    unsigned int length;
    unsigned int size;
    ElemType *data;
}Sqlist, *PSqlist;

//创建一个动态顺序表
void Sqlist_init(Sqlist *l, int length);

//求表长度
int Sqlist_length(const Sqlist *l);

//判断表是否为空
bool Sqlist_is_empty(const Sqlist *l);

//定位元素;i表示元素e在表l中下标
bool Sqlist_locate(const Sqlist *l, int *i, const ElemType e);

//表在第i位前插
bool Sqlist_insert(Sqlist *l, int i, const ElemType e);

//表在第i位后插
bool Sqlist_push(Sqlist *l, int i, const ElemType e);

//在表的最后插入元素
bool Sqlist_push_back(Sqlist *l, const ElemType e);

//在表头插入元素
bool Sqslist_pop_front(Sqlist *l, const ElemType e);

//删除表格
void Sqlist_delete(Sqlist *l);

//打印表
void Sqlist_print(Sqlist *l);



#endif