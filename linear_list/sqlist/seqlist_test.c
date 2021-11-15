#include "static_sqlist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Seqlist l;
    //l.data = (ElemType *)malloc(10 * sizeof(ElemType));
    Seqlist_creat(&l, 100);
    for(int i = 0;i<10;i++)
    {
        Seqlist_push_back(&l, i);
    }

    printf("顺序表l中size = %d\n", Seqlist_length(&l));
    printf("顺序表l中length = %d\n", Seqlist_max_size(&l));
    printf("顺序表l中元素为7位置在%d\n",Seqlist_locate(&l,7));
    if(Seqlist_is_empty(&l)) printf("顺序表l为空\n");
    else{
        printf("顺序表l不空\n");
    }

    if(Seqlist_insert(&l, 5, 10))
    {
        printf("顺序表l成功插入\n");
    }
    else{
        printf("顺序表l第%d位前插入失败\n",5);
    }

    if(Seqlist_push(&l, 7, 100))
    {
        printf("顺序表l成功在第%d位插入元素\n",7);
    }
    else
    {
        printf("顺序表插入失败\n");
    }

    ElemType *e = (ElemType *)malloc(sizeof(ElemType));
    if(Seqlist_get_item(&l,8,e))
    {
        printf("顺序表l第%d元素是%d\n",8,*e);
    }

    if(Seqlist_delete(&l, 8, e))
    {
        printf("顺序表l删除第8位元素，%d\n",*e);
    }
    

    Seqlist_print(&l);
}