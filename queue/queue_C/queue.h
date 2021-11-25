#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int ElemType;

typedef struct QUEUE{
    ElemType *queue;
    unsigned int rear;
    unsigned int front;
    unsigned int max_size;
    unsigned int increment_size;

}Queue, *QueueList;

//循环队列可以解决之前顺序队列，内存空间利用不够得问题
//即当rear == max_size，而front！= 0时可以向0位置继续插入元素
//当然，如果rear==max_size && front =-= 0时，如果还想继续插入元素，则需要扩大max_size;


//初始化队列
void Queue_init(Queue *q, unsigned int size);

//队列长度
unsigned int Queue_length(Queue *q);

//清空队列
void Queue_clear(Queue *q);

//队列插入元素
int Queue_en(Queue *q, ElemType *e);

//队列删除元素
int Queue_de(Queue *q, ElemType *e);

//打印队列
void Queue_print(Queue *q);

//销毁队列
void Queue_destroy(Queue *q);

//队列判断空
int Queue_empty(Queue *q);

#endif