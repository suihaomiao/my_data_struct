#include "SqStack.h"


int main()
{
    SqStack l;
    SqStack_init(&l,4);
    for(int i = 1; i < 11; i++)
    {
        SqStack_push(&l, i);
    }   
    SqStack_print(&l);
    int times = SqStack_length(&l);
    ElemType e;
    for(int j = 0; j < times; j++)
    {
        SqStack_get_top(&l,&e);
        printf("栈顶元素为%d\n",e);
        SqStack_pop(&l,&e);
    }
    if(!SqStack_empty(&l)) printf("此时栈为空！\n");


}