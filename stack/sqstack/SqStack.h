#ifndef SQSTACK_H
#define SQSTACK_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int ElemType;

typedef struct {
    int top;            //栈顶指针，并非真的指针，只是一个计数器
    int stack_size;     //栈最大长度
    int increment_size; //因为是数组是动态的，increment_size表示每次stack_size增长的步长
    ElemType *stack;    //顺序表的变形，存放一维数组
}SqStack,*SqStackList;

//栈初始化
void SqStack_init(SqStack *l, int size);

//栈长度
int SqStack_length(SqStackList l);
 
 //进栈
 int SqStack_push(SqStackList l, ElemType e);

//出栈
//e保存出栈的值
int SqStack_pop(SqStackList l, ElemType *e);

//取栈顶的元素
int SqStack_get_top(SqStackList l, ElemType *e);

//判断栈是否为空
int SqStack_empty(SqStackList l);

//遍历输出栈各元素
void SqStack_print(SqStackList l);

//销毁栈
void SqStack_destroy(SqStackList l);

#endif