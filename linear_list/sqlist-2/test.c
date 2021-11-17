#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"


int main()
{
    //重大疑问，所有的函数都传递的形参都是结构体的指针；
    //但是如果，我在main声明了一个结构体指针，传入函数，就会报错误。
    Sqlist LL;
    Sqlist_init(&LL,0);
    printf("l->size = %d\n",LL.size);
    printf("l->length = %d\n",LL.length);
    //printf("LL->data length = %ld\n",sizeof(LL.data));
    //printf("l->data 地址为%ls",l->data);

    for(int i = 0; i < 33; i++)
    {
        Sqlist_push_back(&LL, i);
    }

    int index = 0;
    ElemType target = 15;
    if(Sqlist_locate(&LL,&index, target))
    {
        printf("123\n");
    }else
    {
        printf("在表中无法找到%d\n",target);
    }

    //Sqlist_insert(&LL,13, 100);
    //Sqlist_insert(&LL,0,1000);

    Sqlist_push(&LL,0,1000);
    Sqlist_push(&LL,LL.length -1,1992);
    Sqslist_pop_front(&LL,522);
    Sqlist_print(&LL);
    Sqlist_delete(&LL);
}



