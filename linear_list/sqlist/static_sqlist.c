#include <stdio.h>
#include <stdlib.h>
#include "static_sqlist.h"

//创建表
void Seqlist_creat(Seqlist *l, int max_size)
{
    l->data = (ElemType *)malloc(max_size * sizeof(ElemType));
    if (l->data == NULL)
        printf("creat Seqlist erro!");
    //将全部元素初始化为0
    memset(l->data, 0, max_size * sizeof(ElemType));
    l->size = max_size;
    l->length = 0;
}

//清空表
void Seqlist_clear(Seqlist *l)
{
    memset(l->data, 0, sizeof(l->size));
    l->length = 0;
}

int Seqlist_length(const Seqlist *l)
{
    return l->length;
}

int Seqlist_max_size(const Seqlist *l)
{
    return l->size;
}

bool Seqlist_is_empty(const Seqlist *l)
{
    if (l->length == 0)
    {
        return true;
    }
    return false;
}

int Seqlist_locate(const Seqlist *l, ElemType e)
{
    //int index;
    for (int i = 0; i < l->length; i++)
    {
        if (!memcmp(&e, l->data + i, sizeof(ElemType)))
        {
            //memcpy(&e, l->data + i, sizeof(ElemType));
            return i;
        }
    }

    return -1;
}

//表前插，即在第i位前，插入元素e
//i取值范围为[0,length-1]
bool Seqlist_insert(Seqlist *l, int i, ElemType e)
{
    if ((i > l->length - 1) || (i < 0))
    {
        printf("前插的位置大于l的长度！");
        return false;
    }

    if (l->size == l->length)
    {
        printf("表已为最大！");
        return false;
    }

    ElemType temp[l->length - i];
    memcpy(temp, l->data + i, (l->length - i) * sizeof(ElemType));
    l->length++;
    memcpy(l->data + i, &e, sizeof(ElemType));
    memcpy(l->data + i + 1, temp, sizeof(temp));
    return true;
}

//表后插，即在第i位后，插入元素e
bool Seqlist_push(Seqlist *l, int i, ElemType e)
{
    if ((i > l->length - 1) || (i < 0))
    {
        printf("前插的位置大于l的长度！");
        return false;
    }

    if (l->size == l->length)
    {
        printf("表已为最大！");
        return false;
    }

    ElemType temp[l->length - i - 1];
    memcpy(temp, l->data + i + 1, sizeof(temp));
    l->length++;
    memcpy(l->data + i + 1, &e, sizeof(ElemType));
    memcpy(l->data + i + 2, temp, sizeof(temp));
    return true;
}

//表尾插，即在表目前最后一位元素插入元素e
bool Seqlist_push_back(Seqlist *l, ElemType e)
{
    if (l->size == l->length)
    {
        printf("表已为最大！");
        return false;
    }

    memcpy(l->data + l->length, &e, sizeof(ElemType));
    //printf("顺序表中添加元素%d\n",l->data[l->length]);
    l->length++;
    return true;
}

//表删除元素，删除指定的第i位元素，并用e拿到该元素的值
bool Seqlist_delete(Seqlist *l, int i, ElemType *e)
{
    if ((i < 0) || (i > l->length))
    {
        printf("i = %d， 不符合顺序表长度", i);
        return false;
    }

    ElemType temp[l->length - i - 1];
    memcpy(temp, l->data + i + 1, sizeof(temp));
    l->length--;
    memset(l->data + l->length - 1, 0, sizeof(ElemType));
    memcpy(l->data + i, temp, sizeof(temp));

    return true;
}

//表取元素，即取出第i位的元素
bool Seqlist_get_item(const Seqlist *l, int i, ElemType *e)
{
    if ((i < 0) || (i > l->length))
    {
        printf("i = %d， 不符合顺序表长度", i);
        return false;
    }

    memcpy(e, l->data + i, sizeof(ElemType));
    if (e != NULL)
        return true;
    else
    {
        e = NULL;
        return false;
    }
}

//遍历输出表中元素
void Seqlist_print(const Seqlist *l)
{
    for (int i = 0; i < l->length; i++)
    {
        printf("顺序表l中第%d个元素为%d\n", i, l->data[i]);
    }
}

//删除表
void Seqlist_delete_all(Seqlist *l)
{
    free(l->data);
    l = NULL;
}
