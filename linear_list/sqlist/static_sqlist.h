#ifndef STATIC_SQLIST_H
#define STATIC_SQLIST_H


#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct 
{
    ElemType data[MAXSIZE];
    int length;
}Seqlist, *PSeqlist;

//创建表
void Seqlist_creat(Seqlist &l, int max_size = MAXSIZE);

//清空表
void Seqlist_clear(Seqlist &l);

//查询表长度
int Seqlist_length(const Seqlist &l);

//查询表最大长度
int Seqlist_max_size(const Seqlist &l);

//判断表是否为空
bool Seqlist_is_empty(const Seqlist &l);

//定位元素，返回与元素e相等的下标
int Seqlist_locate(const Seqlist &l, ElemType e);

//表前插，即在第i位前，插入元素e
bool Seqlist_insert(Seqlist &l, int i, ElemType e);

//表后插，即在第i位后，插入元素e
bool Seqlist_push(Seqlist &l, int i, ElemType e);

//表尾插，即在表目前最后一位元素插入元素e
bool Seqlist_push_back(Seqlist &l, ElemType e);

//表删除元素，删除指定的第i位元素，并用e拿到该元素的值
bool Seqlist_delete(Seqlist &l, int i, ElemType &e);

//表取元素，即取出第i位的元素
bool Seqlist_get_item(const Seqlist &l, int i, ElemType &e);

//遍历输出表中元素
void Seqlist_print(const Seqlist &l);

//删除表
void Seqlist_delete_all(Seqlist &l);


#endif

