#include "sqlist.h"



void Sqlist_init(Sqlist *l,int length)
{
    int count = 0;
    while(length >> count)
    {
        count++;
    }

    //l->length = length;
    if(length == 0) l->size = 2;
    else{
        l->size = 2 << (count-1);
    }
    
    l->length = length;
    l->data = (ElemType *)malloc(l->size * sizeof(ElemType));

}

//打印表
void Sqlist_print(Sqlist *l)
{
    //printf("LL->length = %d\n",l->length);
    for(int i = 0; i < l->length; i++)
    {
        printf("表中第%d位元素为%d\n",i, l->data[i]);
    }

    printf("LL.size = %d\n",l->size);
    printf("LL.length = %d\n", l->length);
    printf("LL.data = %ld\n",sizeof(l->data));
    printf("sizeof(int) = %ld\n",sizeof(int));
}

//在表的最后插入元素
bool Sqlist_push_back(Sqlist *l, const ElemType e)
{
    
    //如果实际长度大于最大容量，把最大容量*2
    if(l->length >= l->size)
    {
        l->size *=2;
        l->data =(ElemType *)realloc(l->data, l->size * sizeof(ElemType));
    }
    if(memcpy(l->data + l->length, &e, sizeof(ElemType)))
    {
        l->length++;
        return true;
    }
    return false;
}

//求表长度
int Sqlist_length(const Sqlist *l)
{
    return l->length;
}

//判断表是否为空
bool Sqlist_is_empty(const Sqlist *l)
{
    if(l->length) return false;
    return true;
}

//定位元素;i表示元素e在表l中下标
bool Sqlist_locate(const Sqlist *l, int *i, const ElemType e)
{
    for(int j = 0; j < l->length; j++)
    {
        if(e == l->data[j])
        {
            *i = j;
            printf("元素%d在表中第%d位！",e,j);
            return true;
        }
    }
    return false;
}


//表在第i位前插
bool Sqlist_insert(Sqlist *l, int i, const ElemType e)
{
    if((i > l->size) || (i < 0)) 
    {
        printf("前插失败！\n");
    }

    //如果实际长度大于最大容量，把最大容量*2
    if(l->length >= l->size)
    {
        l->size *=2;
        l->data =(ElemType *)realloc(l->data, l->size * sizeof(ElemType));
    }
    ElemType *temp;
    
    memcpy(temp, l->data + i, (l->length - i) * sizeof(ElemType));
    memcpy(l->data + i, &e, sizeof(ElemType));
    memcpy(l->data + i+1, temp,  (l->length - i) * sizeof(ElemType));
    l->length++;
}

//表在第i位后插
bool Sqlist_push(Sqlist *l, int i, const ElemType e)
{
    if((i < 0) || (i > l->size))
    {
        printf("后插函数传递的位置不对：i = %d",i);
    }

    //如果实际长度大于最大容量，把最大容量*2
    if(l->length >= l->size)
    {
        l->size *=2;
        l->data =(ElemType *)realloc(l->data, l->size * sizeof(ElemType));
    }
    ElemType *temp;
    memcpy(temp, l->data + i +1, (l->length - i -1)*sizeof(ElemType));
    memcpy(l->data + i +1, &e, sizeof(ElemType));
    memcpy(l->data + i +2, temp, (l->length - i -1)*sizeof(ElemType));
    l->length++;

}

//在表头插入元素
bool Sqslist_pop_front(Sqlist *l, const ElemType e)
{
    //如果实际长度大于最大容量，把最大容量*2
    if(l->length >= l->size)
    {
        l->size *=2;
        l->data =(ElemType *)realloc(l->data, l->size * sizeof(ElemType));
    }
    ElemType *temp;
    memcpy(temp, l->data, l->length * sizeof(ElemType));
    memcpy(l->data, &e, sizeof(ElemType));
    memcpy(l->data +1, temp, l->length * sizeof(ElemType));
    l->length++;
}

//删除表格
void Sqlist_delete(Sqlist *l)
{
    free(l->data);
    l->length = 0;
    l->size = 0;
}


