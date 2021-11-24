#include "SqStack.h"

//栈初始化
void SqStack_init(SqStack *l, int size)
{
    if(size == 0) size += 5;
    l->stack_size = size;
    l->increment_size = 5;
    l->stack = (ElemType *)malloc(sizeof(ElemType) * l->stack_size);
    //-1表示空栈
    l->top = -1;

}

//栈长度
int SqStack_length(SqStackList l)
{
    //l->top是指向栈顶的计数器
    return l->top+1;
}

 //进栈
 int SqStack_push(SqStackList l, ElemType e){
     //printf("l.stack_size = %d\n",l->stack_size);
     //如果栈满了，就扩大栈容量
    if(l->top == l->stack_size - 1)
    {
        //printf("l->stack_size = %d\n",l->stack_size);
        l->stack_size += l->increment_size;
        //printf("l->stack_size = %d\n",l->stack_size);
        l->stack = (ElemType *)realloc(l->stack, sizeof(ElemType) * l->stack_size);
        //printf("l->stack_size = %d\n",l->stack_size);
        if(l->stack == NULL)
        {
            printf("重新分配内存失败！\n");
            return -1;
        }
    }
    memcpy(l->stack + l->top +1, &e, sizeof(ElemType));
    ++l->top;
    //printf("栈顶元素为:%d\n",l->stack[l->top]);
    return 0;
 }
 //判断栈是否为空
int SqStack_empty(SqStackList l)
{
    //返回0，表示空栈
    if(l->top < 0)
        return 0;
    //返回其他数字，表示非空栈
    if(l->top >= 0)
        return 1;
}

//遍历输出栈各元素
void SqStack_print(SqStackList l)
{
    printf("开始打印栈,栈最大长度为%d\n",l->stack_size);
    printf("栈数据长度为%d\n",l->top + 1);
    if(!SqStack_empty(l)) return;
    for(int i =0; i < SqStack_length(l); i++)
    {
        printf("栈第%d个元素为%d\n",i, l->stack[i]);
    }
}

//取栈顶的元素
int SqStack_get_top(SqStackList l, ElemType *e)
{
    ElemType *temp = memcpy(e, l->stack + l->top, sizeof(ElemType));
    if(temp == NULL) 
        return -1;

    return 0;
}

//出栈
//e保存出栈的值
int SqStack_pop(SqStackList l, ElemType *e)
{
    if(l->top < 0)
    {
        printf("空栈不能继续出栈！\n");
        return -1;
    }
    memcpy(e, l->stack + l->top, sizeof(ElemType));
    memset(l->stack+l->top, 0,sizeof(ElemType));
    --l->top;
    return 0;
}


//销毁栈
void SqStack_destroy(SqStackList l)
{
    free(l->stack);
}

